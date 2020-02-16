#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "node.h"


class Queue{
    
    private:
        Node* front;
        Node* rear;

    public:
        Queue();
        ~Queue();
        void enqueue(int value);
        void dequeue();
        void print();

};

#endif