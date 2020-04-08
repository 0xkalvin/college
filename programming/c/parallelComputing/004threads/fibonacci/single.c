#include <stdio.h>
#include <stdlib.h>

long long int singleThreadFibonacci(long long int n){

    long long int fib[n + 1];

    fib[0] = 0;
    fib[1] = 1;

    for (long long int i = 2; i <= n; ++i)
    {
        fib[i] = fib[i - 2] + fib[i - 1];
    }

    return fib[n];
}


int main(void){

    const long long int n = 163;

    if(n < 0){
        printf("The fibonacci term should be a non negative integer");
        exit(-1);
    }

    printf("Single thread: the fibonacci of %lli is %lli \n", n, singleThreadFibonacci(n));

    return 0; 
}