#include "dpolynomial.h"


int main(){

    DPolynomial p1;

    p1.insertLast(Monomial(2,1));
    p1.insertLast(Monomial(-3,2));
    p1.insertLast(Monomial(4,3));

    p1.print();

    
    return 0;
}