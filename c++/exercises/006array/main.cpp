#include "array.cpp"
#include <iostream>

using namespace std;


int main()
{
    Array<int> v1(5);
    v1.insert(10, 0);
    v1.insert(20, 1);
    v1.insert(30, 2);
    v1.insert(40, 3);
    v1.insert(50, 4);

    Array<int> v2(5);
    v2.insert(1, 0);
    v2.insert(2, 1);
    v2.insert(3, 2);
    v2.insert(4, 3);
    v2.insert(5, 4);


    //Array<int> v3 = v1 + v2;

    for(int i = 0; i < v1.getSize(); i++){
        cout << v1.getElement(i) <<endl;
    }
    


    return 0;
}