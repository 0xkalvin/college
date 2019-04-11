#include <iostream>
#ifndef ARRAY_H
#define ARRAY_H

using namespace std;

template <typename T>
class Array{

    private:
        T* v;
        int size;
    
    public:
        Array(int s);
        ~Array();
        int getSize();
        T getElement(int index);
        bool search(T element);
        void append(T element, int index);
};

template <typename T>
Array<T>::Array(int s){
    this->v = new T[s];
    if(this->v==NULL){
        throw new std::string("Error during memory allocation! ");
    }
    this->size = s;
}

template <typename T>
Array<T>::~Array(){
    delete v;
}


template <typename T>
T Array<T>::getElement(int i){
    if(i < 0 || i >= this->size ){
         throw new std::string("out of range");
    }
    return v[i];
}

template <typename T>
int Array<T>::getSize(){
    return this->size;
}

template <typename T>
bool Array<T>::search(T e){
    for(int i = 0; i < this>size; i++){
        if(this->v[i] == e) return true;
    }
    return false;
}

template <typename T>
void Array<T>::append(T element, int index){
    if(index < 0 || index >= this->size){
        throw new std::string("out of range");
    }
    this->v[index] = element;
}

#endif