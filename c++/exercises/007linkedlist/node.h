#include <iostream>
#ifndef NODE_H
#define NODE_H

template <class T>
class LinkedList;

template <class T>
class Node{
    private:
        T elem;
        Node<T> *next;
        friend class LinkedList<T>;
};

#endif