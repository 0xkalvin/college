#include <stdlib.h>
#include <iostream>
#include "rational.h"

using namespace std;

int main(){
    
    
    Complex c1(1,-3);
    Complex c2(0,0);

    Complex sum = c1 + c2;
    Complex sub = c1 - c2;
    Complex mul = c1 * c2;
    Complex div = c1 / c2;

    cout << "COMPLEX NUMBERS"<<endl<<endl;
    cout << "C1 " << c1 <<endl;
    cout << "C2 " << c2 <<endl<<endl;
    cout << "COMPLEX OPERATIONS"<<endl<<endl;
    cout << "SUM " << sum <<endl;
    cout << "SUB " << sub <<endl;
    cout << "MUL " << mul <<endl;
    cout << "DIV " << div <<endl<<endl;

    Real r1(0);
    Real r2(1);

    Real sum1 = r1 + r2;
    Real sub1 = r1 - r2;
    Real mul1 = r1 * r2;
    Real div1 = r1 / r2;

    cout << "REAL NUMBERS"<<endl<<endl;
    cout << "R1 " << r1 <<endl;
    cout << "R2 " << r2 <<endl<<endl;
    cout << "REAL OPERATIONS"<<endl<<endl;
    cout << "SUM " << sum1 <<endl;
    cout << "SUB " << sub1 <<endl;
    cout << "MUL " << mul1 <<endl;
    cout << "DIV " << div1 <<endl<<endl;

    Rational rat1(1,3);
    Rational rat2(1,3);
    int x = rat1.getNumerator();
    cout << x <<endl;


    Rational sum2 = rat1 + rat2;
    Rational sub2 = rat1 - rat2;
    Rational mul2 = rat1 * rat2;
    Rational div2 = rat1 / rat2;

    cout << "RATIONAL NUMBERS"<<endl<<endl;
    cout << "RAT1 " << rat1 <<endl;
    cout << "RAT2 " << rat2 <<endl<<endl;
    cout << "RATIONAL OPERATIONS"<<endl<<endl;
    cout << "SUM " << sum2 <<endl;
    cout << "SUB " << sub2 <<endl;
    cout << "MUL " << mul2 <<endl;
    cout << "DIV " << div2 <<endl<<endl;
    
    return 0;
}