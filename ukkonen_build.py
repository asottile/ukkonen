from __future__ import annotations

from cffi import FFI

CDEF = '''\
int64_t edit_distance_k(
    const wchar_t *a, int64_t asize,
    const wchar_t *b, int64_t bsize,
    int64_t k
);
'''
SRC = '''\
#include "_ukkonen.h"
'''

ffibuilder = FFI()
ffibuilder.cdef(CDEF)
ffibuilder.set_source(
    'ukkonen._ukkonen', SRC,
    sources=['ukkonen/_ukkonen.cpp'],
    include_dirs=['ukkonen'],
)
