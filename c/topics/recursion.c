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

int mdc(int a, int b){
    if(b == 0) return a;
    else return mdc(b, a % b);
}


void decimalToBinary(int n){
    if(n == 0) return;
    else{
        decimalToBinary(n/2);
        printf(" %d", n % 2);
    }
}

// void invertArray(int array[], int start, int end){
//     if(start = end ) return;
//     else{
//         int temp = array[end];
//         array[end] = array[end - start];
//         array[start] = temp;
//         return invertArray(array,start+1, end-1);
//     }
// }

int arrangement(int n, int p){
    return fatorial(n)/fatorial(n-p);
}

int combination(int n, int p){
    return fatorial(n)/(fatorial(p)*fatorial(n-p));
}

void pascalTriangle(int n){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= i; j++){
            int c = combination(i, j);
            printf(" %3d ", c);
        }
        printf("\n");
    }
}

int main(){

    int array[] = {1,2,3,4,5,6};

    pascalTriangle(10);

    return 0;
}