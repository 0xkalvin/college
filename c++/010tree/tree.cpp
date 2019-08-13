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

void Tree::printNodesGreaterThanAverage(Node *n, double average){
    if(n == NULL)   return;
    else{
        if(n->getValue() > average){
            cout << n->getValue() << " ";
        }
        this->printNodesGreaterThanAverage(n->getLeft(), average);
        this->printNodesGreaterThanAverage(n->getRight(), average);
    }
    
}

int Tree::getTotal(Node *n){
    if(n == NULL) return 0;
    else    return n->getValue() + this->getTotal(n->getLeft()) + this->getTotal(n->getRight());
}

double Tree::getAverage(Node* n){
    return (double)this->getTotal(n) / this->getNumberOfNodes(n);
}

int Tree::getSmallest(Node* n){
    if(n->getLeft() == NULL) return n->getValue();
    else    return this->getSmallest(n->getLeft()); 
}

bool Tree::getElement(Node* n, int elem){
    if(n == NULL) return false;
    else if(n->getValue() == elem)  return true;
    else{
        bool left = this->getElement(n->getLeft(), elem);
        bool right = this->getElement(n->getRight(), elem);
        return right || left;
    }
}

int Tree::getHeight(Node *n){
    if(n == NULL)   return 0;
    else{
        if(this->getHeight(n->getLeft()) > this->getHeight(n->getRight()))  
            return 1 + this->getHeight(n->getLeft());
        else
            return 1 + this->getHeight(n->getRight()); 
    }
}