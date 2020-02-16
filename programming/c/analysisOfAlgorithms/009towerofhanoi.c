#include <stdio.h>
#include <stdlib.h>


/*
    (2 ^ n) - 1

    n = 3 -> 8 - 1 = 7
    n = 4 -> 16 - 1 = 15
    n = 5 -> 32 - 1 = 31
*/
void tower(int n, char source, char auxilary, char destination){
    if (n == 1){
        printf("\t\tMove disk %d source %c destination %c\n", n, source, destination);
        return;
    }
    else{
        tower(n - 1, source, destination, auxilary);
        printf("\t\tMove disk %d source %c destination %c\n", n, source, destination);
        tower(n - 1, auxilary, source, destination);
    }
}

int main(){

    int n = 3;
    printf("\t\tTOWER OF HANOI \n");
    tower(n, 'A', 'B', 'C');

    return 0;
}
