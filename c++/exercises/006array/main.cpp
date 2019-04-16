#include "array.cpp"
#include <iostream>

using namespace std;


int main()
{
    Array<int> v1(5);
    Array<int> v2(3);

    v1.insert(10, 0);
    v1.insert(20, 1);
    v1.insert(30, 2);
    v1.insert(40, 3);
    v1.insert(50, 4);
 
    v2.insert(1, 0);
    v2.insert(2, 1);
    v2.insert(3, 2);


    v1.print();
    v2.print();

    v1.concat(v2).print();

    return 0;
}