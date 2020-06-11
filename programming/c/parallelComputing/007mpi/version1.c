#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

float* build_dataset(int n);
void print_dataset(float *dataset, int n);
float get_max_element_in_range(float *dataset, int start, int end);

int main(int argc, char *argv[]){

    MPI_Init(&argc, &argv);
    int size, rank;

    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    int default_tag = 0;
    float max;
    int n = size * 5;
    float *dataset = build_dataset(n);
    int *indexes = (int*)malloc(2 * sizeof(int));
    
    if(rank == 0){
        char processor_name[MPI_MAX_PROCESSOR_NAME];
        int len;
        MPI_Get_processor_name(processor_name, &len);
        printf("Master %s { pid %d } is running \n", processor_name, getpid());

        for (int destination = 1; destination < size; destination++){
            int start = destination * n/size;
            int end = start + n/size;
            indexes[0] = start;
            indexes[1] = end;
            MPI_Send(indexes, 2, MPI_INT, destination, default_tag, MPI_COMM_WORLD);
        }

        printf("Messages with indexes were successfully sent to all ranks \n");

        int start = 0;
        int end = start + n/size;
        float local_max = get_max_element_in_range(dataset, start, end);
        printf("Master local max { %f } \n", local_max);
        float real_max = local_max;

        for (int destination = 1; destination < size; destination++){
            MPI_Recv(&max, 1, MPI_FLOAT, destination, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            if(max > real_max){
                real_max = max;
            }
        }
        print_dataset(dataset, n);
        printf("The max element in the dataset above is %f ", real_max);
        

    } else {
        printf("Worker %d { pid %d } is running \n", rank, getpid());

        int source = 0;
        int destination = 0;
        MPI_Recv(indexes, 2, MPI_INT, source, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        int start = indexes[0];
        int end = indexes[1];
        max = get_max_element_in_range(dataset, start, end);
        printf("Worker %d local max { %f } \n", rank, max);
        MPI_Send(&max, 1, MPI_FLOAT, destination, default_tag, MPI_COMM_WORLD);

    }

    MPI_Finalize();
    free(dataset);
    free(indexes);

    return 0;
}

float* build_dataset(int n){
    float* dataset = (float*)malloc(n * sizeof(float));
    for(int i = 0; i < n; i++){
        dataset[i] = (i * i)/2;
    }
    return dataset;
}

void print_dataset(float *dataset, int n){
    printf("\n DATASET \n");
    printf("[ ");
    for(int i = 0; i < n; i++){
        printf(" %f ", dataset[i]);
    }
    printf(" ]\n");

}

float get_max_element_in_range(float *dataset, int start, int end){
    float max = dataset[start];
    for(int i = start; i < end; i++){
        if(dataset[i] > max){
            max = dataset[i];
        }
    }
    return max;
}