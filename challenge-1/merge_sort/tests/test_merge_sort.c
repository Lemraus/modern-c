#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "../merge_sort.h"
#include "test_merge_sort.h"

int main() {
    test_merge_adjacent();
    test_merge_sort();
    return 0;
}

void test_merge_adjacent() {
    size_t len = 7;
    double ar[] = { 3, 5, 9, 1, 2, 7, 10 };
    double expected[] = { 1, 2, 3, 5, 7, 9, 10 }; 
    merge_adjacent(ar, 0, 3, 3, len);

    for (size_t i = 0; i < len; ++i) {
        if (ar[i] != expected[i]) {
            printf(
                    "=== FAILED: test_merge_adjacent ===\n"
                    "\tAt index %zu: expected %f, got %f", 
                    i, expected[i], ar[i]
            );
            exit(1);
        }
    }

    printf("=== PASSED: test_merge_adjacent ===\n");
}

void test_merge_sort() {
    size_t len = 10;
    double ar[] = { 5, 8, 1, 4, 3, 10, 2, 9, 7, 6 };
    double expected[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    merge_sort(ar, 0, len);

    for (size_t i = 0; i < len; ++i) {
        if (ar[i] != expected[i]) {
            printf(
                    "=== FAILED: test_merge_sort ===\n"
                    "\tAt index %zu: expected %f, got %f", 
                    i, expected[i], ar[i]        
            );
            exit(1);
        }
    }

    printf("=== PASSED: test_merge_sort ===\n");
}
