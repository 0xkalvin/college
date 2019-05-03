#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int value){
        this->data = value;
        this->left = this->right = NULL;
    }
} Node;

void printPreOrder(Node *root){
    // root -> left -> right
    if(root == NULL)   return; 
    
    cout <<" "<<root->data;

    printPreOrder(root->left);
    
    printPreOrder(root->right);
}

void printPostOrder(Node *root){
    // left -> right -> root
    if(root == NULL)    return;

    printPostOrder(root->left);

    printPostOrder(root->right);

    cout << " " << root->data;

}

void printInOrder(Node *root){
    // left -> root -> right
    if(root == NULL)    return;

    printInOrder(root->left);

    cout << " " << root->data;

    printInOrder(root->right);
}


int main(){

    Node *root = new Node(100);
    root->left = new Node(90);
    root->right = new Node(80);
    root->left->left = new Node(75);
    root->left->right = new Node(78);
    root->right->left = new Node(50);

    cout << " PRE ORDER:     ";
    
    printPreOrder(root);

    cout <<endl << " POST ORDER:    ";
    
    printPostOrder(root);

    cout <<endl << " IN ORDER:      ";

    printInOrder(root);

    cout <<endl;





    return 0;
}