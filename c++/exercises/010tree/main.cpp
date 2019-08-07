#include "tree.h"

/*
    lab:
        Count number of nodes
        Print node values that are greater than average
        Print leafs

                10
              1      20
                  15    30
                      25
 */


int main(){


    Tree t;

    t.insert(10);
    t.insert(20);
    t.insert(30);
    t.insert(25);
    t.insert(1);
    t.insert(15);
    

    cout << "IN ORDER " <<endl;
    t.inOrder(t.getRoot());
    cout <<endl;

    cout << "PRE ORDER " <<endl;
    t.preOrder(t.getRoot());
    cout <<endl;

    cout << "POST ORDER " <<endl;
    t.postOrder(t.getRoot());
    cout <<endl;

    cout << "NUMBER OF NODES IS " << t.getNumberOfNodes(t.getRoot()) << endl;

    t.printLeafs(t.getRoot());


    return 0;
}