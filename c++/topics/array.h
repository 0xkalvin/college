#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Array{

    private:
        T* v;
        int size;
    
    public:
        Array(int s);
        ~Array();
        int getSize();
        T getElement(int index);
        bool search(T element);
        void append(T element, int index);
};

#endif