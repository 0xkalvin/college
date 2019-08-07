#include "stack.h"


template <typename T>
Stack<T>::Stack(){
    this->p = new Dll<T>();
    if(this->p == NULL) throw new std::string("Memory error!");
}

template <typename T>
Stack<T>::~Stack(){
    delete this->p;
}

template <typename T>
bool Stack<T>::isEmpty(){
    return this->p->isEmpty();
}

template <typename T>
void Stack<T>::push(const T &e){
    this->p->insertLast(e);
}

template <typename T>
void Stack<T>::pop(){
    this->p->removeLast();
}

template <typename T>
const T &Stack<T>::getTop() const{
    return this->p->getLast();
}

template <typename T>
void Stack<T>::print(){
    this->p->print();
}