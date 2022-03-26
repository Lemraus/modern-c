#include "quick_sort.h"
#include <stddef.h>

void quick_sort(double ar[], size_t start, size_t end) {
  if (end <= start)
    return;

  size_t pivot_pos = partition(ar, start, end);
  quick_sort(ar, start, pivot_pos - 1);
  quick_sort(ar, pivot_pos + 1, end);
}

size_t partition(double ar[], size_t start, size_t end) {
  size_t k = start;
  double pivot_val = ar[end];

  for (size_t i = start; i < end; ++i) {
    if (ar[i] < pivot_val) {
      double val = ar[i];
      ar[i] = ar[k];
      ar[k++] = val;
    }
  }

  ar[end] = ar[k];
  ar[k] = pivot_val;

  return k;
}
