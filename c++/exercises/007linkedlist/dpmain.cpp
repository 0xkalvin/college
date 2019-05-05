#include "dpolynomial.h"

using namespace std;

int main(){

    DPolynomial p1;

    p1.insertLast(Monomial(1,1));
    p1.insertLast(Monomial(2,3));
    p1.insertLast(Monomial(3,3));

    cout << "p(x) = ";
    p1.print();

    int x = 0;
    cout << "p("<< x <<") = " << p1.resolve(x) <<endl;

    
    return 0;
}