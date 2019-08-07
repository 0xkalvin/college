#include <stdio.h>
#include <stdlib.h>

void printa_vetor(int arr[], int size);
    
void partition2way(int vetor[], int n){
    int maior[n];
    int menor[n];
    int pivot = vetor[0];
    int j, k = 0;
    int i;
   
    for(i = 0; i < n; i++){
        if(vetor[i] < pivot){
            menor[j] = vetor[i];
            j++;
        }
        else if (vetor[i] > pivot){
            maior[k] = vetor[i];
            k++;
        }
    }
    
    int maiorTam = k, menorTam = j;
    k = 0;
    i = 0;

    while(i < menorTam){
      vetor[i] = menor[i];
      i++;
    }
    
    vetor[i] = pivot;
    i++;

    while(k <= maiorTam){
      vetor[i] = maior[k];
      k++;
      i++;
  }
}

int main(){

    int array[] = {4,2,7,6,9,3,8,1,5};

    printa_vetor(array, 9);
    partition2way(array, 9);
    printa_vetor(array, 9);

    return 0;
}


void printa_vetor(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf(" %d", arr[i]);
    printf("\n\n");
}
