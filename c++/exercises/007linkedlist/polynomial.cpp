#include "polynomial.h"


Polynomial::Polynomial() : LinkedList<Monomial>(){}

Polynomial::~Polynomial(){}

void Polynomial::print(){
    Node<Monomial> *aux = this->getHead();
    while(aux != NULL){
        std::cout <<" "<< aux->elem.getCoefficient() << "x^" << aux->elem.getExponent();
        aux = aux->next;
    }
    std::cout <<std::endl;
}