#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "rational.h"

using namespace std;


Rational::Rational(int n, int d): Real(n/d){
    this->numerator = n;
    this->denominator = d;
}       
        
Rational::~Rational(){}

int Rational::getNumerator(){
    return numerator;
}

int Rational::getDenominator(){
    return denominator;
}
// SUM
Rational Rational::operator+(Rational n){
    int denominator = this->getDenominator() * n.getDenominator();
    int numerator = (this->getNumerator() * n.getDenominator()) + (n.getNumerator() * this->getDenominator());
    Rational s(numerator, denominator );
    return s;
}   

// SUBTRACTION
Rational Rational::operator-(Rational n){
    int denominator = this->getDenominator() * n.getDenominator();
    int numerator = (this->getNumerator() * n.getDenominator()) - (n.getNumerator() * this->getDenominator());
    Rational s(numerator, denominator );
    return s;
} 
// MULTIPLICATION
Rational Rational::operator*(Rational n){
    int denominator = this->getDenominator() * n.getDenominator();
    int numerator = this->getNumerator() * n.getNumerator();
    Rational m(numerator, denominator );
    return m;
} 

// DIVISION
Rational Rational::operator/(Rational n){
    int denominator = this->getDenominator() / n.getDenominator();
    int numerator = this->getNumerator() / n.getNumerator();
    Rational s(numerator, denominator );
    return s;
} 


std::ostream &operator<<(std::ostream &os, Rational &n) { 
    return os << to_string(n.getNumerator()) + "/" + to_string(n.getDenominator());
}