#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <typename T>
class Node {
    private:
        T data;
        Node<T>* left;
        Node<T>* right;
    
    public:
        Node(T v);
        ~Node();
        void setRight(Node<T>* n);
        void setLeft(Node<T>* n);
        Node<T>* getLeft();
        Node<T>* getRight();
        T getValue();
};


#endif