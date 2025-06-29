#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "../include/array.h"

void test_array_init_and_free() {
    Array arr;
    assert(array_init(&arr) == true);
    assert(arr.length == 0);
    assert(arr.size == INITIAL_CAPACITY);
    array_free(&arr);
    assert(arr.A == NULL);
    assert(arr.length == 0);
    assert(arr.size == 0);
}

void test_array_append_and_display() {
    Array arr;
    array_init(&arr);
    for (int i = 1; i <= 15; i++) {  // test resizing as well
        assert(array_append(&arr, i) == true);
    }
    assert(arr.length == 15);
    assert(arr.size >= 15); // capacity should have grown

    // Check content manually
    for (int i = 0; i < arr.length; i++) {
        assert(arr.A[i] == i + 1);
    }
    array_free(&arr);
}

void test_array_insert() {
    Array arr;
    array_init(&arr);

    // Insert at beginning (empty)
    assert(array_insert(&arr, 0, 10) == true);
    assert(arr.length == 1);
    assert(arr.A[0] == 10);

    // Insert at end
    assert(array_insert(&arr, 1, 20) == true);
    assert(arr.length == 2);
    assert(arr.A[1] == 20);

    // Insert in middle
    assert(array_insert(&arr, 1, 15) == true);
    assert(arr.length == 3);
    assert(arr.A[1] == 15);

    // Insert invalid index
    assert(array_insert(&arr, -1, 5) == false);
    assert(array_insert(&arr, 5, 5) == false);

    array_free(&arr);
}

void test_array_delete() {
    Array arr;
    array_init(&arr);
    for (int i = 0; i < 5; i++) {
        array_append(&arr, i * 10);
    }
    assert(arr.length == 5);

    // Delete middle element
    int deleted = array_delete(&arr, 2);
    assert(deleted == 20);
    assert(arr.length == 4);
    assert(arr.A[2] == 30);

    // Delete invalid index
    deleted = array_delete(&arr, 10);
    assert(deleted == INT_MIN);

    array_free(&arr);
}

void test_searches() {
    Array arr;
    array_init(&arr);
    int vals[] = {1, 3, 5, 7, 9};
    for (int i = 0; i < 5; i++)
        array_append(&arr, vals[i]);

    // Linear search
    assert(array_linear_search(&arr, 5) == 2);
    assert(array_linear_search(&arr, 2) == -1);

    // Binary search
    assert(array_binary_search(&arr, 7) == 3);
    assert(array_binary_search(&arr, 4) == -1);

    array_free(&arr);
}

void test_max_min_sum_average() {
    Array arr;
    array_init(&arr);
    int vals[] = {5, 10, 15, 20};
    for (int i = 0; i < 4; i++)
        array_append(&arr, vals[i]);

    assert(array_get_max(&arr) == 20);
    assert(array_get_min(&arr) == 5);
    assert(array_sum(&arr) == 50);
    assert(array_average(&arr) - 12.5 < 1e-9);

    array_free(&arr);
}

int main() {

    test_array_init_and_free();
    test_array_append_and_display();
    test_array_insert();
    test_array_delete();
    test_searches();
    test_max_min_sum_average();

    printf("All tests passed!\n");
    return 0;
}
