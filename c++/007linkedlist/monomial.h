#ifndef MONOMIAL_H
#define MONOMIAL_H

class Monomial{
    private:
        double coefficient;
        int exponent;

    public:
        Monomial(double c, int e);
        Monomial();
        ~Monomial();
        double getCoefficient();
        int getExponent();
};

#endif 