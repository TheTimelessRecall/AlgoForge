#ifndef ARRAY_H
#define ARRAY_H

#include <stdbool.h>

// change here if you want bigger arrays
#define INITIAL_CAPACITY 10

typedef struct {
    int *A;
    int size;    // capacity
    int length;  // number of elements
} Array;

// Initialize dynamic array with initial capacity
bool array_init(Array *arr);

// Free memory allocated by array
void array_free(Array *arr);

// Display elements
void array_display(const Array *arr);

// Append element at the end; returns success/failure
bool array_append(Array *arr, int x);

// Insert element at index; returns success/failure
bool array_insert(Array *arr, int index, int x);

// Delete element at index; returns deleted element or INT_MIN if error
int array_delete(Array *arr, int index);

// Linear search; returns index or -1 if not found
int array_linear_search(const Array *arr, int key);

// Iterative binary search (array must be sorted)
int array_binary_search(const Array *arr, int key);

// Get max element
int array_get_max(const Array *arr);

// Get min element
int array_get_min(const Array *arr);

// Get sum of elements
long long array_sum(const Array *arr);

// Get average
double array_average(const Array *arr);

#endif // ARRAY_H
