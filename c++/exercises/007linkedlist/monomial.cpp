#include "monomial.h"


Monomial::Monomial(double c, int e){
    this->coefficient = c;
    this->exponent = e;
}

Monomial::Monomial(){}

Monomial::~Monomial(){}

double Monomial::getCoefficient(){
    return this->coefficient;
}

int Monomial::getExponent(){
    return this->exponent;
}