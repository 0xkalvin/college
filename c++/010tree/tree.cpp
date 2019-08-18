#include "tree.h"

/*
                5
            4       6

 */

template  <typename T>
Tree<T>::Tree(){
    this->root = NULL;
}

template  <typename T>
Tree<T>::~Tree(){
    delete this->root;
}

template  <typename T>
void Tree<T>::insert(int v){
    if(this->root == NULL){
        this->root = new Node<T>(v);
    }
    else{
        this->insertAux(this->root, v);
    }
}

template  <typename T>
void Tree<T>::insertAux(Node<T>* n, int v){
    if(v < n->getValue()){
        if(n->getLeft() == NULL){
            n->setLeft(new Node<T>(v));
        }
        else{
            this->insertAux(n->getLeft(), v);
        }
    }
    else if(v > n->getValue()){
        if(n->getRight() == NULL){
            n->setRight(new Node<T>(v));
        }
        else{
            this->insertAux(n->getRight(), v);
        }

    }
}

// left -> root -> right
template  <typename T>
void Tree<T>::inOrder(Node<T>*n){
    if(n != NULL){
        this->inOrder(n->getLeft());
        cout <<  n->getValue() << " ";
        this->inOrder(n->getRight());
    }
}

// Root -> Left -> Right
template  <typename T>
void Tree<T>::preOrder(Node<T>*n){
    if(n != NULL){
        cout <<  n->getValue() << " ";
        this->preOrder(n->getLeft());
        this->preOrder(n->getRight());
    }
}

//  left -> right -> root
template  <typename T>
void Tree<T>::postOrder(Node<T>*n){
    if(n != NULL){
        this->postOrder(n->getLeft());
        this->postOrder(n->getRight());
        cout <<  n->getValue() << " ";
    }
}

template  <typename T>
Node<T>* Tree<T>::getRoot(){
    return this->root;
}

template  <typename T>
int Tree<T>::getNumberOfNodes(Node<T> *n){
    if(n == NULL)   return 0;
    else    return 1 + this->getNumberOfNodes(n->getLeft()) + this->getNumberOfNodes(n->getRight());
}

template  <typename T>
void Tree<T>::printLeafs(Node<T> *n){
    if(n == NULL){
        return;
    }
    else if(n->getLeft() == NULL && n->getRight() == NULL){
        cout << n->getValue() << " ";
    }
    else{
        this->printLeafs(n->getLeft());
        this->printLeafs(n->getRight());
    }
}

template  <typename T>
void Tree<T>::printNodesGreaterThanAverage(Node<T> *n, double average){
    if(n == NULL)   return;
    else{
        if(n->getValue() > average){
            cout << n->getValue() << " ";
        }
        this->printNodesGreaterThanAverage(n->getLeft(), average);
        this->printNodesGreaterThanAverage(n->getRight(), average);
    }
    
}

template  <typename T>
int Tree<T>::getTotal(Node<T> *n){
    if(n == NULL) return 0;
    else    return n->getValue() + this->getTotal(n->getLeft()) + this->getTotal(n->getRight());
}

template  <typename T>
double Tree<T>::getAverage(Node<T>* n){
    return (double)this->getTotal(n) / this->getNumberOfNodes(n);
}

template  <typename T>
int Tree<T>::getSmallest(Node<T>* n){
    if(n->getLeft() == NULL) return n->getValue();
    else    return this->getSmallest(n->getLeft()); 
}

template  <typename T>
Node<T>* Tree<T>::getElement(Node<T>* n, int elem){
    if(n == NULL) return NULL;
    else if(n->getValue() == elem)  return n;
    else{
        if(elem < n->getValue())    return this->getElement(n->getLeft(), elem);
        else return this->getElement(n->getRight(), elem);
    }
}

template  <typename T>
int Tree<T>::getHeight(Node<T> *n){
    if(n == NULL)   return 0;
    else{
        if(this->getHeight(n->getLeft()) > this->getHeight(n->getRight()))  
            return 1 + this->getHeight(n->getLeft());
        else
            return 1 + this->getHeight(n->getRight()); 
    }
}

template  <typename T>
void Tree<T>::deleteNode(int v){
    
}