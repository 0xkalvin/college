#include "dll.h"


template <typename T>
Dll<T>::Dll(){
    this->head = this->tail = NULL;
}

template <typename T>
Dll<T>::~Dll(){
    delete this->head;
}

template <typename T>
bool Dll<T>::isEmpty() const{
    return this->head == NULL;
}

template <typename T>
const T &Dll<T>::getFirst() const {
    return this->head->elem;
}

template <typename T>
const T &Dll<T>::getLast() const {
    return this->tail->elem;
}

template <typename T>
Node<T> *Dll<T>::getHead() const {
    return this->head;
}