#include "002maxheapify.c"


void buildMaxHeap(int array[], int size){
    int heapSize = size;
    for(int i = size; i > 0; --i){
        maxHeapify(array, i, heapSize);
    }
}

int main()
{

    int arr[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};

    printa_vetor(arr, 10);

    buildMaxHeap(arr, 9);

    printa_vetor(arr, 10);

    return 0;
}

/*
                        16
                14              10
            4       8       9       3
        2       7       1
*/          