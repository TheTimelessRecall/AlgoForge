#include "Array.hpp"
#include <iostream>
#include <climits> 

Array::Array(int capacity) {
    A = new int[capacity];
    size = capacity;
    length = 0;
}

Array::~Array() {
    delete[] A;
}

void Array::resize() {
    int newSize = size * 2;
    int* newArray = new int[newSize];
    for (int i = 0; i < length; ++i)
        newArray[i] = A[i];
    delete[] A;
    A = newArray;
    size = newSize;
}

void Array::display() const {
    std::cout << "Elements: ";
    for (int i = 0; i < length; ++i)
        std::cout << A[i] << " ";
    std::cout << "\n";
}

bool Array::append(int x) {
    if (length == size)
        resize();
    A[length++] = x;
    return true;
}

bool Array::insert(int index, int x) {
    if (index < 0 || index > length)
        return false;
    if (length == size)
        resize();
    for (int i = length; i > index; --i)
        A[i] = A[i - 1];
    A[index] = x;
    ++length;
    return true;
}

int Array::remove(int index) {
    if (index < 0 || index >= length)
        return INT_MIN;
    int deleted = A[index];
    for (int i = index; i < length - 1; ++i)
        A[i] = A[i + 1];
    --length;
    return deleted;
}

int Array::linear_search(int key) const {
    for (int i = 0; i < length; ++i)
        if (A[i] == key)
            return i;
    return -1;
}

int Array::binary_search(int key) const {
    int low = 0, high = length - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (A[mid] == key)
            return mid;
        else if (A[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int Array::get_max() const {
    if (length == 0)
        return INT_MIN;
    int max = A[0];
    for (int i = 1; i < length; ++i)
        if (A[i] > max)
            max = A[i];
    return max;
}

int Array::get_min() const {
    if (length == 0)
        return INT_MAX;
    int min = A[0];
    for (int i = 1; i < length; ++i)
        if (A[i] < min)
            min = A[i];
    return min;
}

long long Array::sum() const {
    long long total = 0;
    for (int i = 0; i < length; ++i)
        total += A[i];
    return total;
}

double Array::average() const {
    return (length == 0) ? 0.0 : (double)sum() / length;
}
