#include <stdio.h>
#include <stdlib.h>

void printaVetor(int arr[], int size);

void directAddressing(int arr[], int min, int max, int size){
    int n = max + 1;
    int *p = (int*)malloc(n*sizeof(int));
    
    int i, j;
    for(i = 0 ; i < n; i++) p[i] = 0;

    for(i = 0; i < size; i++)   p[arr[i]]++;
    
    i = 0;
    j = 0;
    while(i < n){
        if(p[i] != 0){
            if(p[i] == 1){
                arr[j] = i;
                j++;
            } 
            else{
                while(p[i] >= 1){
                    arr[j] = i;
                    j++;
                    p[i]--;
                }
            }  
        }
        i++;
    }
}


int main(){

    int array[] = {10, 9, 0, 3, 4, 4, 7, 6, 8, 8};
    int size = 10;

    printaVetor(array, size);
    directAddressing(array, 0, 10, size);
    printaVetor(array, size);

    return 0;
}

void printaVetor(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf(" %d", arr[i]);
    printf("\n\n");
}
