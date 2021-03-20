#include <stddef.h>
#include <stdlib.h>

#include "merge_sort.h"

double* merge_sorted_recursive(size_t len, double ar[len]) {
    if (len == 1) {
        return ar;
    }

    size_t left_size = len / 2;
    size_t right_size = len - len / 2;
    double *left = array_slice(ar, 0, len / 2); 
    double *right = array_slice(ar, len / 2, len);
    
    double *left_sorted = merge_sorted_recursive(left_size, left);
    free(left);
    double *right_sorted = merge_sorted_recursive(right_size, right);
    free(right);

    double *sorted = two_arrays_merge(left_size, right_size, left_sorted, right_sorted);
    free(left_sorted);
    free(right_sorted);
    
    return sorted;
}

double* array_slice(double ar[], size_t i_start, size_t i_end) {
    double *slice = malloc((i_end - i_start) * sizeof(*slice));

    for (int i = 0; i < i_end - i_start; ++i) {
        slice[i] = ar[i_start + i];
    }

    return slice;
}

double* two_arrays_merge(size_t len_a, size_t len_b, double a[len_a], double b[len_b]) {
    double *merged = malloc((len_a + len_b) * sizeof(*merged));

    for (size_t i = 0, j = 0, k = 0; k < len_a + len_b; ++k) {
        if (i < len_a && (j == len_b || a[i] < b[j])) {
            merged[k] = a[i];
            ++i;
        } else {
            merged[k] = b[j];
            ++j;
        }
    }

    return merged;
}
