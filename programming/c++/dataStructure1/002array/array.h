#define SIZE 10
#include <stdlib.h>
#include <iostream>

using namespace std;



class Array {
    
    private:
        int numbers[SIZE];
    
    public:
        Array();
        void print(int array[]);
        string addElement(int n, int position);
        string deleteElement(int position); 
        string exchangeElementsPosition(int pos1, int pos2);
        string findMaxAndMin();
        void selectionSort();
        void invertArray(int arr[]);
        int *newSortedArray();
        int *getNumbers();
};
