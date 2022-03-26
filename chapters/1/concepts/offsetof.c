#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define container_of(p, s, f) (s *)(p - offsetof(s, f))

typedef struct {
  int a;
  int b;
  int *c;
} S;

int main() {
  printf("Offset of 'b' field in the S struct: %lu\n", offsetof(S, b));
  // Now let's use it with our custom 'container_of' macro
  S *item = (S *)malloc(sizeof(S));
  item->a = 1;
  item->b = 2;
  item->c = (int *)malloc(3 * sizeof(int));
  int *ar = item->c;
  S *container = container_of(ar, S, c);
  // Check if the container was succesfully retrieved
  assert(container == item);
  return 0;
}
