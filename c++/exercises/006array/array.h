#include <iostream>
#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Array {
private:
    T *v;
    int size;
public:
    Array(int s);
    ~Array();
    int getSize();
    T getElement(int index);
    bool search(T elem);
    void insert(T elem, int i);
    void remove(int i);
    Array<T> concat(Array& arr);
    void print();
    //void &operator[](T &elem, int i);
};

#endif