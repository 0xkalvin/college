#include <stdio.h>
#include <stdlib.h>

void printa_vetor(int arr[], int size);

// afunda
void maxHeapify(int array[], int index, int size){
    int left = 2*index;         // LEFT CHILD
    int right = 2*index + 1;    // RIGHT CHILD
    int largest;

    if(left <= size && array[left] > array[index]) largest = left;
    else largest = index;

    if(right <= size && array[right] > array[index]) largest = right;

    if(largest != index){
        int temp = array[index];
        array[index] = array[largest];
        array[largest] = temp;
        maxHeapify(array, largest, size);
    }
}

int main()
{

    int arr[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};

    printa_vetor(arr, 10);

    maxHeapify(arr, 1, 9);

    printa_vetor(arr, 10);

    return 0;
}

void printa_vetor(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf(" %d", arr[i]);
    printf("\n\n");
}
