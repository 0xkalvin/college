#include <ostream>
#ifndef DLL
#define DLL
#include "node.h"


template <typename T>
class Dll{
    private:
        Node<T> *head;
        Node<T> *tail;

    public:
        Dll();
        ~Dll();
        bool isEmpty() const;
        const T &getFirst() const;
        const T &getLast() const;
        Node<T> *getHead() const;
        void insertFirst(const T &elem);
        void insertLast(const T &elem);
        void removeFirst();
        void removeLast();
        void invert();
        void print() const;

};

#endif