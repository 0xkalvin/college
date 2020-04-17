#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1073741824

int main(void)
{
    printf("Running version 1 \n");
    long long int *array = (long long int *)(malloc(N * sizeof(long long int)));
    
    for (long long int i = 0; i < N; i++)
    {
        array[i] = 1;
    }
    
    
    long long int max_num_threads = omp_get_max_threads();
    long long int *temp = (long long int *)(malloc(max_num_threads * sizeof(long long int)));

    #pragma omp parallel shared(array, max_num_threads, temp)
    {
        long long int tid = omp_get_thread_num();
        printf("Thread %lli starting... \n", tid);
        
        long long int start = tid * N/max_num_threads; 
        long long int end = start + N/max_num_threads;
        long long int sum = 0;
        
        for (long long int i = start; i < end; i++)
        {
            sum += array[i];
        }

        temp[tid] = sum;
    }

    long long int total = 0;
    for(long long int i = 0; i < max_num_threads; i++){
        total += temp[i];
    }

    printf("The sum of the array is %lli \n", total);

    return 0;
}