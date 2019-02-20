#define SIZE 10
#include <stdlib.h>
#include <iostream>

using namespace std;



class adtArray {
    
    private:
        int numbers[SIZE];
    
    public:
        adtArray();
        void print();
        string addElement(int n, int position);
        string deleteElement(int position); 
        string exchangeElementsPosition(int pos1, int pos2);
        string findMaxAndMin();
        void selection_sort();
        void invert_array(int arr[]);
        int *new_sorted_array();
        int *get_numbers();
};
