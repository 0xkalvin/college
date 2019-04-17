#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "complex.h"

using namespace std;


Complex::Complex(double real, double imaginary){
    this->real = real;
    this->imaginary = imaginary;
};

Complex::~Complex(){}

double Complex::getReal(){
    return real;
}

double Complex::getImaginary(){
    return imaginary;
}

// SUM
Complex Complex::operator+(Complex n){
    // ( a + bi ) + ( c + di ) = ( a + c ) + ( b + d ) i
    double realPart = real + n.getReal();
    double imaginaryPart = imaginary + n.getImaginary();
    Complex s(realPart, imaginaryPart);
    return s;
}   

// SUBTRACTION
Complex Complex::operator-(Complex n){
    double realPart = real - n.getReal();
    double imaginaryPart = imaginary - n.getImaginary();
    Complex s(realPart, imaginaryPart);
    return s;
} 

// MULTIPLICATION
Complex Complex::operator*(Complex n){
    // ( a + bi ) * ( c + di ) = ( ac - bd ) + ( ad + bc ) i
    double realPart = (real * n.getReal()) - (imaginary * n.getImaginary());
    double imaginaryPart = (real * n.getImaginary()) + (imaginary * n.getReal());
    Complex m(realPart, imaginaryPart);
    return m;
}

// DIVISION
Complex Complex::operator/(Complex n){
    // a: real; b: imaginary; c: n.getReal(); d: n.getImaginary()
    // ( a + bi ) / ( c + di ) = ((ac + bd) + i(bc - ad))/(c**2 + d**2)
    if(n.getImaginary()==0 && n.getReal() == 0) return n;
    double denominator = (pow(n.getReal(), 2)+ pow(n.getImaginary(), 2));
    double realPart = (real*n.getReal() + imaginary*getImaginary())/denominator;
    double imaginaryPart = (imaginary*n.getReal() + real*n.getImaginary())/denominator;
    Complex d(realPart, imaginaryPart);
    return d;
}


std::ostream &operator<<(std::ostream &os, Complex &n) { 
    if(n.getImaginary() > 0) return os <<n.getReal() << "+" << n.getImaginary() << "i";
    else if(n.getImaginary() < 0) return os <<n.getReal()  << n.getImaginary() << "i";
    else if (n.getImaginary() == 0) return os << n.getReal();
}