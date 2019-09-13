#include <iostream>
#include "avl.h"


using namespace std;

int main(void){

    AVLTree avlTree;

    avlTree.inserir(1);
    avlTree.inserir(2);
    avlTree.inserir(3);

    cout << avlTree.qtNodes() <<endl;


    avlTree.remover(3);

    cout << avlTree.qtNodes() <<endl;

    return 0;
}