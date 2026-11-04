"""template_try finds a definition through the include walk and builds a replacement body."""

from __future__ import annotations

from pathlib import Path

import pytest

import template_try
import try_body
from bof3.source.index import Func

DEF = "int Lifted(int a)\n{\n    return a + 1;\n}\n"


@pytest.fixture
def root(tmp_path: Path, monkeypatch: pytest.MonkeyPatch) -> Path:
    monkeypatch.setattr(template_try, "ROOT", tmp_path)
    monkeypatch.setattr(try_body, "ROOT", tmp_path)
    return tmp_path


def write(root: Path, name: str, text: str) -> None:
    path = root / name
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text, encoding="utf-8")


def test_locate_finds_a_definition_in_the_file(root: Path) -> None:
    write(root, "src/a/a.c", "void x(void);\n" + DEF)
    src, start, end = template_try.locate("src/a/a.c", "Lifted") or ("", 0, 0)
    assert src == "src/a/a.c"
    assert (root / src).read_text(encoding="utf-8")[start:end].startswith("int Lifted")


def test_locate_follows_a_quoted_include_next_to_the_file(root: Path) -> None:
    write(root, "src/a/a.c", '#include "body.h"\n')
    write(root, "src/a/body.h", DEF)
    found = template_try.locate("src/a/a.c", "Lifted")
    assert found is not None and found[0] == "src/a/body.h"


def test_locate_falls_back_to_the_shared_folder(root: Path) -> None:
    write(root, "src/a/a.c", '#include "Body.h"\n')
    write(root, "src/shared/Body.h", DEF)
    found = template_try.locate("src/a/a.c", "Lifted")
    assert found is not None and found[0] == "src/shared/Body.h"


def test_locate_ignores_headers_outside_src(root: Path) -> None:
    write(root, "src/a/a.c", '#include "sdk.h"\n')
    write(root, "include/sdk.h", DEF)
    assert template_try.locate("src/a/a.c", "Lifted") is None


def test_locate_stops_on_an_include_cycle_and_at_depth_zero(root: Path) -> None:
    write(root, "src/a/a.c", '#include "b.h"\n')
    write(root, "src/a/b.h", '#include "a.c"\n')
    assert template_try.locate("src/a/a.c", "Lifted") is None
    write(root, "src/a/c.c", '#include "d.h"\n')
    write(root, "src/a/d.h", DEF)
    assert template_try.locate("src/a/c.c", "Lifted", depth=0) is None


def func(name: str, status: str, src: str | None) -> Func:
    return Func("exe/a", name, 0x100, 8, (0, 0), name, status, src)


def test_attempt_dry_run_renames_the_template_body(root: Path) -> None:
    write(root, "src/a/a.c", DEF)
    write(root, "src/a/b.c", "INCLUDE_ASM(func_8001);\n")
    funcs = [func("Lifted", "C", "src/a/a.c"), func("func_8001", "ASM", "src/a/b.c")]
    line = template_try.attempt(funcs, "exe/a@func_8001\texe/a@Lifted", dry=True)
    assert line.startswith("DRY exe/a@func_8001 <- exe/a@Lifted\n")
    assert "int func_8001(int a)" in line
    assert "Lifted" not in line.split("\n", 1)[1]
    assert (root / "src/a/b.c").read_text(
        encoding="utf-8"
    ) == "INCLUDE_ASM(func_8001);\n"


def test_attempt_keeps_an_exact_body_and_restores_a_failed_one(
    root: Path, monkeypatch: pytest.MonkeyPatch
) -> None:
    write(root, "src/a/a.c", DEF)
    write(root, "src/a/b.c", "INCLUDE_ASM(func_8001);\n")
    funcs = [func("Lifted", "C", "src/a/a.c"), func("func_8001", "ASM", "src/a/b.c")]
    row = "exe/a@func_8001\texe/a@Lifted"
    monkeypatch.setattr(try_body, "match", lambda ref, root: (True, ""))
    assert template_try.attempt(funcs, row, dry=False).startswith("EXACT ")
    assert "int func_8001" in (root / "src/a/b.c").read_text(encoding="utf-8")
    write(root, "src/a/b.c", "INCLUDE_ASM(func_8001);\n")
    monkeypatch.setattr(try_body, "match", lambda ref, root: (False, "diff at 0x4"))
    assert (
        template_try.attempt(funcs, row, dry=False)
        == f"FAIL {row.replace(chr(9), ' <- ')}: 0 differ, diff at 0x4"
    )
    assert (root / "src/a/b.c").read_text(
        encoding="utf-8"
    ) == "INCLUDE_ASM(func_8001);\n"


@pytest.mark.parametrize(
    ("target", "template", "text", "reason"),
    [
        (
            ("func_8001", "C", "src/a/b.c"),
            ("Lifted", "C", "src/a/a.c"),
            "",
            "is not an INCLUDE_ASM function",
        ),
        (
            ("func_8001", "ASM", "src/a/b.c"),
            ("Lifted", "ASM", "src/a/a.c"),
            "INCLUDE_ASM(func_8001);",
            "is not lifted C",
        ),
        (
            ("func_8001", "ASM", "src/a/b.c"),
            ("Lifted", "C", "src/a/a.c"),
            "int func_8001(void) { return 0; }",
            "already has a body",
        ),
        (
            ("func_8001", "ASM", "src/a/b.c"),
            ("Other", "C", "src/a/a.c"),
            "INCLUDE_ASM(func_8001);",
            "no definition of Other",
        ),
    ],
)
def test_attempt_skips_a_row_it_cannot_use(
    root: Path, target, template, text, reason
) -> None:
    write(root, "src/a/a.c", DEF)
    write(root, "src/a/b.c", text)
    funcs = [func(*target), func(*template)]
    line = template_try.attempt(
        funcs, f"exe/a@{target[0]}\texe/a@{template[0]}", dry=True
    )
    assert line.startswith("SKIP ")
    assert reason in line
