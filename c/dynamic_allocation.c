#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int **create_matrix(int lines, int collums)
{
    srand(time(NULL));
    int **m = malloc(lines * sizeof(int *));
    for (int i = 0; i < lines; i++)
    {
        m[i] = malloc(collums * sizeof(int));
        for (int j = 0; j < collums; j++)
        {
            m[i][j] = rand() % 200;
        }
    }

    return m;
}

void print_matrix(int **m, int lines, int collums)
{
    printf("------------- MATRIX ------- \n\n");
    
    // HEADER
    printf("   ");
    for(int i = 0; i < collums; i++){
        printf(" %3d", i+1);
    }
    printf("\n");
    printf("   ");
    for(int i = 0; i < collums; i++){
        printf("   -");
    }
    
    printf("\n");

    // actually printing matrix elements
    for(int i = 0; i < lines; i++)
    {
        printf(" %2d|", i+1);  // SIDE ELEMENTS
        for (int j = 0; j < collums; j++)
        {
            printf(" %3d", m[i][j]);
        }
        printf("\n");
    }
}
void free_memory(int **m, int lines)
{
    for (int i = 0; i < lines; i++)
    {
        free(m[i]);
    }
    free(m);

    printf("\n\n---------> MEMORY IS FREE! \n\n");
}

int main() 
{ 
    int **m;
    int lines = 5;
    int collums = 7;

    m = create_matrix(lines, collums);
    print_matrix(m,lines, collums);
    free_memory(m,lines);

   return 0; 
} 