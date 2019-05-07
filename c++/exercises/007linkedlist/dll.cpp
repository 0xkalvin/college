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

template<typename T>
const int Dll<T>::getSize() const {
    if(this->isEmpty()) return 0;
    else{
        DNode<T> *aux = this->getHead();
        int size = 0;
        while(aux != NULL){
            size++;
            aux = aux->next;
        }
        return size;
    }
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
void Dll<T>::insertAt(const T &elem, int k){
    if(k >= this->getSize() || k < 0) throw new std::string("Out of range! \n");
    else{
        if(this->getSize() - 1 == k){
            this->insertLast(elem);
            return;
        }
        else if(k == 0){
            this->insertFirst(elem);
            return;
        }
        else{
            DNode<T> *aux = this->getHead();
            int count = 0;
            while(count != k - 1){
                count++;
                aux = aux->next;
            }
            DNode<T> *newElem = new DNode<T>();
            newElem->elem = elem;
            newElem->next = aux->next;
            newElem->prev = aux;
            aux->next->prev = newElem;
            aux->next = newElem;
        }
 
    }
 
}

template <typename T>
void Dll<T>::insertAfter(DNode<T> *p){
    if(this->getSize() <= 1) return;
    else{
        DNode<T> *aux = this->getHead();
        while(aux != p){
            aux = aux->next;
        }
        DNode<T> *newElem = new DNode<T>();
        newElem->elem = p->elem;
        newElem->next = aux->next;
        newElem->prev = aux;
        aux->next->prev = newElem;
        aux->next = newElem;     
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
void Dll<T>::exchangeEdge(){
    if(this->getSize() > 1){
        T aux = this->head->elem;
        this->head->elem = this->tail->elem;
        this->tail->elem = aux;
    }
    else return;

}

template <typename T>
void Dll<T>::print() const {
    DNode<T> *aux = this->head;
    std::cout << "[ ";
    while(aux != NULL){ 
        if(aux->next == NULL) std::cout << aux->elem <<" ";
        else std::cout << aux->elem <<", ";
        aux = aux->next;
    }
    std::cout << "]"<<std::endl;

}

template <typename T>
T &Dll<T>::operator[](int index){
    if(index >= this->getSize() || index < 0) throw new std::string("Out of range");
    DNode<T> *aux = this->getHead();
    int count = 0;
    while(count != index){
        count++;
        aux= aux->next;
    }

    return aux->elem;
    
}