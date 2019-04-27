#include <iostream>
#ifndef DNODE_H
#define DNODE_H

template <class T>
class Dll;

template <class T>
class DNode{
    private:
        T elem;
        DNode<T> *next;
        DNode<T> *prev;
        friend class Dll<T>;
};

#endif