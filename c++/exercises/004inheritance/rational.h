#ifndef	RATIONAL_H
#define	RATIONAL_H
#include "complex.h"


class Rational : public Complex
{   
    public:
        Rational(int n, int d);
        Rational();
        ~Rational();
        friend std::ostream &operator<<(std::ostream &os, Rational &n);
       
};

#endif