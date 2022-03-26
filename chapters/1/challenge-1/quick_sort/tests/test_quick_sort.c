#include "test_quick_sort.h"
#include "../quick_sort.h"
#include <stddef.h>
#include <stdio.h>

int main() {
  test_partition();
  test_quick_sort();
  return 0;
}

void test_partition() {
  double ar[] = {4, 3, 2, 1};
  double expected[] = {1, 3, 2, 4};

  partition(ar, 0, 3);

  for (size_t i = 0; i < 4; ++i) {
    if (ar[i] != expected[i]) {
      printf("=== FAILED: test_partition ===\n");
      printf("At index %d: expected %f, got %f\n", i, expected[i], ar[i]);
      return;
    }
  }

  printf("=== PASSED: test_partition ===\n");
}

void test_quick_sort() {
  double ar[] = {5, 8, 1, 4, 3, 10, 2, 9, 7, 6};
  double expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  quick_sort(ar, 0, 9);

  for (size_t i = 0; i < 9; ++i) {
    if (ar[i] != expected[i]) {
      printf("=== FAILED: test_quick_sort ===\n");
      printf("At index %d: expected %f, got %f\n", i, expected[i], ar[i]);
      return;
    }
  }

  printf("=== PASSED: test_quick_sort ===\n");
}
