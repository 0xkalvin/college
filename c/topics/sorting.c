#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

int *createArray(int size)
{
    srand(time(NULL));
    int *array = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 10000;
    }
    return array;
}

void printArray(int *array, int size)
{
    printf(" [");
    for (int i = 0; i < size; i++)
    {
        if (i == size - 1)
            printf(" %d", array[i]);
        else
            printf(" %d,", array[i]);
    }
    printf(" ]\n");
}

double speedTest(clock_t start, clock_t end){
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

int *bubbleSort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return array;
}

int *selectionSort(int array[], int size){
    int min;
    for(int i = 0; i < size; i++){
        min = i;
        for(int j = i + 1; j < size; j++){
            if(array[min] > array[j]){
                min = j;
            }
        }
        int temp = array[min];
        array[min] = array[i];
        array[i] = temp;
    }

    return array;
}

int *inserctionSort(int array[], int size){

    for(int i = 1; i < size; i++){
        int key = array[i];
        int j = i - 1;
        // j is always less than i
        while( j >= 0 && key < array[j]){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }

    return array;
}

int *mergeSort(int array[], int size){
    
    return array;
}
void menuAnalysis()
{
    int choice;
    while (true){
        printf("\n---------SORTING ALGORITHM------------\n");
        printf("0 - EXIT\n");
        printf("1 - BUBBLE SORT\n");
        printf("2 - SELECTION SORT\n");
        printf("3 - INSERCTION SORT\n");
        printf("4 - MERGE SORT\n\n");
        printf("Please, select an option 0-4 \n");

        scanf("%d", &choice);

        if (choice == 0)
        {
            break;
        }
        else if (choice == 1)
        {
            int size;
            printf("\n\nInsert the size of the array\n");
            scanf("%d",&size);
            system("clear");
            int *array = createArray(size);

            printf(" DESORDED ARRAY: \n");
            printArray(array, size);

            clock_t start = clock();
            array = bubbleSort(array, size);
            clock_t end =  clock();

            printf(" SORTED ARRAY: \n");
            printArray(array, size);

            double result = speedTest(start, end);
            printf("\n BUBBLE SORT: THE TIME TAKEN WAS %f SECONDS \n\n", result);

        }
        else if(choice == 2)
        {
            int size;
            printf("\n\nInsert the size of the array\n");
            scanf("%d",&size);
            system("clear");
            int *array = createArray(size);

            printf(" DESORDED ARRAY: \n");
            printArray(array, size);

            clock_t start = clock();
            array = selectionSort(array, size);
            clock_t end =  clock();

            printf(" SORTED ARRAY: \n");
            printArray(array, size);

            double result = speedTest(start, end);
            printf("\n SELECTION SORT: THE TIME TAKEN WAS %f SECONDS \n\n", result);
        }
        else if(choice == 3)
        {
            int size;
            printf("\n\nInsert the size of the array\n");
            scanf("%d",&size);
            system("clear");
            int *array = createArray(size);

            printf(" DESORDED ARRAY: \n");
            printArray(array, size);

            clock_t start = clock();
            array = inserctionSort(array, size);
            clock_t end =  clock();

            printf(" SORTED ARRAY: \n");
            printArray(array, size);

            double result = speedTest(start, end);
            printf("\n INSERCTION SORT: THE TIME TAKEN WAS %f SECONDS \n\n", result);
        }
    };
}

int main()
{

    menuAnalysis(); 


    return 0;
}