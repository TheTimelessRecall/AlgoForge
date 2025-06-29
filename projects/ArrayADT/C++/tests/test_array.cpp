#include <iostream>
#include <cassert>
#include <climits>
#include "array.hpp"

using namespace std;

void test_append_and_display() {
    Array arr;

    assert(arr.append(10));
    assert(arr.append(20));
    assert(arr.append(30));

    cout << "After append: ";

    arr.display();  
    assert(arr.sum() == 60);
    assert(arr.get_max() == 30);
    assert(arr.get_min() == 10);
}

void test_insert() {
    Array arr;

    arr.append(10);
    arr.append(30);
    assert(arr.insert(1, 20));  
    assert(arr.linear_search(20) == 1);

    cout << "After insert: ";
    arr.display();  // Expect: 10 20 30
}

void test_delete() {
    Array arr;

    arr.append(10);
    arr.append(20);
    arr.append(30);

    int deleted = arr.remove(1);  

    assert(deleted == 20);
    assert(arr.linear_search(20) == -1);

    cout << "After delete: ";
    arr.display();  // Expect: 10 30
}

void test_search() {
    Array arr;

    arr.append(10);
    arr.append(20);
    arr.append(30);
    assert(arr.linear_search(20) == 1);
    assert(arr.linear_search(100) == -1);

    // Binary search requires sorted array
    assert(arr.binary_search(20) == 1);
    assert(arr.binary_search(100) == -1);
}

void test_edge_cases() {
    Array arr;

    assert(arr.remove(0) == INT_MIN); 
    assert(!arr.insert(-1, 5));      
    assert(!arr.insert(1, 5));       
}

int main() {
    test_append_and_display();
    test_insert();
    test_delete();
    test_search();
    test_edge_cases();

    cout << "All tests passed!\n";
    return 0;
}
