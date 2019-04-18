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
    naturalArray.insert(n1, 0);
    naturalArray.insert(n2, 1);
    cout << "Natural Array"<<endl;
    naturalArray.print();

    //  INTEIROS
    Array<Integer> integerArray(2);
    Integer i1(-22);
    Integer i2(123);
    integerArray.insert(i1, 0);
    integerArray.insert(i2, 1);
    cout << "Integer Array"<<endl;
    integerArray.print();

    // RACIONAIS
    Array<Rational> rationalArray(2);
    Rational rat1(-2,5);
    Rational rat2(1,3);
    rationalArray.insert(rat1, 0);
    rationalArray.insert(rat2, 1);
    cout << "Rational Array"<<endl;
    rationalArray.print();

    // REAIS
    Array<Real> realArray(2);
    Real r1(-2.6);
    Real r2(1);
    realArray.insert(r1, 0);
    realArray.insert(r2, 1);
    cout << "Real Array"<<endl;
    realArray.print();

    // COMPLEXOS
    Array<Complex> complexArray(2);
    Complex c1(-2,5);
    Complex c2(1,3);
    complexArray.insert(c1, 0);
    complexArray.insert(c2, 1);
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