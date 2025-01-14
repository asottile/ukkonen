#ifndef ___UKKONEN__H__
#define ___UKKONEN__H__

#include <stdint.h>
#include <wchar.h>

#ifdef __cplusplus
extern "C" {
#endif

int64_t edit_distance_k(const wchar_t *a, int64_t asize, const wchar_t *b, int64_t bsize, int64_t k);

#ifdef __cplusplus
}
#endif

#endif
