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
void LinkedList<T>::removeFirst(){
    if(!this->isEmpty()){
        Node *aux = this->head;
        this->head = this->head->next;
        delete aux;
    }
}
