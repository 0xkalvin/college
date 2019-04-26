#include "linkedlist.cpp"

using namespace std;

int main(){


    LinkedList<int> arr1;


    arr1.insertFirst(10);
    arr1.insertFirst(20);
    arr1.insertFirst(30);


    arr1.print();
    cout << "first element is " << arr1.getFirst() <<endl; 
    cout << "last element is " << arr1.getLast() <<endl; 

    arr1.removeFirst();
    arr1.insertLast(1);
    arr1.insertLast(2);
    
    arr1.print();

    return 0;
}