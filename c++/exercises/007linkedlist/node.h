#ifndef NODE_H
#define NODE_H


template <typename T>
class Node{
    private:
        T elem;
        Node<T> *next;
        friend class LinkedList<T>;
};

#endif