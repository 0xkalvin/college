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


    Rational rat1(1,2);
    Rational rat2(1,2);
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