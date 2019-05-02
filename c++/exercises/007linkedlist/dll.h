#include <ostream>
#ifndef DLL
#define DLL
#include "dnode.h"


template <typename T>
class Dll{
    private:
        DNode<T> *head;
        DNode<T> *tail;

    public:
        Dll();
        ~Dll();
        bool isEmpty() const;
        const T &getFirst() const;
        const T &getLast() const;
        DNode<T> *getHead() const;
        DNode<T> *getTail() const;
        void insertFirst(const T &elem);
        void insertLast(const T &elem);
        void removeFirst();
        void removeLast();
        void invert();
        void print() const;

};

#endif