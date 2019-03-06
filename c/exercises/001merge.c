#include <stdio.h>
#include <stdlib.h>

// a1 = 1,5,6
// a2 =  2, 123, 1000
// a3 = 1, 2, 5, 6, 123, 1000

void printArray(int *array, int tam)
{
    printf(" [");
    for (int i = 0; i < tam; i++)
    {
        printf(" %2d", array[i]);
    }
    printf(" ]");
    printf("\n\n");
}

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

int main()
{
    
    int vetor1[] = {0,10, 20, 30, 40, 50};
    int vetor2[] = {11, 21, 31, 41, 51};

    int *vetorIntercalado;
    vetorIntercalado = intercala(vetor1, vetor2, 5, 5);
    printArray(vetorIntercalado, 10);

    return 0;
}