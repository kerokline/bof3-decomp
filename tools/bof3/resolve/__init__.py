"""Target discovery and identity resolution."""

from __future__ import annotations

from typing import TYPE_CHECKING, Any

if TYPE_CHECKING:
    from bof3.resolve.ids import normalize_target_id as normalize_target_id
    from bof3.resolve.manifests import TargetManifest as TargetManifest
    from bof3.resolve.registry import load_target_manifests as load_target_manifests

__all__ = [
    "TargetManifest",
    "load_target_manifests",
    "normalize_target_id",
]


def __getattr__(name: str) -> Any:
    """Load target resolution modules only for callers that use them."""
    if name == "normalize_target_id":
        from bof3.resolve.ids import normalize_target_id

        return normalize_target_id
    if name == "TargetManifest":
        from bof3.resolve.manifests import TargetManifest

        return TargetManifest
    if name == "load_target_manifests":
        from bof3.resolve.registry import load_target_manifests

        return load_target_manifests
    raise AttributeError(f"module {__name__!r} has no attribute {name!r}")
