from __future__ import annotations

from ukkonen import distance


def test_not_bounded():
    assert distance('hello', 'world', 5) == 4


def test_bounded():
    assert distance('hello', 'world', 2) == 2


def test_exact_match():
    assert distance('hello', 'hello', 2) == 0
