#include "dpolynomial.h"

using namespace std;

int main(){

    DPolynomial p1;

    p1.insertLast(Monomial(1,1));
    p1.insertLast(Monomial(2,3));
    p1.insertLast(Monomial(3,3));

    cout << "p(x) is ";
    p1.print();

    cout << "p(1) is " << p1.resolve(1) <<endl;

    
    return 0;
}