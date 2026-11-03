"""Declarations, definitions and calls of the C tree, and the problems they show.

``Tree`` reads every tracked C file once: each prototype and definition with its types, each
call, and which file includes which. ``problems`` compares them and returns one row per
disagreement: a prototype that differs from its definition, a call that no declaration
covers, a cast that a missing prototype forced.
"""

from __future__ import annotations

import collections
import os
import re
from dataclasses import dataclass, field

from .ctext import split_args

_KEYWORDS = frozenset(
    "if while for switch return sizeof else do case goto defined typeof __attribute__".split()
)
_TYPES = frozenset("void s8 s16 s32 u8 u16 u32 int char short long unsigned".split())
_QUALIFIERS = frozenset(("struct", "union", "enum", "unsigned", "signed", "const"))
_MARKERS = re.compile(
    r"\b(static|extern|inline|INLINE|STATIC|MATCH|NON_MATCHING|FAKE_MATCH|MATCH_FAKE)\b"
)
_HEAD = re.compile(
    r"(?:^|(?<=[;}]))\s*((?:[\w\s\*]+?)[\s\*])(\w+)\s*"
    r"\(([^;{}()]*(?:\([^()]*\)[^;{}()]*)*)\)\s*([;{])"
)
_PLACEHOLDER = re.compile(r"^arg\d+$")
_CALL_CAST = re.compile(
    r"\(\s*\(\s*([^()]*?)\(\s*\*\s*\)\s*\(([^()]*)\)\s*\)\s*(\w+)\s*\)"
)
_RETURN_CAST = re.compile(r"\(\s*((?:struct\s+|union\s+)?\w+\s*\*+)\s*\)\s*(\w+)\s*\(")
_INCLUDE = re.compile(r'^\s*#\s*include\s*[<"]([^>"]+)[>"]', re.M)


@dataclass(frozen=True, slots=True)
class Decl:
    """A prototype (``kind == "proto"``) or a definition (``"def"``)."""

    kind: str
    file: str
    line: int
    ret: str
    params: tuple[tuple[str, str], ...]  # (type, name)
    unspecified: bool  # written with empty parentheses


@dataclass(frozen=True, slots=True)
class Call:
    """A call inside a function body."""

    name: str
    file: str
    line: int
    argc: int
    before: str  # the text just before the name


@dataclass(frozen=True, slots=True)
class Problem:
    """One disagreement between declarations, or between a call and its declaration."""

    kind: str
    name: str
    file: str
    line: int
    detail: str


def strip_comments(text: str) -> str:
    """Blank comments, ``extern "C"`` wrappers and preprocessor lines; keep line numbers."""
    text = re.sub(
        r"/\*.*?\*/", lambda m: re.sub(r"[^\n]", "", m.group()), text, flags=re.S
    )
    text = re.sub(r"//[^\n]*", "", text)
    if re.search(r'extern\s+"C"\s*\{', text):
        text = re.sub(r'extern\s+"C"\s*\{', "", text)
        end = text.rfind("\n}")
        if end >= 0:
            text = text[:end] + text[end + 2 :]
    out, continued = [], False
    for line in text.split("\n"):
        if continued or line.lstrip().startswith("#"):
            continued = line.rstrip().endswith("\\")
            out.append("")
        else:
            out.append(line)
    return "\n".join(out)


def normalize(text: str) -> str:
    """Collapse spaces around ``*`` and between words."""
    return re.sub(r"\s+", " ", re.sub(r"\s*\*\s*", "*", text)).strip()


def split_param(param: str) -> tuple[str, str]:
    """Split one parameter into ``(type, name)``; the name is empty when absent."""
    if param == "...":
        return ("...", "")
    pointer = re.match(r"^(.*)\(\s*\*\s*(\w+)\s*\)(.*)$", param, re.S)
    match = re.match(r"^(.*?)(\w+)((?:\[[^\]]*\])*)$", param, re.S)
    if not match or not match.group(1).strip() or match.group(1).strip() in _QUALIFIERS:
        return (normalize(param), "")
    if pointer:
        return (
            normalize(pointer.group(1) + "(*)" + pointer.group(3)),
            pointer.group(2),
        )
    return (normalize(match.group(1) + match.group(3)), match.group(2))


def _top_level(text: str) -> tuple[str, list[tuple[int, int]]]:
    """Return ``text`` with every top-level body emptied (lines kept) and the body spans."""
    spans, depth, start = [], 0, 0
    for i, ch in enumerate(text):
        if ch == "{":
            if depth == 0:
                start = i
            depth += 1
        elif ch == "}":
            depth -= 1
            if depth == 0:
                spans.append((start, i))
    parts, pos = [], 0
    for a, b in spans:
        parts.append(text[pos : a + 1])
        parts.append(re.sub(r"[^\n]", "", text[a + 1 : b]))
        pos = b
    parts.append(text[pos:])
    return "".join(parts), spans


@dataclass
class Tree:
    """The declarations and calls of a set of C files, keyed by repo-relative path."""

    texts: dict[str, str]
    decls: dict[str, list[Decl]] = field(
        default_factory=lambda: collections.defaultdict(list)
    )
    calls: list[Call] = field(default_factory=list)
    stripped: dict[str, str] = field(default_factory=dict)
    includes: dict[str, list[str]] = field(default_factory=dict)
    macros: set[str] = field(default_factory=set)
    variables: set[str] = field(default_factory=set)

    def __post_init__(self) -> None:
        for name in sorted(self.texts):
            self._read(name)
        self._includes()

    def _includes(self) -> None:
        known = set(self.texts)
        for name, text in self.texts.items():
            found = []
            for m in _INCLUDE.finditer(text):
                for base in (os.path.dirname(name), "src", "include", "include/psyq"):
                    candidate = os.path.normpath(os.path.join(base, m.group(1)))
                    if candidate in known:
                        found.append(candidate)
                        break
            self.includes[name] = found

    def _read(self, name: str) -> None:
        text = strip_comments(self.texts[name])
        self.stripped[name] = text
        top, spans = _top_level(text)
        for m in _HEAD.finditer(top):
            ret, fname, params, end = m.groups()
            ret = ret.strip()
            if fname in _KEYWORDS or "=" in ret or ret.split()[-1:] == ["return"]:
                continue
            if re.search(r"\btypedef\b", ret):
                continue
            line = top.count("\n", 0, m.start(2)) + 1
            self.decls[fname].append(
                Decl(
                    "def" if end == "{" else "proto",
                    name,
                    line,
                    normalize(_MARKERS.sub("", ret)),
                    tuple(split_param(p) for p in split_args(params)),
                    params.strip() == "",
                )
            )
        for a, b in spans:
            body = text[a : b + 1]
            for m in re.finditer(r"(?<![\w.>])(\w+)\s*\(", body):
                callee = m.group(1)
                if callee in _KEYWORDS or callee in _TYPES:
                    continue
                depth, k = 1, m.end()
                while k < len(body) and depth:
                    depth += (body[k] == "(") - (body[k] == ")")
                    k += 1
                self.calls.append(
                    Call(
                        callee,
                        name,
                        text.count("\n", 0, a + m.start()) + 1,
                        len(split_args(body[m.end() : k - 1])),
                        body[max(0, m.start() - 12) : m.start()],
                    )
                )
        for m in re.finditer(r"^\s*#\s*define\s+(\w+)", self.texts[name], re.M):
            self.macros.add(m.group(1))
        for m in re.finditer(r"\(\s*\*\s*(\w+)\s*\)", text):
            self.variables.add(m.group(1))
        for m in re.finditer(r"[\s\*](\w+)\s*(?:=|\[)", text):
            self.variables.add(m.group(1))

    def kind(self, name: str, kind: str) -> list[Decl]:
        """Return the ``kind`` declarations of ``name``."""
        return [d for d in self.decls.get(name, ()) if d.kind == kind]

    def closure(self, name: str) -> set[str]:
        """Return ``name`` and every file it includes, directly or not."""
        seen, stack = {name}, [name]
        while stack:
            for inc in self.includes.get(stack.pop(), ()):
                if inc not in seen:
                    seen.add(inc)
                    stack.append(inc)
        return seen


def _compare(d: Decl, p: Decl) -> str | None:
    """Return why a prototype disagrees with a definition, or None."""
    if d.ret != p.ret:
        return f"ret {d.ret} vs {p.ret}"
    if p.unspecified and not d.unspecified:
        return f"unspecified vs {len(d.params)} args"
    if d.unspecified and p.unspecified:
        return None
    if len(d.params) != len(p.params):
        return f"argc {len(d.params)} vs {len(p.params)}"
    for i, (a, b) in enumerate(zip(d.params, p.params, strict=True)):
        if a[0] != b[0]:
            return f"arg{i} {a[0]} vs {b[0]}"
    return None


def cross_image(tree: Tree) -> list[tuple[str, Decl, Decl, str]]:
    """Return every prototype that disagrees with a definition in another file.

    Visibility is ignored: the same name in two images is compared as one function.
    """
    rows = []
    for name in sorted(tree.decls):
        for proto in tree.kind(name, "proto"):
            for definition in tree.kind(name, "def"):
                if definition.file != proto.file:
                    why = _compare(definition, proto)
                    if why:
                        rows.append((name, proto, definition, why))
    return rows


def problems(tree: Tree) -> list[Problem]:
    """Compare every definition with the prototypes it sees, and every call with its callee."""
    rows: list[Problem] = []

    def add(kind: str, name: str, file: str, line: int, detail: str) -> None:
        rows.append(Problem(kind, name, file, line, detail))

    visible = {name: tree.closure(name) for name in tree.texts}
    defs = {n: tree.kind(n, "def") for n in tree.decls}
    protos = {n: tree.kind(n, "proto") for n in tree.decls}
    for name, definitions in defs.items():
        for d in definitions:
            for p in (q for q in protos[name] if q.file in visible[d.file]):
                _prototype_rows(add, name, d, p)
    callers: dict[str, list[Call]] = collections.defaultdict(list)
    for call in tree.calls:
        callers[call.name].append(call)
    for call in tree.calls:
        _call_rows(add, tree, call, visible, defs, protos)
    for file, text in tree.stripped.items():
        for m in _CALL_CAST.finditer(text):
            if m.group(3) in tree.decls:
                detail = f"{normalize(m.group(1))}({normalize(m.group(2))})"
                add(
                    "call_through_cast",
                    m.group(3),
                    file,
                    text.count("\n", 0, m.start()) + 1,
                    detail,
                )
        for m in _RETURN_CAST.finditer(text):
            if m.group(2) in tree.decls and m.group(2) not in tree.macros:
                add(
                    "return_cast",
                    m.group(2),
                    file,
                    text.count("\n", 0, m.start()) + 1,
                    normalize(m.group(1)),
                )
    for name, definitions in defs.items():
        for d in definitions:
            if d.ret == "void":
                for call in callers.get(name, ()):
                    if re.search(r"=\s*$|return\s*$", call.before):
                        add("void_result_read", name, call.file, call.line, "")
            if d.ret in ("s32", "void*"):
                casts = [r for r in rows if r.kind == "return_cast" and r.name == name]
                kinds = {r.detail for r in casts}
                if len(kinds) == 1 and len(casts) == len(callers.get(name, ())):
                    add(
                        "wide_ret_all_callers_cast",
                        name,
                        d.file,
                        d.line,
                        f"{d.ret} -> {kinds.pop()}",
                    )
    return sorted(rows, key=lambda r: (r.kind, r.name, r.file, r.line, r.detail))


def _prototype_rows(add, name: str, d: Decl, p: Decl) -> None:
    if d.ret != p.ret:
        add(
            "ret_mismatch",
            name,
            p.file,
            p.line,
            f"def {d.ret} ({d.file}) vs proto {p.ret}",
        )
    if p.unspecified and not d.unspecified:
        add(
            "proto_unspecified_args",
            name,
            p.file,
            p.line,
            f"def {len(d.params)} args ({d.file})",
        )
        return
    if len(d.params) != len(p.params):
        add(
            "argc_mismatch",
            name,
            p.file,
            p.line,
            f"def {len(d.params)} ({d.file}) vs proto {len(p.params)}",
        )
        return
    for i, (a, b) in enumerate(zip(d.params, p.params, strict=True)):
        if a[0] != b[0]:
            add(
                "argtype_mismatch",
                name,
                p.file,
                p.line,
                f"arg{i} def {a[0]} vs proto {b[0]}",
            )
        elif a[1] != b[1]:
            if a[1] and _PLACEHOLDER.match(b[1]):
                add(
                    "proto_placeholder_name",
                    name,
                    p.file,
                    p.line,
                    f"arg{i} proto {b[1]} def {a[1]}",
                )
            elif a[1] and not _PLACEHOLDER.match(a[1]):
                add(
                    "param_name_differs",
                    name,
                    p.file,
                    p.line,
                    f"arg{i} def {a[1]} proto {b[1] or '-'}",
                )
        if _PLACEHOLDER.match(a[1]) and b[1] and not _PLACEHOLDER.match(b[1]):
            add(
                "def_placeholder_name",
                name,
                d.file,
                d.line,
                f"arg{i} def {a[1]} proto {b[1]}",
            )


def _call_rows(add, tree: Tree, call: Call, visible, defs, protos) -> None:
    name = call.name
    if name in tree.macros or name in tree.variables:
        return
    if name in tree.decls:
        seen = [
            q
            for q in tree.decls[name]
            if q.file in visible[call.file] or q.file == call.file
        ]
        if not seen:
            add("implicit_decl", name, call.file, call.line, "no proto or def in scope")
            return
        scope = [q for q in protos[name] if q.file in visible[call.file]] or [
            q for q in defs[name] if q.file == call.file
        ]
        for p in scope[:1]:
            variadic = any(a[0] == "..." for a in p.params)
            if not p.unspecified and not variadic and len(p.params) != call.argc:
                add(
                    "call_argc",
                    name,
                    call.file,
                    call.line,
                    f"call {call.argc} proto {len(p.params)}",
                )
    elif name != "INCLUDE_ASM" and not name.isupper() and name not in _TYPES:
        add("implicit_decl", name, call.file, call.line, "no declaration anywhere")


def declares(text: str, name: str) -> bool:
    """Return True when ``text`` holds a prototype statement of ``name``."""
    clean = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
    pattern = (
        r"^(?:extern\s+)?[A-Za-z_][\w \t\*]*?[ \t\*]"
        + re.escape(name)
        + r"\s*\([^;{}]*\)\s*;"
    )
    return re.search(pattern, clean, re.M) is not None


def implicit_coverage(
    tree: Tree, rows: list[Problem]
) -> list[tuple[str, str, int, int, int]]:
    """Classify each ``implicit_decl`` row by translation unit.

    Returns ``(name, file, line, units, uncovered)``: how many ``.c`` files include ``file``,
    and how many of them see no prototype of the callee. ``uncovered == 0`` with ``units > 0``
    means every unit that compiles the call already has a declaration through another path.
    """
    roots = [f for f in tree.texts if f.endswith(".c")]
    roots_of: dict[str, list[str]] = collections.defaultdict(list)
    closures = {r: tree.closure(r) for r in roots}
    for r in roots:
        for g in closures[r]:
            roots_of[g].append(r)
    names = {r.name for r in rows if r.kind == "implicit_decl"}
    holders = {
        n: [f for f, text in tree.texts.items() if n in text and declares(text, n)]
        for n in names
    }
    out = []
    for r in rows:
        if r.kind != "implicit_decl":
            continue
        units = roots_of.get(r.file, [])
        bad = [u for u in units if not any(h in closures[u] for h in holders[r.name])]
        out.append((r.name, r.file, r.line, len(units), len(bad)))
    return out
