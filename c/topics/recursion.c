#include <stdio.h>
#include <stdlib.h>

int somaIntervalo(int start,int end){
    if(end < start) return 0;
    else return end + somaIntervalo(start, end-1);
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



int main(){

    printf(" %d", somaIntervalo(0,4));
    printf(" %d \n", fatorial(4));


    return 0;
}