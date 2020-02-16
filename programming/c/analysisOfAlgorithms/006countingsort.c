#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printaVetor(int vetor[], int tam);
int *criaVetorAleatorio(int tam);

void ordernaPorEnderecamentoDireto(int vetor[], int maxElem, int tam){
    // cria vetor auxiliar com tamanho maxElem + 1
    // suficientemente grande para gravar todos elementos do vetor
    int *aux = (int*)malloc((maxElem + 1)*sizeof(int));
    int i, j;

    // inicializa todos elementos com zero
    for(i = 0 ; i < maxElem + 1; i++) aux[i] = 0;

    // conta quantas ocorrencias de cada elemento do vetor em cada posicao
    for(i = 0; i < tam; i++)   aux[vetor[i]]++;
    
    i = 0;
    j = 0;
    // percorre vetor auxiliar e quando seu elemento for diferente de 0,
    // posiciona o numero de sua posicao no vetor principal 
    while(i < maxElem + 1){
        if(aux[i] != 0){
            if(aux[i] == 1){
                vetor[j] = i;
                j++;
            } 
            else{
                while(aux[i] >= 1){ // tratamento para elementos repetidos
                    vetor[j] = i;  
                    j++;
                    aux[i]--;
                }
            }  
        }
        i++;
    }
}


// int main(){

//     int v[] = {15, 9, 0, 3, 4, 4, 7, 6, 8, 8};
//     int tam = 100;
//     int maxElem = 100;
//     int *v1 = criaVetorAleatorio(tam);

//     printf("VETOR DESORDENADO: \n");
//     printaVetor(v1, tam);
//     ordernaPorEnderecamentoDireto(v1, maxElem, tam);
//     printf("\nVETOR ORDENADO: \n");
//     printaVetor(v1, tam);

//     return 0;
// }

void printaVetor(int vetor[], int tam)
{
    for (int i = 0; i < tam; i++)
        printf(" %d", vetor[i]);
    printf("\n\n");
}

int *criaVetorAleatorio(int tam){
    int *p =(int*)malloc(tam*sizeof(int));
    srand(time(NULL));
    for(int i = 0; i < tam; i++) p[i] = rand() % 1000;
    return p;
}
