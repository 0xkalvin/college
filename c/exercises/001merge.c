#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int tam);

int *intercala(int vetor1[], int vetor2[], int tam1, int tam2)
{
    // TAMANHO DO VETOR RESPOSTA
    int tam = tam1 + tam2;

    // CRIA VETOR AUXILIAR
    int *vetorAux = malloc(tam * sizeof(int));
    for (int i = 0; i < tam; i++)   vetorAux[i] = i < tam1 ? vetor1[i] : vetor2[i - tam1];

    // VETOR RESPOSTA
    int *resultado = malloc(tam * sizeof(int));
    for (int i = 0; i < tam; i++)   resultado[i] = i;
    
    // INTERCALANDO VETOR1 E VETOR2 
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < tam1 && j < tam2) resultado[k++] = vetor1[i] < vetor2[j] ? vetor1[i++] : vetor2[j++];
    while (i < tam1) resultado[k++] = vetor1[i++]; 
    while (j < tam2) resultado[k++] = vetor2[j++];

    return resultado;
}


// n (arraySize) = end - start + 1
// start = 0
// end = n - 1
// mid = (start + end) / 2
void merge(int array[], int start, int mid, int end){
    // set sizes for both arrays
    int n1 = mid - start + 1; 
    int n2 = end - mid;
    // create left and right array;
    int left[n1];
    int right[n2];
    
    int i, j, k;
    // fill both arrays 
    for(i = 0; i < n1; i++) left[i] = array[start + i];
    for(j = 0; j < n2; j++) right[j] = array[mid + 1 + j];

    i = 0;
    j = 0; 
    for(k = start; k < end; k++){
        if(left[i] <= right[j]){
            array[k] = left[i];
            i++;
        }
        else{
            array[k] = right[j];
            j++;
        }
    }
}

int main()
{

    int array[] = {10, 20, 30, 40, 50, 11, 21, 31, 41, 51};
    int start = 0;
    int end = sizeof(array)/sizeof(array[0]) - 1;
    int mid = (start + end) / 2;

    printArray(array, 10);

    merge(array, start, mid, end);

    printArray(array, 10);

    return 0;
}

void printArray(int *array, int tam)
{
    printf(" [");
    for (int i = 0; i < tam; i++)   printf(" %2d", array[i]);
    printf(" ]");
    printf("\n\n");
}
