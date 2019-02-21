#include <stdlib.h>
#include <iostream>
#include "rational.h"

using namespace std;


Rational::Rational(double a, double b){
    this->value = a/b;
}

Rational::~Rational(){}

double Rational::getValue(){
    return value;
}

Rational Rational::add(Rational n){
    Rational s(n.getValue() + value);
    return s;
}

string Rational::print(){
    return to_string(value);
}