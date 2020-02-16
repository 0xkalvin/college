#include "node.h"


template <typename T>
Node<T>::Node(T v){
    this->data = v;
    this->left = NULL;
    this->right = NULL;
}

template <typename T>
Node<T>::~Node(){
    delete this->left;
    delete this->right;
}

template <typename T>
void Node<T>::setLeft(Node* n){
    this->left = n;
}

template <typename T>
void Node<T>::setRight(Node* n){
    this->right = n;
}

template <typename T>
Node<T>* Node<T>::getLeft(){
    return this->left;
}

template <typename T>
Node<T>* Node<T>::getRight(){
    return this->right;
}

template <typename T>
T Node<T>::getValue(){
    return this->data;
}