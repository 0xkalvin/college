#ifndef	RATIONAL_H
#define	RATIONAL_H
#include "real.h"


class Rational : public Real
{   
    private:
        int denominator;
        int numerator;
    public:
        Rational(int n, int d);
        Rational();
        ~Rational();
        int getNumerator();
        int getDenominator();
        Rational operator+(Rational n);
        Rational operator-(Rational n);
        Rational operator*(Rational n);
        Rational operator/(Rational n);
        friend std::ostream &operator<<(std::ostream &os, Rational &n);
       
};

#endif