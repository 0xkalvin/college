#include <stdlib.h>
#include <iostream>
#include "real.h"

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
    cout << "C1 " << r1 <<endl;
    cout << "C2 " << r2 <<endl<<endl;
    cout << "REAL OPERATIONS"<<endl<<endl;
    cout << "SUM " << sum1 <<endl;
    cout << "SUB " << sub1 <<endl;
    cout << "MUL " << mul1 <<endl;
    cout << "DIV " << div1 <<endl<<endl;
    
    return 0;
}