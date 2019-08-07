#include "tree.h"

/*
                5
            4       6

 */

Tree::Tree(){
    this->root = NULL;
}

Tree::~Tree(){}

void Tree::insert(int v){
    if(this->root == NULL){
        this->root = new Node(v);
    }
    else{
        this->insertAux(this->root, v);
    }
}

void Tree::insertAux(Node* n, int v){
    if(v < n->getValue()){
        if(n->getLeft() == NULL){
            n->setLeft(new Node(v));
        }
        else{
            this->insertAux(n->getLeft(), v);
        }
    }
    else if(v > n->getValue()){
        if(n->getRight() == NULL){
            n->setRight(new Node(v));
        }
        else{
            this->insertAux(n->getRight(), v);
        }

    }
}

// left -> root -> right
void Tree::inOrder(Node*n){
    if(n != NULL){
        this->inOrder(n->getLeft());
        cout <<  n->getValue() << " ";
        this->inOrder(n->getRight());
    }
}

// Root -> Left -> Right
void Tree::preOrder(Node*n){
    if(n != NULL){
        cout <<  n->getValue() << " ";
        this->preOrder(n->getLeft());
        this->preOrder(n->getRight());
    }
}

//  left -> right -> root
void Tree::postOrder(Node*n){
    if(n != NULL){
        this->postOrder(n->getLeft());
        this->postOrder(n->getRight());
        cout <<  n->getValue() << " ";
    }
}

Node* Tree::getRoot(){
    return this->root;
}

int Tree::getNumberOfNodes(Node *n){
    if(n == NULL)   return 0;
    else    return 1 + this->getNumberOfNodes(n->getLeft()) + this->getNumberOfNodes(n->getRight());
}

void Tree::printLeafs(Node *n){
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

