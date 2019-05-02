#include "dll.cpp"

using namespace std;

int main(){


    Dll<int> arr1;


    arr1.insertFirst(10);
    arr1.insertFirst(20);
    arr1.insertFirst(30);
    arr1.insertLast(100);
    
    cout << "Doubly Linked list :" <<endl;
    arr1.print();


    arr1.removeFirst();
    arr1.removeLast();


    arr1.print();


    return 0;
}