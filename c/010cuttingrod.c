#include <stdio.h>
#include <stdlib.h>



#define MAX(x, y) (((x) > (y)) ? (x) : (y))



int cuttingRodNaive(int price[], int n){

    if(n <= 0){
        return 0;
    }

    int maxValue = -1;

    for(int i = 0; i < n; i++){
        maxValue = MAX(maxValue, price[i] + cuttingRodNaive(price, n - i - 1));
    }

    return maxValue;
}


int cuttingRodDynamic(int price[], int n) 
{ 
   int val[n+1]; 
   val[0] = 0; 
   int i, j; 
  

   for (i = 1; i<=n; i++) 
   { 
       int max_val = -1; 
       for (j = 0; j < i; j++) 
         max_val = MAX(max_val, price[j] + val[i-j-1]); 
       val[i] = max_val; 
   } 
  
   return val[n]; 
} 

int main(){

    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20}; 
    int size = sizeof(arr)/sizeof(arr[0]); 


    printf("NAIVE : %d \n", cuttingRodNaive(arr, size)); 

    printf("DYNAMIC : %d \n", cuttingRodDynamic(arr, size)); 
    

    return 0;
}