#include <stdio.h>
#include <omp.h>

#define N 65536
#define toBeFound 42000

int main(void){

    int array[N];
    int hasFound = 0;

    for(int i = 0; i < N; i++){
        array[i] = i * 2;
    }

    #pragma omp parallel shared(hasFound)
    {
        int tid = omp_get_thread_num();
        int max_num_threads = omp_get_max_threads();

        int start = tid * N/max_num_threads; 
        int end = start + N/max_num_threads;

        printf("Thread %d looking in range [ %d, %d ] ...\n", tid, start, end);

        for(int i = start; i < end; i++){
            if(toBeFound == array[i]){
                printf("FOUND! %d is in index %d, by thread %d \n", toBeFound, i, tid);
                hasFound = 1;
            }
        }

    }

    if(!hasFound){
        printf("%d is not in array! \n", toBeFound);
    }


    return 0;
}