#include <stdlib.h>
#include <iostream>
#include "rational.h"

using namespace std;


Rational::Rational(double a, double b){
    this->value = a/b;
}

Rational::~Rational(){}

string Rational::print(){
    return to_string(value);
}

double Rational::getValue(){
    return value;
}

Rational Rational::add(Rational n){
    Rational a(n.getValue() + value, 1);
    return a;
}

Rational Rational::sub(Rational n){
    Rational s(value - n.getValue(), 1);
    return s;
}

Rational Rational::mul(Rational n){
    Rational m(n.getValue() * value, 1);
    return m;
}

Rational Rational::div(Rational n){
    Rational m((value / n.getValue()), 1);
    return m;
}

Rational Rational::operator+(Rational n){
    Rational a(n.getValue() + value, 1);
    return a;
}

Rational Rational::operator-(Rational n){
    Rational s(value - n.getValue(), 1);
    return s;
}

Rational Rational::operator*(Rational n){
    Rational m(n.getValue() * value, 1);
    return m;
}

Rational Rational::operator/(Rational n){
    Rational m((value / n.getValue()), 1);
    return m;
}

std::ostream &operator<<(std::ostream &os, Rational &n) { 
    return os << n.getValue();
}