[![build status](https://github.com/asottile/ukkonen/actions/workflows/main.yml/badge.svg)](https://github.com/asottile/ukkonen/actions/workflows/main.yml)
[![pre-commit.ci status](https://results.pre-commit.ci/badge/github/asottile/ukkonen/main.svg)](https://results.pre-commit.ci/latest/github/asottile/ukkonen/main)

ukkonen
=======

Implementation of bounded Levenshtein distance (Ukkonen)

### port

this is a port of [ukkonen] from javascript to c++ / python via cffi.

[ukkonen]: https://github.com/sunesimonsen/ukkonen

### installation

```bash
pip install ukkonen
```

- wheels should be available on pypi in most cases

### api

#### `distance(s1: str, s2: str, k: int) -> int`

compute the edit distance, bounded by `k`

```pycon
>>> import ukkonen
>>> ukkonen.distance('hello', 'world', 5)
4
>>> ukkonen.distance('hello', 'world', 2)
2
```
