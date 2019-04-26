#include "dll.h"


template <typename T>
Dll<T>::Dll(){
    this->head = this->tail = NULL;
}

template <typename T>
Dll<T>::~Dll(){
    delete this->head;
}