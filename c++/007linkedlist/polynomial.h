#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "monomial.h"
#include "linkedlist.cpp"


class Polynomial : public LinkedList<Monomial>{
    public:
        Polynomial();
        ~Polynomial();
        void print();
        double resolve(int k);
};

#endif 