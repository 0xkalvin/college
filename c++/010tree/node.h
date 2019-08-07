#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node {
    private:
        int data;
        Node* left;
        Node* right;
    
    public:
        Node(int v);
        ~Node();
        void setRight(Node* n);
        void setLeft(Node* n);
        Node* getLeft();
        Node* getRight();
        int getValue();
};


#endif