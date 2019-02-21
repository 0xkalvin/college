#include <stdlib.h>
#include <iostream>
#include "integer.h"
#include "natural.h"
#include "rational.h"

using namespace std;

int main()
{
    
    Natural nat1(10);
    Natural nat2(15);
    
    // without operator overloading
    Natural nat3 = nat1.add(nat2);

    // operator overloading working fine
    Natural nat4 = nat1 + nat2;
    Natural nat5 = nat1 * nat2;

    
    cout <<"NATURAL SUM  " <<nat3.print() <<endl;
    cout <<"NATURAL SUM OPERATOR " <<nat4.print() <<endl;
    cout <<"NATURAL MULTIPLY OPERATOR " <<nat5.print() <<endl;

    // ========================================================================================================

    Integer int1(9);
    Integer int2(7);
    
    // without operator overloading
    Integer int3 = int1.add(int2);

    // operator overloading working fine
    Integer int4 = int1 + int2;

    
    cout <<"\n\nInteger  " <<int3.print() <<endl;
    cout <<"Integer OPERATOR " <<int4.print() <<endl;

    // ========================================================================================================

    Rational rat1(3,4);
    Rational rat2(1,2);

    Rational r1 = rat1 + rat2;
    Rational r2 = rat1 - rat2;
    Rational r3 = rat1 * rat2;
    Rational r4 = rat1 / rat2;

    cout <<"\n\nRATIONAL SUM "<<r1.print() <<endl;
    cout <<"\n\nRATIONAL SUB "<<r2.print() <<endl;
    cout <<"\n\nRATIONAL MULT "<<r3.print() <<endl;
    cout <<"\n\nRATIONAL DIV "<<r4.print() <<endl;


    return 0;
}