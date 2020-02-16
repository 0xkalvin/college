#include "dll.cpp"

using namespace std;

int main(){
    Dll<int> arr1;

    arr1.insertFirst(40);
    arr1.insertFirst(10);
    arr1.insertFirst(20);
    arr1.insertFirst(30);
    arr1.insertLast(100);
    arr1.insertAt(99,0);

    cout << "Doubly Linked List :" <<endl;
    arr1.print();

    arr1.removeFirst();
    arr1.removeLast();
    arr1.exchangeEdge();

    arr1.print();

    for(int i = 0; i < arr1.getSize(); i++){
        arr1[i] = i*i;
    }

    arr1.print();

    arr1.invert();


    arr1.print();

    return 0;
}