#include "avl.h"
#include <iostream>

using namespace std;

AVLTree::AVLTree()
{
    //ctor
    this->root = NULL;
}

AVLTree::~AVLTree()
{
    delete this->root;
}

bool AVLTree::isEmpty()
{
    return this->root == NULL;
}

int AVLTree::height()
{
    return height(root); //altura da ·rvore È a altura do seu nÛ raiz
}

int AVLTree::height(AVLNode *no)
{ /*Se o nÛ for NULL retorna -1, sen„o retorna o que vier do mÈtodo getHeight()*/

    return no == NULL ? -1 : no->getHeight();
}

int AVLTree::maximo(int lhs, int rhs)
{
    return lhs > rhs ? lhs : rhs;
}

int AVLTree::qtNodes()
{
    return qtNodes(this->root);
}

int AVLTree::qtNodes(AVLNode *no)
{
    if (no == NULL)
        return 0;
    int qtleft = qtNodes(no->getLeft());
    int qtright = qtNodes(no->getRight());
    return qtleft + qtright + 1;
}
/*Inserir È polimorfico. o MÈtodo publico È pra inserir na ·rvore. Esse mÈtodo invoca o mÈtodo privado, que È recursivo*/
void AVLTree::inserir(int valor)
{
    this->root = inserir(this->root, valor);
}

AVLNode *AVLTree::inserir(AVLNode *node, int valor)
{

    /*Se È uma arvore ou subarvore vazia, cria 1 novo nÛ e retorna*/
    if (node == NULL)
        return new AVLNode(valor);
    if (valor < node->getData())
    {
        node->setLeft(inserir(node->getLeft(), valor));
        if (height(node->getRight()) - height(node->getLeft()) == -2)
        {
            if (valor < node->getLeft()->getData())
            {
                node = rotateLL(node);
            }
            else
            {
                node = rotateLR(node);
            }
        }
    }
    else
    {
        if (valor > node->getData())
        {
            node->setRight(inserir(node->getRight(), valor));
            if (height(node->getRight()) - height(node->getLeft()) == 2)
            {
                if (valor > node->getRight()->getData())
                    node = rotateRR(node);
                else
                    node = rotateRL(node);
            }
        }
    }
    node->setHeight(maximo(height(node->getLeft()), height(node->getRight())) + 1);

    return node;
}

AVLNode *AVLTree::rotateLL(AVLNode *node)
{
    AVLNode *leftSubTree = node->getLeft();
    node->setLeft(leftSubTree->getRight());
    leftSubTree->setRight(node);
    node->setHeight(maximo(height(node->getLeft()), height(node->getRight())) + 1);
    leftSubTree->setHeight(maximo(height(leftSubTree->getLeft()), height(node) + 1));
    return leftSubTree;
}

AVLNode *AVLTree::rotateRR(AVLNode *node)
{
    AVLNode *rightSubTree = node->getRight();
    node->setRight(rightSubTree->getLeft());
    rightSubTree->setLeft(node);
    node->setHeight(maximo(height(node->getLeft()), height(node->getRight())) + 1);
    rightSubTree->setHeight(maximo(height(rightSubTree->getRight()), height(node) + 1));
    return rightSubTree;
}

AVLNode *AVLTree::rotateLR(AVLNode *node)
{
    node->setLeft(rotateRR(node->getLeft()));
    return rotateLL(node);
}

AVLNode *AVLTree::rotateRL(AVLNode *node)
{
    node->setRight(rotateLL(node->getRight()));
    return rotateRR(node);
}

void AVLTree::preOrder()
{
    preOrder(root);
}

void AVLTree::inOrder()
{
    inOrder(root);
}

void AVLTree::posOrder()
{
    posOrder(root);
}
void AVLTree::reverseOrder()
{
    reverseOrder(root);
}
void AVLTree::preOrder(AVLNode *no)
{
    if (no != NULL)
    {
        cout << no->getData() << endl;
        preOrder(no->getLeft());
        preOrder(no->getRight());
    }
}

void AVLTree::posOrder(AVLNode *no)
{
    if (no != NULL)
    {
        posOrder(no->getLeft());
        posOrder(no->getRight());
        cout << no->getData() << endl;
    }
}

void AVLTree::inOrder(AVLNode *no)
{
    if (no != NULL)
    {
        inOrder(no->getLeft());
        cout << no->getData() << endl;
        inOrder(no->getRight());
    }
}

void AVLTree::reverseOrder(AVLNode *no)
{
    if (no != NULL)
    {
        reverseOrder(no->getRight());
        cout << no->getData() << endl;

        reverseOrder(no->getLeft());
    }
}

AVLNode *AVLTree::remover(AVLNode *no, int valor)
{

    if (no == NULL)
        return no;

    AVLNode *temp;
    // caso valor seja menor que raiz, vai para esquerda
    if (valor < this->root->getData())
    {
        no->setLeft(this->remover(no->getLeft(), valor));
    }

    // caso valor seja maior que raiz, vai para direita
    else if (valor > this->root->getData())
        no->setRight(this->remover(no->getRight(), valor));

    // caso nó tenha 2 filhos (direita e esquerda)
    else if (no->getLeft() && no->getRight())
    {
        temp = minimo(no->getRight());
        no->setData(temp->getData());
        no->setRight(this->remover(no->getRight(), valor));
    }

    else
    {
        temp = no;
        if (no->getLeft() == NULL)
        {
            no = no->getRight();
        }
        else if (no->getRight() == NULL)
        {
            no = no->getLeft();
        }
        delete temp;
    }
    if (no == NULL)
    {
        return no;
    }

    no->setHeight(max(height(no->getLeft()), height(no->getRight())) + 1);

    if (height(no->getLeft()) - height(no->getRight()) == 2)
    {
        if (height(no->getLeft()->getLeft()) - height(no->getLeft()->getRight()) == 1)
            return rotateRR(no);
        else
            return rotateLR(no);
    }
    else if (height(no->getRight()) - height(no->getLeft()) == 2)
    {
        if (height(no->getRight()->getRight()) - height(no->getRight()->getLeft()) == 1)
            return rotateLL(no);
        else
            return rotateRR(no);
    }
    return no;
}

void AVLTree::remover(int valor)
{

    this->root = remover(this->root, valor);
}

AVLNode *AVLTree::minimo(AVLNode *no)
{
    if (no == NULL)
        return NULL;
    else if (no->getLeft() == NULL)
        return no;
    else
        return minimo(no->getLeft());
}
