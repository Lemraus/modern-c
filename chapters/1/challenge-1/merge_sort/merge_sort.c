#include "merge_sort.h"
#include <stdlib.h>

void merge_sort(double ar[], size_t start, size_t end) {
  size_t len = end - start;
  if (len == 1)
    return;

  merge_sort(ar, start, start + len / 2);
  merge_sort(ar, start + len / 2, end);
  merge_adjacent(ar, start, start + len / 2, end);
}

void merge_adjacent(double ar[], size_t start, size_t middle, size_t end) {
  double merged[end - start];

  for (size_t i = start, j = middle, k = 0; k < end - start; ++k) {
    if (i < middle && (j == end || ar[i] < ar[j])) {
      merged[k] = ar[i];
      ++i;
    } else {
      merged[k] = ar[j];
      ++j;
    }
  }

  for (size_t i = 0; i < end - start; ++i) {
    ar[start + i] = merged[i];
  }
}
