"""m2ctx builds the preprocessor input for a header or a C source."""

from __future__ import annotations

from pathlib import Path

import m2ctx


def test_a_header_is_included_by_absolute_path(tmp_path: Path) -> None:
    header = tmp_path / "x.h"
    header.write_text("int x;\n", encoding="utf-8")
    assert m2ctx.stub(header) == f'#include "{header.resolve()}"\n'


def test_a_source_becomes_a_stub_of_its_quoted_includes(tmp_path: Path) -> None:
    source = tmp_path / "x.c"
    source.write_text(
        '#include "a.h"\n#include <sys.h>\n  #  include "b/c.h"\nint f(void) { return 0; }\n',
        encoding="utf-8",
    )
    assert m2ctx.stub(source) == '#include "a.h"\n#include "b/c.h"\n'


def test_a_source_without_includes_gets_the_common_header(tmp_path: Path) -> None:
    source = tmp_path / "x.c"
    source.write_text("int f(void);\n", encoding="utf-8")
    assert m2ctx.stub(source) == '#include "common.h"\n'


def test_a_source_with_bad_bytes_still_reads(tmp_path: Path) -> None:
    source = tmp_path / "x.c"
    source.write_bytes(b'#include "a.h"\n\xff\xfe\n')
    assert m2ctx.stub(source) == '#include "a.h"\n'


def test_preprocess_drops_pragma_and_line_markers(tmp_path: Path) -> None:
    compiler = tmp_path / "cc"
    compiler.write_text(
        "#!/bin/sh\nprintf '#pragma once\\nint a;\\n  #line 4\\nint b;\\n'\n",
        encoding="utf-8",
    )
    compiler.chmod(0o755)
    source = tmp_path / "x.c"
    source.write_text("int f(void);\n", encoding="utf-8")
    assert m2ctx.preprocess(source, str(compiler)) == "int a;\nint b;\n"


def test_preprocess_reports_a_compiler_failure(tmp_path: Path) -> None:
    compiler = tmp_path / "cc"
    compiler.write_text("#!/bin/sh\necho boom >&2\nexit 1\n", encoding="utf-8")
    compiler.chmod(0o755)
    source = tmp_path / "x.c"
    source.write_text("", encoding="utf-8")
    try:
        m2ctx.preprocess(source, str(compiler))
    except SystemExit as stop:
        assert "failed: boom" in str(stop)
    else:
        raise AssertionError("expected SystemExit")
