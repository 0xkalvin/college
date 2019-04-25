#include "linkedlist.h"

template <typename T>
LinkedList<T>::LinkedList(){
    this->head = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList(){
    delete this->head;
}

template <typename T>
bool LinkedList<T>::isEmpty() const{
    return this->head == NULL;
}

template <typename T>
const T &LinkedList<T>::getFirst() const {
    return this->head->elem;
}

template <typename T>
const T &LinkedList<T>::getLast() const {
    Node<T> aux = this->head;
    while(aux->next != NULL) aux = aux->next;
    return aux->elem; 
}


template <typename T>
void LinkedList<T>::insertFirst(const T &elem){
    Node<T> aux = new Node<T>();
    aux->elem = elem;
    aux->next = this->head;
    this->head = aux;
}


template <typename T>
void LinkedList<T>::removeFirst(){
    if(!this->isEmpty()){
        Node *aux = this->head;
        this->head = this->head->next;
        delete aux;
    }
}

