#include "dll.h"


template <typename T>
Dll<T>::Dll(){
    this->head = this->tail = NULL;
}

template <typename T>
Dll<T>::~Dll(){
    if(!this->isEmpty()) delete this->head;
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
DNode<T> *Dll<T>::getHead() const {
    return this->head;
}

template <typename T>
void Dll<T>::insertFirst(const T &elem){
    DNode<T> *first = new DNode<T>();
    first->elem = elem;
    first->prev = NULL;
    if(this->isEmpty()){
        first->next = NULL;
        this->head = this-> tail = first;
    }
    else{
        first->next = this->head;
        this->head->prev = first;
        this->head = first; 
    }
}



template <typename T>
void Dll<T>::print() const {
    DNode<T> *aux = this->head;
    std::cout << "[ ";
    while(aux != this->tail){ 
        std::cout << aux->elem <<", ";
        aux = aux->next;
    }
    std::cout << this->tail->elem<< " ]"<<std::endl;

}