#include "dll.cpp"

using namespace std;

int main(){


    Dll<int> arr1;


    arr1.insertFirst(10);
    arr1.insertFirst(20);
    arr1.insertFirst(30);

    cout << "first element is " << arr1.getFirst() <<endl; 
    cout << "last element is " << arr1.getLast() <<endl; 

    
    cout << "Doubly Linked list :" <<endl;
    arr1.print();


    return 0;
}