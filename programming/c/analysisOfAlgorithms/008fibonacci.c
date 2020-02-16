#include <stdio.h>
#include <stdlib.h>
#include <time.h>



long long int naiveFibonacci(int n){
    if(n <= 0)  return 0;
    else if(n == 1) return 1;
    else    return naiveFibonacci(n - 1) + naiveFibonacci(n - 2);    
}

long long int dynamicFibonacci(int n){
   long long int array[n + 1];
   
   array[0] = 0;
   array[1] = 1;

   for(int i = 2; i < n + 1; i++){
       array[i] = array[i - 1] + array[i - 2];
   }

   return array[n];
}

int main(){

    int n = 40;

    printf("FIB OF %d\n\n", n);

    printf("DYNAMIC\n");

    clock_t begin2 = clock();

    printf(" %lld ", dynamicFibonacci(n));

    clock_t end2 = clock();

    double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
    printf("\nElapsed: %f seconds\n", time_spent2);

    printf("\n\n");

    printf("NAIVE\n");

    clock_t begin1 = clock();

    printf(" %lld ", naiveFibonacci(n));

    clock_t end1 = clock();

    double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
    printf("\nElapsed: %f seconds\n", time_spent1);






    return 0;
}