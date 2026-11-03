#!/usr/bin/env python3
"""Extract the retail payloads for the build; ``tools/setup.sh`` runs this last.

Finds the US disc image under ``inputs/external``, extracts it into ``build/disc``,
unpacks every EMI archive, writes the catalog and materializes each target's payload.
Prints what is missing and what to do when the media is absent.
"""

from __future__ import annotations

import argparse
import hashlib
import os
import re
import shutil
import subprocess
import sys
from pathlib import Path

from bof3.core.io import write_json
from bof3.core.paths import BUILD
from bof3.emi.catalog import load_catalog, materialize_reviewed_targets
from bof3.resolve import load_target_manifests

ROOT = Path(__file__).resolve().parents[1]
MEDIA = ROOT / "inputs/external"
#: The Redump US disc: SHA-1 of track 1 and track 2.
TRACK_SHA1 = (
    "5745d9dde965ed0ec673ba071deb762355fa3e1a",
    "d9f92af296360772e62caa4cb276de3fa74f5538",
)
MISSING = f"""setup: retail media is missing. The build reads your own copy of the US disc.
setup: dump your own disc and put the two-track CUE/BIN set (Redump, 'Breath of Fire III (USA)') in {MEDIA}/,
setup: then run tools/setup.sh again.
setup: until then the disc-free checks work: meson setup build/meson && meson compile -C build/meson check-tree include-asm"""


def disc_set() -> tuple[Path, list[Path]] | None:
    """Return the cue sheet and bins of the shallowest complete disc set."""
    found = []
    for cue in sorted(MEDIA.rglob("*.cue")):
        text = cue.read_text(encoding="utf-8", errors="ignore")
        bins = [
            (cue.parent / name).resolve()
            for name in re.findall(r'^\s*FILE\s+"([^"]+)"', text, re.I | re.M)
        ]
        if bins and all(path.is_file() for path in bins):
            found.append((len(cue.relative_to(MEDIA).parts), cue, bins))
    return min(found, key=lambda item: item[:2])[1:] if found else None


def find_media() -> tuple[Path, list[Path]]:
    """Locate the disc set."""
    found = disc_set()
    if found is None:
        sys.exit(MISSING)
    return found


def check_tracks(bins: list[Path]) -> None:
    """Refuse a disc dump that is not the pinned US release."""
    if len(bins) != len(TRACK_SHA1):
        sys.exit(f"setup: expected a two-track disc, the cue names {len(bins)} file(s)")
    for number, (path, wanted) in enumerate(zip(bins, TRACK_SHA1), 1):
        digest = hashlib.sha1()
        with path.open("rb") as stream:
            for chunk in iter(lambda: stream.read(1 << 20), b""):
                digest.update(chunk)
        if digest.hexdigest() != wanted:
            sys.exit(
                f"setup: {path.name} (track {number}) is not the US disc dump "
                f"(SHA-1 {digest.hexdigest()}, expected {wanted})"
            )


def extractor() -> str:
    """Build the pinned ``bof3`` CLI, or use the one named by ``BOF3_CLI``."""
    override = os.environ.get("BOF3_CLI")
    if override:
        found = shutil.which(override)
        if found is None:
            sys.exit(f"setup: BOF3_CLI is not executable: {override}")
        return found
    manifest = ROOT / "tools/bof3-tools/Cargo.toml"
    if not manifest.is_file():
        sys.exit(
            "setup: tools/bof3-tools is empty; run: git submodule update --init tools/bof3-tools"
        )
    target = (ROOT / (os.environ.get("CARGO_TARGET_DIR") or "build/rust")).resolve()
    subprocess.run(
        ["cargo", "build", "--locked", "--release", "--no-default-features",
         "--bin", "bof3", "--manifest-path", str(manifest), "--target-dir", str(target)],
        check=True,
    )  # fmt: skip
    return str(target / "release/bof3")


def main(argv: list[str] | None = None) -> int:
    """Extract and materialize the payloads unless they are current."""
    argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter
    ).parse_args(argv)
    manifests = load_target_manifests(ROOT)
    disc = ROOT / BUILD / "disc"
    catalog_path = ROOT / BUILD / "catalog/emi.json"
    if catalog_path.is_file() and all(
        (ROOT / manifest.binary).is_file() for manifest in manifests.values()
    ):
        print("payloads: current")
        return 0
    cue, bins = find_media()
    check_tracks(bins)
    cli = extractor()
    subprocess.run(
        [cli, "disc", "extract", "-i", str(cue), "-o", str(disc)], check=True
    )
    for archive in sorted(disc.rglob("*.EMI")):
        out = disc / archive.relative_to(disc).with_suffix("")
        out.parent.mkdir(parents=True, exist_ok=True)
        subprocess.run(
            [cli, "emi", "extract", "--quiet", "-J", "-o", str(out), str(archive)],
            check=True,
        )
    catalog = load_catalog(ROOT)
    write_json(catalog_path, catalog)
    materialize_reviewed_targets(root=ROOT, catalog=catalog)
    for manifest in manifests.values():
        if manifest.kind == "executable" and not (ROOT / manifest.binary).is_file():
            (ROOT / manifest.binary).parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(disc / manifest.disc_id, ROOT / manifest.binary)
    # Fresh payloads are split inputs; drop the caches.
    shutil.rmtree(ROOT / BUILD / ".cache", ignore_errors=True)
    print(f"payloads: {len(manifests)} targets")
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except subprocess.CalledProcessError as error:
        command = " ".join(str(part) for part in error.cmd[:3])
        sys.exit(
            f"setup: '{command} ...' failed with status {error.returncode}; see the output above"
        )
