#include <stdalign.h>
#include <stdio.h>

typedef struct {
  float f;
  short s;
  char c;
} well_aligned;

typedef struct {
  short s;
  float f;
  char c;
} badly_aligned;

int main() {
  printf("Well aligned: %lu\nBadly aligned: %lu\n", alignof(well_aligned),
         alignof(badly_aligned));
  return 0;
}
