#include "derivative.h"
#include <math.h>
#include <stdio.h>

/*
 * This value of epsilon is the most suitable one when manipulating double
 * precision floating point numbers. See
 * https://stackoverflow.com/questions/13430123/what-is-the-optimum-epsilon-dx-value-to-use-within-the-finite-difference-method.
 */
#define EPSILON 2.22E-16

int main() {
  double x = 3;
  printf("x = %f, x² = %f, 2x = %f\n", x, square(x), derivative(square, x));
  return 0;
}

double derivative(double (*f)(double), double x) {
  double dx = sqrt(EPSILON) * x;
  return (f(x + dx) - f(x)) / dx;
}

double square(double x) { return x * x; }
