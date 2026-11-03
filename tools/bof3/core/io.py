"""Repository paths and atomic I/O helpers."""

from __future__ import annotations

import json
import os
import tempfile
import unicodedata
from dataclasses import dataclass
from pathlib import Path, PurePosixPath
from typing import Any, TypeGuard

from bof3.core.paths import BUILD, INPUTS, TOOLCHAINS


# Repo-relative top-level directories.


@dataclass(frozen=True)
class RepoLayout:
    """One resolved path per repository top-level directory."""

    root: Path
    build_dir: Path
    toolchains_dir: Path
    inputs_dir: Path
    downloads_dir: Path
    private_assets_dir: Path
    psn00b_toolchain_root: Path
    gcc272_psx_root: Path


def repo_layout(root: Path | None = None) -> RepoLayout:
    """Return the repository layout derived from ``root``."""
    resolved = (root or Path(__file__).resolve().parents[3]).resolve()
    build = resolved / BUILD
    toolchains = resolved / TOOLCHAINS
    inputs = resolved / INPUTS
    return RepoLayout(
        root=resolved,
        build_dir=build,
        toolchains_dir=toolchains,
        inputs_dir=inputs,
        downloads_dir=toolchains / "downloads",
        private_assets_dir=inputs / "external" / "private-assets",
        psn00b_toolchain_root=toolchains / "psn00b_toolchain",
        gcc272_psx_root=toolchains / "gcc-2.7.2-psx",
    )


def read_json(path: Path) -> dict[str, Any]:
    """Return the JSON object stored at ``path``."""
    payload = json.loads(path.read_text(encoding="utf-8"))
    if not isinstance(payload, dict):
        raise ValueError(f"expected a JSON object in {path}")
    return payload


def is_safe_relative_path(value: object) -> TypeGuard[str]:
    """Return whether ``value`` is a plain, lexically safe relative path."""
    if not isinstance(value, str) or not value or "\\" in value:
        return False
    path = PurePosixPath(value)
    if (
        path.is_absolute()
        or not path.parts
        or path.as_posix() != value
        or ".." in path.parts
    ):
        return False
    return not any(
        character == "\x00"
        or unicodedata.category(character) in {"Cc", "Zl", "Zp"}
        or 0xD800 <= ord(character) <= 0xDFFF
        for character in value
    )


def write_atomic(path: Path, data: str | bytes) -> None:
    """Write ``data`` to ``path`` atomically via a same-directory temp file."""
    if isinstance(data, str):
        data = data.encode("utf-8")
    path.parent.mkdir(parents=True, exist_ok=True)
    descriptor, temporary_name = tempfile.mkstemp(
        dir=path.parent, prefix=f".{path.name}.", suffix=".tmp"
    )
    temporary = Path(temporary_name)
    try:
        with os.fdopen(descriptor, "wb") as stream:
            stream.write(data)
        temporary.replace(path)
    except BaseException:
        temporary.unlink(missing_ok=True)
        raise


def write_json(
    path: Path, payload: dict[str, Any], *, sort_keys: bool = True, indent: int = 2
) -> None:
    """Write ``payload`` to ``path`` as an indented JSON document."""
    write_atomic(path, json.dumps(payload, indent=indent, sort_keys=sort_keys) + "\n")
