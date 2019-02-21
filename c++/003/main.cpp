#include <stdlib.h>
#include <iostream>
#include "integer.h"
#include "natural.h"
#include "rational.h"

using namespace std;

int main()
{
    
    Natural a1(10);
    Natural b1(15);
    
    // without operator overloading
    Natural c1 = a1.add(b1);

    // operator overloading working fine
    Natural sum1 = a1 + b1;
    Natural m1 = a1 * b1;

    
    cout <<"NATURAL SUM  " <<c1.print() <<endl;
    cout <<"NATURAL SUM OPERATOR " <<sum1.print() <<endl;
    cout <<"NATURAL MULTIPLY OPERATOR " <<m1.print() <<endl;

    // ========================================================================================================

    Integer a2(9);
    Integer b2(7);
    
    // without operator overloading
    Integer c2 = a2.add(b2);

    // operator overloading working fine
    Integer sum2 = a2 + b2;

    
    cout <<"\n\nInteger  " <<c2.print() <<endl;
    cout <<"Integer OPERATOR " <<sum2.print() <<endl;

    // ========================================================================================================

    Rational a3(3,4);

    cout <<"\n\nRATIONAL "<<a3.print() <<endl;

    return 0;
}