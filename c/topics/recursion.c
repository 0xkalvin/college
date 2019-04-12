#include <stdio.h>
#include <stdlib.h>

int somaIntervalo(int start,int end){
    if(end < start) return 0;
    else return end + somaIntervalo(start, end-1);
}

int arraySoma(int array[], int size){
    if(size == 0) return 0;
    else return array[size-1] + arraySoma(array, size-1);
}

int fibonacci(int n){
    if(n<=1) return n;
    else return fibonacci(n-1) + fibonacci(n-2);
}

int fatorial(int n){
    if(n == 0) return 1;
    else return n*fatorial(n-1);
}

void printArray(int array[], int size, int i){
    if(i >= size) return;
    else{
        printf(" %d", array[i]);
        printArray(array, size, i+1);
    }
}

int binarySearch(int array[], int n, int start, int end){
    if(start > end) return -1;
    else{
        int mid = (start + end)/2;
        if(array[mid] == n) return mid;
        else if(array[mid] > n) return binarySearch(array, n, start, mid-1);
        else return binarySearch(array, n, mid+1, end);
    }
}


int powerOf(int x, int y){
    if(y == 0) return 1;
    else return x*powerOf(x, y-1);
}


int main(){

    printf(" %d", somaIntervalo(0,4));
    printf(" %d \n", fatorial(4));

    int array[] = {1,2,3};

    printf(" %d ", arraySoma(array, 3));


    return 0;
}