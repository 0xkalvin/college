#include "tree.h"

/*
    lab:
        Count number of nodes
        Print node values that are greater than average
        Print leafs

 */


int main(){


    Tree t;

    for(int i = 0; i < 5; i++) t.insert(i*i);
    

    cout << "IN ORDER " <<endl;
    t.inOrder(t.getRoot());
    cout <<endl;

    cout << "PRE ORDER " <<endl;
    t.preOrder(t.getRoot());
    cout <<endl;

    cout << "POST ORDER " <<endl;
    t.postOrder(t.getRoot());
    cout <<endl;

    return 0;
}