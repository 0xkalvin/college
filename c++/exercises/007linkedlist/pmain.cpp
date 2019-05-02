#include "polynomial.h"

using namespace std;

int main(){

    Polynomial p1;


    p1.insertFirst(Monomial(2, 2));
    p1.insertFirst(Monomial(2, 3));
    p1.insertFirst(Monomial(2, 1));

    cout << "p(x) is ";
    p1.print();


    cout << "p(0) is " << p1.resolve(0) <<endl;
    cout << "p(1) is " << p1.resolve(1) <<endl;


    return 0;
}