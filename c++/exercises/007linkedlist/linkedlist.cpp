#include "linkedlist.h"

template <typename T>
LinkedList<T>::LinkedList(){
    this->head = NULL;
}

template <typename T>
LinkedList<T>::~LinkedList(){
    delete this->head;
}
