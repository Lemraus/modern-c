#include <stddef.h>
#include <stdlib.h>

#include "merge_sort.h"

void merge_sort(double ar[], size_t start, size_t end) {
    size_t len = end - start;
    if (len == 1) {
        return;
    }
    
    merge_sort(ar, start, start + len / 2);
    merge_sort(ar, start + len / 2, end);
    merge_adjacent(ar, start, start + len / 2, start + len / 2, end);
}

void merge_adjacent(double ar[], size_t a_start, size_t a_end, size_t b_start, size_t b_end) {
    double merged[b_end - a_start];

    for (size_t i = a_start, j = b_start, k = 0; k < b_end - a_start; ++k) {
        if (i < a_end && (j == b_end || ar[i] < ar[j])) {
            merged[k] = ar[i];
            ++i;
        } else {
            merged[k] = ar[j];
            ++j;
        }
    }

    for (size_t i = 0; i < b_end - a_start; ++i) {
        ar[a_start + i] = merged[i];
    }
}
