#include <stdio.h>
#include <stdlib.h>

void printa_vetor(int arr[], int size);

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    
    for(int j = low + 1; j <= high; j++){
      if(arr[j] <= pivot){
        i++;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    
    int temp = arr[low];
    arr[low] = arr[i];
    arr[i] = temp;
    return i;
}


void quickSort(int arr[], int low, int high){
    if(low < high){
        int x = partition(arr, low, high);
        quickSort(arr, low, x - 1);
        quickSort(arr, x + 1, high);
    }
}


int main(){

    int array[] = {4,2,7,6,9,3,8,1,5};

    printa_vetor(array, 9);
    quickSort(array, 0, 9);
    printa_vetor(array, 9);

    return 0;
}


void printa_vetor(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf(" %d", arr[i]);
    printf("\n\n");
}