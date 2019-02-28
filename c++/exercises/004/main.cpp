#include <stdlib.h>
#include <iostream>
#include "complex.h"

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
    
    return 0;
}