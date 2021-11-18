import _ukkonen_s

_lib = _ukkonen_s.lib


def distance(s1: str, s2: str, k: int) -> int:
    return _lib.edit_distance_k(s1, len(s1), s2, len(s2), k)
