#ifndef MERGE_SORT
#define MERGE_SORT
double* merge_sorted_recursive(size_t len, double ar[len]);
double* array_slice(double ar[], size_t i_start, size_t i_end);
double* two_arrays_merge(size_t len_a, size_t len_b, double a[len_a], double b[len_b]);
#endif // MERGE_SORT
