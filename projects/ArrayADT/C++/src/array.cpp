#include "array.hpp"
#include <iostream>
#include <climits>

using namespace std;

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
    int* newA = new int[newSize];
    for (int i = 0; i < length; i++) {
        newA[i] = A[i];
    }
    delete[] A;
    A = newA;
    size = newSize;
}

void Array::display() const {
    cout << "Elements: ";
    for (int i = 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
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
    for (int i = length; i > index; i--) {
        A[i] = A[i - 1];
    }
    A[index] = x;
    length++;
    return true;
}

int Array::remove(int index) {
    if (index < 0 || index >= length)
        return INT_MIN;
    int deleted = A[index];
    for (int i = index; i < length - 1; i++) {
        A[i] = A[i + 1];
    }
    length--;
    return deleted;
}

int Array::linear_search(int key) const {
    for (int i = 0; i < length; i++) {
        if (A[i] == key)
            return i;
    }
    return -1;
}

int Array::binary_search(int key) const {
    int low = 0, high = length - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
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
    if (length == 0) return INT_MIN;
    int maxVal = A[0];
    for (int i = 1; i < length; i++) {
        if (A[i] > maxVal)
            maxVal = A[i];
    }
    return maxVal;
}

int Array::get_min() const {
    if (length == 0) return INT_MAX;
    int minVal = A[0];
    for (int i = 1; i < length; i++) {
        if (A[i] < minVal)
            minVal = A[i];
    }
    return minVal;
}

long long Array::sum() const {
    long long s = 0;
    for (int i = 0; i < length; i++)
        s += A[i];
    return s;
}

double Array::average() const {
    if (length == 0) return 0.0;
    return (double)sum() / length;
}
