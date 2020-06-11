#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 100
#define DEFAULT_TAG 0

float* build_dataset(int n);
float get_max_element_in_range(float *dataset, int n);

int main(int argc, char *argv[]){

    MPI_Init(&argc, &argv);
    int size, rank;

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if(rank == 0){
        char processor_name[MPI_MAX_PROCESSOR_NAME];
        int len;
        MPI_Get_processor_name(processor_name, &len);
        printf("Master %s { pid %d } is running \n", processor_name, getpid());

        float *dataset = build_dataset(N * size);

        for (int destination = 1; destination < size; destination++){
            MPI_Send(dataset + (N * destination), N, MPI_FLOAT, destination, DEFAULT_TAG, MPI_COMM_WORLD);
        }

        printf("Messages with indexes were successfully sent to all ranks \n");

        float max = get_max_element_in_range(dataset, N);
        printf("Master local max is %f  \n", max);

        float local_max;
        for (int destination = 1; destination < size; destination++){
            MPI_Recv(&local_max, 1, MPI_FLOAT, destination, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            if(local_max > max){
                max = local_max;
            }
        }
        printf("The max element in the dataset is %f ", max);
        free(dataset);        

    } else {
        printf("Worker %d { pid %d } is running \n", rank, getpid());
       
        float *dataset_slice = (float*)malloc(N * sizeof(float));
        MPI_Recv(dataset_slice, N, MPI_FLOAT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        float local_max = get_max_element_in_range(dataset_slice, N);
        printf("Worker %d local max is %f \n", rank, local_max);
        MPI_Send(&local_max, 1, MPI_FLOAT, 0, DEFAULT_TAG, MPI_COMM_WORLD);
        free(dataset_slice);
    }

    MPI_Finalize();

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
    for(int i = 1; i < n; i++){
        if(dataset[i] > max){
            max = dataset[i];
        }
    }
    return max;
}