#include <stdio.h>
#include <stdlib.h>


void exercise3(int n){

    if(n % 2 == 0){
        printf("\nNumber must be odd\n");
        return;
    }

    int counter = 0;
    
    while(counter < n){
        /*  Print spaces before each line   */
        for(int i = 0; i < counter; i++){
            printf(" ");
        }

        for(int i = counter; i < n - counter; i++){
            printf("%d", i + 1);
        }
        
        printf("\n");
        counter++;
    }

}

int main(void){

    exercise3(9);

    return 0;
}