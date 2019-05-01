#include <iostream>
#ifndef NODE_H
#define NODE_H

template <class T>
class LinkedList;


class Polynomial;

template <class T>
class Node{
    private:
        T elem;
        Node<T> *next;
        friend class LinkedList<T>;
        friend class Polynomial;
};

#endif