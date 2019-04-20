#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "linkedlist.h"
#include "monomial.h"


template <typename T>
class Polynomial : public LinkedList{
    private:
        Monomial<T> *head;

    public:
        Polynomial();
        ~Polynomial();
};

#endif 