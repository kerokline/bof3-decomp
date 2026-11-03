"""Load every target in one deterministic pass: one ``splat.yaml`` each."""

from __future__ import annotations

from pathlib import Path

from bof3.core.paths import CONFIG
from bof3.resolve.ids import source_folder
from bof3.resolve.manifests import (
    TargetManifest,
    _splat_paths,
    _validate_companions,
    _validate_copies,
    load_target_manifest,
)

_MANIFESTS_CACHE: dict[str, tuple[int, dict[str, TargetManifest]]] = {}


def source_dir(root: Path, target: str) -> Path:
    """Return the folder that holds a target's sources, as its layout names it."""
    manifest = load_target_manifests(root).get(target)
    if manifest is not None:
        return Path(root) / manifest.source_dir
    return Path(root) / "src" / source_folder(target)


def _stamp(directory: Path) -> int | None:
    try:
        return directory.stat().st_mtime_ns
    except OSError:
        return None


def load_target_manifests(root: Path) -> dict[str, TargetManifest]:
    """Load and validate every target under ``config/``, keyed by target id."""
    root = Path(root)
    directory = root / CONFIG
    if not directory.is_dir():
        return {}
    key = str(root.resolve())
    stamp = _stamp(directory)
    cached = _MANIFESTS_CACHE.get(key)
    if cached is not None and cached[0] == stamp:
        return dict(cached[1])

    parsed: dict[str, TargetManifest] = {}
    for path in _splat_paths(directory):
        target = path.parent.relative_to(directory).as_posix()
        manifest = load_target_manifest(
            path.parent / "target.toml", root=root, target=target
        )
        if manifest.id.value != target:
            raise ValueError(
                f"target ID {manifest.id.value!r} does not match path {target!r}"
            )
        if manifest.id.value in parsed:
            raise ValueError(f"duplicate target: {manifest.id.value}")
        parsed[manifest.id.value] = manifest
    _validate_companions(parsed)
    _validate_copies(parsed)
    if stamp is not None:
        _MANIFESTS_CACHE[key] = (stamp, dict(parsed))
    return parsed
