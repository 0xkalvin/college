#ifndef	REAL_H
#define	REAL_H
#include "complex.h"


class Real : public Complex
{
    public:
        Real(double n);
        ~Real();
        Real operator+(Real n);
        Real operator-(Real n);
        Real operator*(Real n);
        Real operator/(Real n);
        friend std::ostream &operator<<(std::ostream &os, Real &n);
       
};

#endif