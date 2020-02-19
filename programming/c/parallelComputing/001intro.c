#include <stdio.h>
#include <stdlib.h>

/*
    Exercises:
    http://www.inf.pucrs.br/~pinho/PRGSWB/Exercicios/Introducao/Introducao.html
*/

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

void exercise4(){

    char name1[100], name2[100];

    printf("\nInsert the first name\n");
    scanf("%s", name1);

    printf("\nInsert the second name\n");
    scanf("%s", name2);

    int counter1 = 0, counter2 = 0, i =  0;
    
    while(counter1 == counter2 && i < 100){
        counter1 += name1[i];
        counter2 += name2[i];
        i++;
    }
    
    printf("\nNames in alphabetical order: \n");
    if(counter1 < counter2){
        printf("%s \n%s \n", name1, name2);
    } else {
        printf("%s \n%s \n", name2, name1);
    }
} 


int main(void){

    exercise4();

    return 0;
}