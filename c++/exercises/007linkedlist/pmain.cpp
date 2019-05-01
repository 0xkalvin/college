#include "polynomial.h"



int main(){

    Polynomial p1;


    p1.insertFirst(Monomial(1.2, 2));
    p1.insertFirst(Monomial(6, 3));
    p1.insertFirst(Monomial(2.5, 1));

    p1.print();


    return 0;
}