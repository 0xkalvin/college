#include "polynomial.h"
#include <cmath>

Polynomial::Polynomial() : LinkedList<Monomial>(){}

Polynomial::~Polynomial(){}

void Polynomial::print(){
    Node<Monomial> *aux = this->getHead();
    while(aux != NULL){
        if(aux->elem.getCoefficient() > 0)  std::cout <<" + "<< aux->elem.getCoefficient() << "x^" << aux->elem.getExponent();
        else    std::cout <<" "<< aux->elem.getCoefficient() << "x^" << aux->elem.getExponent();
        aux = aux->next;
    }
    std::cout <<std::endl;
}


double Polynomial::resolve(int k){
    double sum = 0;
    Node<Monomial> *aux = this->getHead();
    while(aux != NULL){
        sum += aux->elem.getCoefficient()*pow(k, aux->elem.getExponent());
        aux = aux->next;
    }
    return sum;
}