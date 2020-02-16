#ifndef TREE_H
#define TREE_H

#include "node.cpp"

template  <typename T>
class Tree {
    private:
        Node<T> *root;

    
    public:
        Tree();
        ~Tree();
        Node<T>* getRoot();
        void insert(int v);
        void insertAux(Node<T> *n, int v);
        void inOrder(Node<T> *n);
        void postOrder(Node<T> *n);
        void preOrder(Node<T> *n);
        int getNumberOfNodes(Node<T> *n);
        int getTotal(Node<T> *n);
        void printLeafs(Node<T> *n);
        void printNodesGreaterThanAverage(Node<T> *n, double average);
        double getAverage(Node<T> *n);
        int getSmallest(Node<T>* n);
        int getHeight(Node<T>* n);
        Node<T>* getElement(Node<T>* n, int elem);
        Node<T>* getElementIterative(Node<T>* n, int elem);
        void deleteNode(int v);
};


#endif