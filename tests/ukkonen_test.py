from ukkonen import distance


def test_not_bounded():
    assert distance('hello', 'world', 5) == 4


def test_bounded():
    assert distance('hello', 'world', 2) == 2
