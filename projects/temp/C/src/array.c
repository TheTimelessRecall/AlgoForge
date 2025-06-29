#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

bool array_init(Array *arr) {
    arr->A = (int*) malloc(sizeof(int) * INITIAL_CAPACITY);
    if (!arr->A) return false;
    arr->size = INITIAL_CAPACITY;
    arr->length = 0;
    return true;
}

void array_free(Array *arr) {
    if (arr->A) {
        free(arr->A);
        arr->A = NULL;
    }
    arr->length = 0;
    arr->size = 0;
}

void array_display(const Array *arr) {
    printf("Elements: ");
    for (int i = 0; i < arr->length; i++) {
        printf("%d ", arr->A[i]);
    }
    printf("\n");
}

bool array_append(Array *arr, int x) {
    if (arr->length == arr->size) {
        int *temp = (int*) realloc(arr->A, sizeof(int) * arr->size * 2);
        if (!temp) return false; // realloc failed
        arr->A = temp;
        arr->size *= 2;
    }
    arr->A[arr->length++] = x;
    return true;
}

bool array_insert(Array *arr, int index, int x) {
    if (index < 0 || index > arr->length) return false;
    if (arr->length == arr->size) {
        int *temp = (int*) realloc(arr->A, sizeof(int) * arr->size * 2);
        if (!temp) return false;
        arr->A = temp;
        arr->size *= 2;
    }
    for (int i = arr->length; i > index; i--) {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[index] = x;
    arr->length++;
    return true;
}

int array_delete(Array *arr, int index) {
    if (index < 0 || index >= arr->length) return INT_MIN; // error value
    int deleted = arr->A[index];
    for (int i = index; i < arr->length -1; i++) {
        arr->A[i] = arr->A[i + 1];
    }
    arr->length--;
    return deleted;
}

int array_linear_search(const Array *arr, int key) {
    for (int i = 0; i < arr->length; i++) {
        if (arr->A[i] == key) return i;
    }
    return -1;
}

int array_binary_search(const Array *arr, int key) {
    int low = 0, high = arr->length - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr->A[mid] == key) return mid;
        else if (arr->A[mid] > key) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int array_get_max(const Array *arr) {
    if (arr->length == 0) return INT_MIN;
    int max = arr->A[0];
    for (int i = 1; i < arr->length; i++) {
        if (arr->A[i] > max) max = arr->A[i];
    }
    return max;
}

int array_get_min(const Array *arr) {
    if (arr->length == 0) return INT_MAX;
    int min = arr->A[0];
    for (int i = 1; i < arr->length; i++) {
        if (arr->A[i] < min) min = arr->A[i];
    }
    return min;
}

long long array_sum(const Array *arr) {
    long long s = 0;
    for (int i = 0; i < arr->length; i++) {
        s += arr->A[i];
    }
    return s;
}

double array_average(const Array *arr) {
    if (arr->length == 0) return 0.0;
    return (double)array_sum(arr) / arr->length;
}
