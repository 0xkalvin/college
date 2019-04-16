#include <iostream>
#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Array {
private:
    T *v;
    int size;
public:
    Array(int s);
    ~Array();
    int getSize();
    T getElement(int index);
    bool search(T elem);
    void insert(T elem, int i);
    void remove(int i);
    Array<T> concat(Array& arr);
    void print();
};


template <typename T>
Array<T>::Array(int s){
    try{
        this->v = new T[10];
        if(v == NULL) throw new std::string("Memory allocation failed! ");
        this->size = s;
    }
    catch (std::string e){
        std::cout << "Error: " << e <<std::endl;
    }
}

template <typename T>
Array<T>::~Array(){
    delete v;
}

template <typename T>
int Array<T>::getSize(){
    return this->size;
}

template <typename T>
T Array<T>::getElement(int index){
    try{
        if(index < 0 || index >= this->size) throw new std::string("Out of range!");
        return v[index];
    }
    catch (std::string e){
        std::cout << "Error: " << e <<std::endl;
    }
}

template <typename T>
void Array<T>::insert(T elem, int index){
    try{
        if(index < 0 || index >= this->size) throw new std::string("Out of range!");
        v[index] = elem;
    }
    catch (std::string e){
        std::cout << "Error: " << e <<std::endl;
    }
}

template <typename T>
void Array<T>::remove(int index){
    try{
        if(index < 0 || index >= this->size) throw new std::string("Out of range!");
        
        for(int i = index; i < this->size - 1; i++){
            this->v[i] = this->v[i+1];
        }
        this->v[index] = NULL;
    }
    catch (std::string e){
        std::cout << "Error: " << e <<std::endl;
    }
}

template <typename T>
bool Array<T>::search(T elem){
    for(int i = 0; i < this->size; i++){
        if(this->v[i] == elem) return true;
    }
    return false;
}

template <typename T>
Array<T> Array<T>::concat(Array<T>& arr){
    Array<T> resp(this->size + arr.getSize());
    
    for(int i = 0; i < this->size; i++){
        resp.insert(this->v[i], i);
    }
    int j = 0;
    for(int i = this->size; i < this->size + arr.getSize(); i++){
        resp.insert(arr.getElement(j), i);
        j++;
        
    }
    return resp;
}

template <typename T>
void Array<T>::print(){
    std::cout << "[";
    for(int i = 0; i < this->size; i++){
        std::cout <<" "<<this->v[i];
    }
    std::cout << "]" <<std::endl;
}

#endif