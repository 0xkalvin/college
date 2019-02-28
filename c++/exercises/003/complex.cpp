#include <stdlib.h>
#include <iostream>
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


Complex Complex::add(Complex n){
    // ( a + bi ) + ( c + di ) = ( a + c ) + ( b + d ) i
    double realPart = real + n.getReal();
    double imaginaryPart = imaginary + n.getImaginary();
    Complex s(realPart, imaginaryPart);
    return s;
}   

Complex Complex::sub(Complex n){
    double realPart = real - n.getReal();
    double imaginaryPart = imaginary - n.getImaginary();
    Complex s(realPart, imaginaryPart);
    return s;
} 

Complex Complex::mul(Complex n){
    // ( a + bi ) * ( c + di ) = ( ac - bd ) + ( ad + bc ) i
    double realPart = (real * n.getReal()) - (imaginary * n.getImaginary());
    double imaginaryPart = (real + n.getImaginary()) + (imaginary + n.getReal());
    Complex m(realPart, imaginaryPart);
    return m;
} 

Complex Complex::operator+(Complex n){
    // ( a + bi ) + ( c + di ) = ( a + c ) + ( b + d ) i
    double realPart = real + n.getReal();
    double imaginaryPart = imaginary + n.getImaginary();
    Complex s(realPart, imaginaryPart);
    return s;
}   

Complex Complex::operator-(Complex n){
    double realPart = real - n.getReal();
    double imaginaryPart = imaginary - n.getImaginary();
    Complex s(realPart, imaginaryPart);
    return s;
} 

Complex Complex::operator*(Complex n){
    // ( a + bi ) * ( c + di ) = ( ac - bd ) + ( ad + bc ) i
    double realPart = (real * n.getReal()) - (imaginary * n.getImaginary());
    double imaginaryPart = (real + n.getImaginary()) + (imaginary + n.getReal());
    Complex m(realPart, imaginaryPart);
    return m;
}


std::ostream &operator<<(std::ostream &os, Complex &n) { 
    if(n.getImaginary() >= 0) return os << to_string(n.getReal()) + "+" + to_string(n.getImaginary()) + "i";
    else return os << to_string(n.getReal()) + to_string(n.getImaginary()) + "i";
}