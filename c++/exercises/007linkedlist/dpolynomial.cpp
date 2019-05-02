#include "dpolynomial.h"
#include <cmath>

DPolynomial::DPolynomial() : Dll<Monomial>(){}

DPolynomial::~DPolynomial(){}


void DPolynomial::print(){
    DNode<Monomial> *aux = this->getHead();
    while(aux != NULL){
        if(aux->elem.getCoefficient() > 0)  std::cout <<" + "<< aux->elem.getCoefficient() << "x^" << aux->elem.getExponent();
        else    std::cout <<" "<< aux->elem.getCoefficient() << "x^" << aux->elem.getExponent();
        aux = aux->next;
    }
    std::cout <<std::endl;
}