#ifndef ARRAY_HPP
#define ARRAY_HPP

class Array {
private:
    int* A;
    int size;   
    int length; 

    void resize();

public:
    Array(int capacity = 10);
    ~Array();

    void display() const;
    bool append(int x);
    bool insert(int index, int x);
    int remove(int index);
    int linear_search(int key) const;
    int binary_search(int key) const;
    int get_max() const;
    int get_min() const;
    long long sum() const;
    double average() const;
};

#endif
