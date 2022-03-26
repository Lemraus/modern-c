#include "union_find.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  size_t size = 4;
  size_t *table = init_table(size);

  // Perform operations on the table
  printf("Initial table:\n");
  print_table(table, size);
  perform_union(table, 0, 1);
  printf("After union(0, 1):\n");
  print_table(table, size);
  find_replace(table, 2, 1);
  printf("After find_replace(2, 1):\n");
  print_table(table, size);
  find_compress(table, 2);
  printf("After find_compress(2):\n");
  print_table(table, size);
  perform_union(table, 1, 3);
  printf("After union(1, 3):\n");
  print_table(table, size);

  free(table);
  return 0;
}

size_t *init_table(size_t size) {
  size_t *table = (size_t *)malloc(size * sizeof(size_t));
  for (int i = 0; i < size; ++i) {
    table[i] = i;
  }
  return table;
}

void print_table(size_t *table, size_t size) {
  printf("{ ");
  for (size_t i = 0; i < size; ++i) {
    printf("%lu ", table[i]);
  }
  printf("}\n");
}

size_t find(size_t *table, size_t index) {
  size_t cur_index = index;
  while (cur_index != table[cur_index]) {
    cur_index = table[cur_index];
  }
  return cur_index;
}

void find_replace(size_t *table, size_t index, size_t value) {
  size_t parent, cur_index = index;
  for (;;) {
    parent = table[cur_index];
    table[cur_index] = value;
    if (cur_index == parent) {
      break;
    }
    cur_index = parent;
  }
}

size_t find_compress(size_t *table, size_t index) {
  size_t root = find(table, index);
  find_replace(table, index, root);
  return root;
}

size_t perform_union(size_t *table, size_t a, size_t b) {
  size_t root = find_compress(table, a);
  find_replace(table, b, root);
  return root;
}