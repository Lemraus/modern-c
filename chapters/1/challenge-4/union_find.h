#ifndef UNION_FIND
#define UNION_FIND

#include <stddef.h>

/**
 * @brief Initializes an Union-Find index table with the given size.
 * The returned table is dynamically allocated and therefore needs to be freed.
 *
 * @param size
 * @return size_t*
 */
size_t *init_table(size_t size);

/**
 * @brief Pretty-print the Union-Find index table.
 * Example: { 0 1 2 3 }
 *
 * @param table
 * @param size
 */
void print_table(size_t *table, size_t size);

/**
 * @brief In the given Union-Find index table, find the root for the specified
 * index.
 *
 * @param table
 * @param index
 * @return size_t
 */
size_t find(size_t *table, size_t index);

/**
 * @brief In the given Union-Find index table, replace all values from the
 * specified index to its root by the provided value.
 *
 * @param table
 * @param index
 * @param value
 */
void find_replace(size_t *table, size_t index, size_t value);

/**
 * @brief In the given Union-Find index table, replaces all values from the
 * specified index to its root by the value of its root.
 *
 * @param table
 * @param index
 * @return size_t
 */
size_t find_compress(size_t *table, size_t index);

/**
 * @brief Performs the union between two members of the provided Union-Find
 * index table.
 *
 * @param table
 * @param a
 * @param b
 * @return size_t
 */
size_t perform_union(size_t *table, size_t a, size_t b);

#endif