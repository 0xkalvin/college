#ifndef DPOLYNOMIAL_H
#define DPOLYNOMIAL_H
#include "monomial.h"
#include "dll.cpp"


class DPolynomial : public Dll<Monomial>{
    public:
        DPolynomial();
        ~DPolynomial();
        void print();
        double resolve(int k);
};

#endif 