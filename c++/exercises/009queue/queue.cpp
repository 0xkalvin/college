#include "queue.h"


template<typename T>
Queue<T>::Queue(){
    
}

template<typename T>
Queue<T>::~Queue(){
    delete this->s1;
    delete this->s2;
}

template<typename T>
void Queue<T>::enqueue(int data){
    s1.push(data);
    cout << "Data inserted into queue" <<endl;
}

template<typename T>
int Queue<T>::dequeue(){
    int x,y;
    if(!s1.isEmpty()){
        x = s1.pop();
        s2.push(x);
    }

    y = s2.pop();

    while(!s2.isEmpty()){
        x = s2.pop();
        s1.push(x);
    }

    return y
}