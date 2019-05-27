#ifndef STACK_H
#define STACK_H

#include "../007linkedlist/dll.cpp"

template <typename T>
class Stack{
    private:
        Dll<T> *p;
    public:
        Stack();
        ~Stack();
        bool isEmpty();
        void push(const T &e);
        void pop();
        const T &getTop() const;
        void print();
};

#endif