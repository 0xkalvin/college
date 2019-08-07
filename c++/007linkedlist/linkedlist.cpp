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
    Node<T> *aux = this->head;
    while(aux->next != NULL) aux = aux->next;
    return aux->elem; 
}

template <typename T>
Node<T> *LinkedList<T>::getHead() const {
    return this->head;
}


template <typename T>
void LinkedList<T>::insertFirst(const T &elem){
    Node<T> *aux = new Node<T>();
    aux->elem = elem;
    aux->next = this->head;
    this->head = aux;
}

template <typename T>
void LinkedList<T>::insertLast(const T &elem){
    Node<T> *last = new Node<T>();
    last->elem = elem;
    last->next = NULL;

    Node<T> *aux = this->head;
    while(aux->next != NULL) aux = aux->next;
    aux->next = last;
}

template <typename T>
void LinkedList<T>::removeFirst(){
    if(!this->isEmpty()){
        Node<T> *aux = this->head;
        this->head = this->head->next;
        delete aux;
    }
}

template <typename T>
void LinkedList<T>::removeLast(){
    Node<T> *aux = this->head;
    while(aux->next->next != NULL) aux = aux->next;
    delete aux->next;
    aux->next = NULL;
}

template <typename T>
void LinkedList<T>::invert(){
    Node<T> *aux = this->head;
    LinkedList<T> result;
    while (aux != NULL) {
        result.insertFirst(aux->elem);
        aux = aux->next;
        this->removeFirst();
    }
    this->head = new Node<T>();
    this->head->elem = result.getFirst();
    this->head->next = result.getHead()->next;
}


template <typename T>
void LinkedList<T>::print() const{
    Node<T> *aux = this->head;
    std::cout << "[ ";
    while(aux->next != NULL){ 
        std::cout << aux->elem <<", ";
        aux = aux->next;
    }
    std::cout << aux->elem<< " ]"<<std::endl;

}

    