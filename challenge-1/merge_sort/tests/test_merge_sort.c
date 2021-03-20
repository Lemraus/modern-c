#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "../merge_sort.h"
#include "test_merge_sort.h"

int main() {
    test_two_arrays_merge();
    test_merge_sorted_recursive();
    return 0;
}

void test_two_arrays_merge() {
    size_t len_a = 3;
    size_t len_b = 4;
    double a[] = { 3, 5, 9 };
    double b[] = { 1, 2, 7, 10 };
    
    double expected[] = { 1, 2, 3, 5, 7, 9, 10 }; 
    double *merged = two_arrays_merge(len_a, len_b, a, b);

    for (size_t i = 0; i < len_a + len_b; ++i) {
        if (merged[i] != expected[i]) {
            printf(
                    "=== FAILED: test_two_arrays_merge ===\n"
                    "\tAt index %zu: expected %f, got %f", 
                    i, expected[i], merged[i]
            );
            free(merged);
            exit(1);
        }
    }

    free(merged);
    printf("=== PASSED: test_two_array_merge ===\n");
}

void test_merge_sorted_recursive() {
    size_t len = 10;
    double ar[] = { 5, 8, 1, 4, 3, 10, 2, 9, 7, 6 };
    
    double expected[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    double *sorted = merge_sorted_recursive(len, ar);

    for (size_t i = 0; i < len; ++i) {
        if (sorted[i] != expected[i]) {
            printf(
                    "=== FAILED: test_merge_sorted_recursive ===\n"
                    "\tAt index %zu: expected %f, got %f", 
                    i, expected[i], sorted[i]        
            );
            free(sorted);
            exit(1);
        }
    }

    free(sorted);
    printf("=== PASSED: test_merge_sorted_recursive ===\n");
}
