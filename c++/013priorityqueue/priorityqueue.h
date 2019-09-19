#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "node.h"


class PriorityQueue{
    
    private:
        Node* front;
        Node* rear;

    public:
        PriorityQueue();
        ~PriorityQueue();
        void enqueue(int value, int priority);
        void dequeue();
        void print();

};

#endif