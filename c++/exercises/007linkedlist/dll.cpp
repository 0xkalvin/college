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
DNode<T> *Dll<T>::getTail() const {
    return this->tail;
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
void Dll<T>::insertLast(const T &elem){
    DNode<T> *last = new DNode<T>();
    last->next = NULL;
    last->elem = elem;

    if(this->isEmpty()){
        last->prev = NULL;
        this->head = this->tail = last;
    } 
    else{
        last->prev = this->tail;
        this->tail->next = last;
        this->tail = last;
    }
}

template <typename T>
void Dll<T>::removeFirst(){
    if(!this->isEmpty()){
        if(this->head != this->tail){
            DNode<T> *aux = this->head;
            this->head = this->head->next;
            delete aux;
        }
        else{
            delete this->head;
            this->head = this->tail = NULL;
        }
    }
    
}

template <typename T>
void Dll<T>::removeLast(){
    if(!this->isEmpty()){
        if(this->head != this->tail){
            DNode<T> *aux = this->tail;
            this->tail = this->tail->prev;
            this->tail->next = NULL;
            delete aux;
        }
        else{
            delete this->head;
            this->head = this->tail = NULL;
        }
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