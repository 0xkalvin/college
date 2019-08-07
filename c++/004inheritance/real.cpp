#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "real.h"

using namespace std;

Real::Real(double n) : Complex(n,0) {}   
        
        
Real::~Real(){}

// SUM
Real Real::operator+(Real n){
    Real s(this->getReal() + n.getReal() );
    return s;
}   

// SUBTRACTION
Real Real::operator-(Real n){
    Real s(this->getReal() - n.getReal() );
    return s;
} 

// MULTIPLICATION
Real Real::operator*(Real n){
    Real m(this->getReal() * n.getReal() );
    return m;
}

// DIVISION
Real Real::operator/(Real n){
    Real d(this->getReal() / n.getReal() );
    return d;
}


std::ostream &operator<<(std::ostream &os, Real &n) { 
    return os << n.getReal();
}