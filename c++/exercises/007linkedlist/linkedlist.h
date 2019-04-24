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
        void insertFirst(const T& elem);
        void removeFirst();
        void insertLast();
        void removeLast();
        void invert();
        Node<T> getLast() const;
        const T &getFirst() const;


};


#endif 