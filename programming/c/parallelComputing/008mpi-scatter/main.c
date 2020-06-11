#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#define N 100

float* build_dataset(int n);
float get_max_element_in_range(float *dataset, int n);

int main(int argc, char *argv[]){

    MPI_Init(&argc, &argv);
    int size, rank;

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    float global_max;
    float *dataset = build_dataset(N * size);
    float *local_piece = (float*)malloc(N * sizeof(float));
    
    MPI_Scatter(dataset, N, MPI_FLOAT, local_piece, N, MPI_INT, 0, MPI_COMM_WORLD);

    float local_max = get_max_element_in_range(local_piece, N);

    MPI_Reduce(&local_max, &global_max, 1, MPI_FLOAT, MPI_MAX, 0, MPI_COMM_WORLD);
    
    if(rank == 0){
        printf("The max element in the dataset is %f \n", global_max);
    }

    MPI_Finalize();
    free(dataset);

    return 0;
}

float* build_dataset(int n){
    float* dataset = (float*)malloc(n * sizeof(float));
    for(int i = 0; i < n; i++){
        dataset[i] = i;
    }
    return dataset;
}
float get_max_element_in_range(float *dataset, int n){
    float max = dataset[0];
    for(int i = 0; i < n; i++){
        if(dataset[i] > max){
            max = dataset[i];
        }
    }
    return max;
}