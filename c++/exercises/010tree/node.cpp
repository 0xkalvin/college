#include "node.h"


Node::Node(int v){
    this->data = v;
    this->left = NULL;
    this->right = NULL;
}

Node::~Node(){
    delete this->left;
    delete this->right;
}

void Node::setLeft(Node* n){
    this->left = n;
}

void Node::setRight(Node* n){
    this->right = n;
}

Node* Node::getLeft(){
    return this->left;
}

Node* Node::getRight(){
    return this->right;
}

int Node::getValue(){
    return this->data;
}