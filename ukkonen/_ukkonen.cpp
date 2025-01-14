#include <algorithm>
#include <cstdint>
#include <vector>

template <typename T> int64_t edit_distance_k_impl(
    const T* a, int64_t a_size,
    const T* b, int64_t b_size,
    int64_t k
) {
    if (a_size > b_size) {
        std::swap(a, b);
        std::swap(a_size, b_size);
    }

    // suffix trimming
    while (a_size > 0 && a[a_size - 1] == b[b_size - 1]) {
        a_size--;
        b_size--;
    }

    // prefix trimming
    while (a_size > 0 && *a == *b) {
        a++;
        b++;
        a_size--;
        b_size--;
    }


    k = std::min(b_size, k);

    // if the shorter string is gone, return b_size or threshold
    if (a_size == 0) {
        return k;
    }

    auto size_d = b_size - a_size;

    if (size_d > k) {
        return k;
    }

    int64_t ZERO_K = std::min(k, a_size) / 2 + 2;
    auto array_size = size_d + ZERO_K * 2 + 2;

    std::vector<int64_t> current_row(array_size, -1);
    std::vector<int64_t> next_row(array_size, -1);

    int64_t i = 0;
    int64_t condition_row = size_d + ZERO_K;
    int64_t end_max = condition_row * 2;

    do {
        i++;

        std::swap(current_row, next_row);

        int64_t start;
        int64_t previous_cell;
        int64_t current_cell = -1;
        int64_t next_cell;

        if (i <= ZERO_K) {
            start = -i + 1;
            next_cell = i - 2;
        } else {
            start = i - ZERO_K * 2 + 1;
            next_cell = current_row[ZERO_K + start];
        }

        int64_t end;
        if (i <= condition_row) {
            end = i;
            next_row[ZERO_K + i] = -1;
        } else {
            end = end_max - i;
        }

        for (int64_t q = start, row_index = start + ZERO_K; q < end; q++, row_index++) {
            previous_cell = current_cell;
            current_cell = next_cell;
            next_cell = current_row[row_index + 1];

            int64_t t = std::max(
                std::max(current_cell + 1, previous_cell),
                next_cell + 1
            );

            while (t < a_size && t + q < b_size && a[t] == b[t + q]) {
                t++;
            }

            next_row[row_index] = t;
        }
    } while (next_row[condition_row] < a_size && i <= k);

    return i - 1;
}

extern "C" int64_t edit_distance_k(
    const wchar_t *a, int64_t asize,
    const wchar_t *b, int64_t bsize,
    int64_t k
) {
    return edit_distance_k_impl(a, asize, b, bsize, k);
}
