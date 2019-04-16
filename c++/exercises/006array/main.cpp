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

    for(int i = 0; i < v1.getSize(); i++){
        cout << v1.getElement(i) <<endl;
    }

    v1.print();
    


    return 0;
}