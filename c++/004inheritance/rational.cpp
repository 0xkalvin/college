#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "rational.h"

using namespace std;


Rational::Rational(int n, int d): Complex(n/(double)d,0){}       
        
Rational::~Rational(){}

std::ostream &operator<<(std::ostream &os, Rational &n) {
    return os << n.getReal();
}