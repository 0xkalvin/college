#ifndef QUEUE_H
#define QUEUE_H

#include "../008stack/stack.cpp"

template <typename T>
class Queue{
    private:
        Stack<T> s1;
        Stack<T> s2;
    public:
        Queue();
        ~Queue();
        void enqueue(int data);
        int dequeue(); 

};

#endif