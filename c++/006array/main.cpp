#include "array.cpp"
#include "../004inheritance/real.h"
#include "../003classes/natural.h"
#include "../003classes/integer.h"
#include "../003classes/rational.h"

using namespace std;

void exercise1(){

    // NATURAIS
    Array<Natural> naturalArray(2);
    Natural n1(666);
    Natural n2(1000);
    naturalArray[0] = n1;
    naturalArray[1] = n2;
    cout << "Natural Array"<<endl;
    naturalArray.print();

    //  INTEIROS
    Array<Integer> integerArray(2);
    Integer i1(-22);
    Integer i2(123);
    integerArray[0] = i1;
    integerArray[1] = i2;
    cout << "Integer Array"<<endl;
    integerArray.print();

    // RACIONAIS
    Array<Rational> rationalArray(2);
    Rational rat1(-2,5);
    Rational rat2(1,3);
    rationalArray[0] = rat1;
    rationalArray[1] = rat2;
    cout << "Rational Array"<<endl;
    rationalArray.print();

    // REAIS
    Array<Real> realArray(2);
    Real r1(-2.6);
    Real r2(1);
    realArray[0] = r1;
    realArray[0] = r2;
    cout << "Real Array"<<endl;
    realArray.print();

    // COMPLEXOS
    Array<Complex> complexArray(2);
    Complex c1(-2,5);
    Complex c2(1,3);
    complexArray[0] = c1;
    complexArray[1] = c2;
    cout << "Complex Array"<<endl;
    complexArray.print();

}


void exercise2(){
    Array<int> v1(5);
    Array<int> v2(3);

    v1[0] = 10;
    v1[1] = 20;
    v1[2] = 30;
    v1[3] = 40;
    v1[4] = 50;

    v2[0] = 111;
    v2[1] = 222;
    v2[2] = 333;

    cout << "Array 1"<<endl;
    v1.print();
    cout << "Array 2"<<endl;
    v2.print();
    cout << "Concat array 1 and array 2"<<endl;
    v1.concat(v2).print();

}


int main()
{
 
    exercise1();

    exercise2();


    return 0;
}