#include <stdlib.h>
#include <iostream>
#include "integer.h"
#include "natural.h"

using namespace std;

int main()
{
    


    Natural a1(10);
    Natural b1(15);
    
    // without operator overloading
    Natural c1 = a1.add(b1);

    // operator overloading working fine
    Natural d1 = a1 + b1;

    
    cout <<"NATURAL  " <<c1.print() <<endl;
    cout <<"NATURAL OPERATOR " <<d1.print() <<endl;

    Integer a2(9);
    Integer b2(7);
    
    // without operator overloading
    Integer c2 = a2.add(b2);

    // operator overloading working fine
    Integer d2 = a2 + b2;

    
    cout <<"\n\nInteger  " <<c2.print() <<endl;
    cout <<"Integer OPERATOR " <<d2.print() <<endl;

    

    return 0;
}