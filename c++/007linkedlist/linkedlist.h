#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "node.h"

template <typename T>
class LinkedList{
    private:
        Node<T> *head;

    public:
        LinkedList();
        ~LinkedList();
        bool isEmpty() const;
        const T &getLast() const;
        const T &getFirst() const;
        Node<T> *getHead() const;
        void insertFirst(const T &elem);
        void insertLast(const T &elem);
        void removeFirst();
        void removeLast();
        void invert();
        void print() const;



};


#endif 