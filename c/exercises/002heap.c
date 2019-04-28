#include <stdio.h>
#include <stdlib.h>

void printa_vetor(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf(" %d", arr[i]);
    printf("\n\n");
}

void afunda(int vetor[], int n)
{
    int i, j, item;
    j = 0;
   
    // pega primeiro elemento do vetor
    item = vetor[j];
    
    // filhos do lado esquerdo
    i = 2 * j + 1;
    
    // verifica se o elemento está dentro do vetor  
    while (i <= n - 1)
    {
        // verifica se o sucessor também está dentro do vetor
        if (i + 1 <= n - 1)
            if (vetor[i] < vetor[i + 1])
                i++;
        
        // se o elemento filho for maior do que o pai, eles sao atualizados
        if (item < vetor[i])
        {
            vetor[j] = vetor[i];
            j = i;
            i = 2 * j + 1;
        }
        else
            break;
    }
    vetor[j] = item;
}

int main()
{

    int arr[] = {10, 9, 89, 7, 6};

    printa_vetor(arr, 5);

    afunda(arr, 5);

    printa_vetor(arr, 5);

    return 0;
}