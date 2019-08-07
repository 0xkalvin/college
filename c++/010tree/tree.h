#ifndef TREE_H
#define TREE_H

#include "node.h"

class Tree {
    private:
        Node *root;

    
    public:
        Tree();
        ~Tree();
        Node* getRoot();
        void insert(int v);
        void insertAux(Node *n, int v);
        void inOrder(Node *n);
        void postOrder(Node *n);
        void preOrder(Node *n);
        int getNumberOfNodes(Node *n);
        int getTotal(Node *n);
        void printLeafs(Node *n);
        void printNodesGreaterThanAverage(Node *n, double average);
        double getAverage(Node *n);
};


#endif