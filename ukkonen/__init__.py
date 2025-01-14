from __future__ import annotations

from . import _ukkonen  # type: ignore[attr-defined]

_lib = _ukkonen.lib


def distance(s1: str, s2: str, k: int) -> int:
    return _lib.edit_distance_k(s1, len(s1), s2, len(s2), k)
