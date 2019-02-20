#include <stdlib.h>
#include <iostream>
#include "integer.h"
#include "natural.h"

using namespace std;

int main()
{
    Integer a(10);
    int y = 5;
    Integer b = a.multiply(y);

    Natural n(10);
    int x = 10;
    Natural m = n.multiply(x);

    cout <<"INTEGER " <<b.print() <<endl;
    cout <<"NATURAL " <<m.print() <<endl;

    

    return 0;
}