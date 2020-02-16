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


double DPolynomial::resolve(int k){
    DNode<Monomial> *auxStart = this->getHead();
    DNode<Monomial> *auxEnd = this->getTail();
    double sum = 0;
    while(auxStart != NULL && auxEnd != NULL){
        if(auxStart == auxEnd)    return sum + auxStart->elem.getCoefficient()*pow(k, auxStart->elem.getExponent());
        else if(auxStart->prev == auxEnd) return sum;
        else{
            sum += auxStart->elem.getCoefficient()*pow(k, auxStart->elem.getExponent()) + auxEnd->elem.getCoefficient()*pow(k, auxEnd->elem.getExponent());
            auxStart = auxStart->next;
            auxEnd = auxEnd->prev;
        }
    }
    return sum;
}