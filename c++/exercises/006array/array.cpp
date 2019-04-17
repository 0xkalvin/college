#include "array.h"

template <typename T>
Array<T>::Array(int s){
    try{
        this->v = (T*)malloc(s*sizeof(T));
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
    std::cout << "[ ";
    for(int i = 0; i < this->size; i++){
        if(i != this->size - 1) std::cout <<this->v[i]<<", ";
        else std::cout <<this->v[i];
    }
    std::cout << " ]" <<std::endl<<std::endl;
}


// template <typename T>
// void Array<T>::&operator[](T elem, int index){
//     try{
//         if(index < 0 || index >= this->size) throw new std::string("Out of range!");
//         v[index] = elem;
//     }
//     catch (std::string e){
//         std::cout << "Error: " << e <<std::endl;
//     }
// }

