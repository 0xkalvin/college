#ifndef MONOMIAL_H
#define MONOMIAL_H


template <typename T>
class Polynomial;

template <typename T>
class Monomial{
    private:
        T coefficient;
        T exponent;
        Monomial<T> *next;
        friend class Polynomial<T>;
};

#endif 