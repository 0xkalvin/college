#include "006countingsort.c"

int maiorElemento(int array[], int size);


void radixSort(int array[], int size){
    int max = maiorElemento(array, size);

    for(int digit = 1; max/digit > 0; digit *= 10){
        // should be digit
        ordernaPorEnderecamentoDireto(array, max, size);
    }
}



int main(){

    int size = 100;
    int *v = criaVetorAleatorio(size);

    printf("\nVETOR DESORDENADO: \n");
    printaVetor(v,size);
    radixSort(v, size);
    printf("\nVETOR ORDENADO: \n");
    printaVetor(v,size);

    return 0;
}

int maiorElemento(int array[], int size){
    int max = array[0];
    for(int i = 0; i < size; i++)
        if(array[i] > max) max = array[i];
    return max;
}
