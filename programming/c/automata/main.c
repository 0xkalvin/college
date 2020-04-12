#include <stdio.h>

#define MAX_LEN_WORDS 100



int getWordsLength(char words[MAX_LEN_WORDS]){
    int counter = 0;
    
    while(words[counter] != '\0') {
        counter++;
    }
    
    return counter;
}


void processWords(char words[MAX_LEN_WORDS]){

    FILE *file;
    file = fopen("result.txt", "w");

    int finalState = 0;
    int i = 0;
    int size = getWordsLength(words);
    char c = words[0];

    while(i < size){
        back:            
            c = words[i];
           
            q0:
                c = words[i];
                finalState = 0;
                if(c >= 48 && c <= 57){
                    i++;
                    goto q6;
                } else if(c == 43 || c == 45){
                    i++;
                    goto q1;
                } else if(c == 32){
                    i++;
                    goto q0;
                } else  {
                    goto q4;
                }

            q1:
                c = words[i];
                finalState = 1;
                if(c >= 48 && c <= 57){
                    i++;
                    goto q5;
                } else  {
                    goto q4;
                }

            q2:
                c = words[i];
                finalState = 2;
                if(c >= 48 && c <= 57){
                    i++;
                    goto q2;
                } else if(c == 32 || c == '\0'){
                    i++;
                    goto printWord;
                } else  {
                    goto q4;
                }
            q3:
                c = words[i];
                finalState = 3;
                if(c >= 48 && c <= 57){
                    i++;
                    goto q2;
                } else  {
                    goto q4;
                }
            q4:
                c = words[i];
                i++;
                finalState = 4;
                goto printWord;
                
            q5:
                c = words[i];
                finalState = 5;
                if(c >= 48 && c <= 57){
                    i++;
                    goto q5;
                } else if(c == 44 || c == 46){
                    i++;
                    goto q3;
                } else if(c == 32 || c == '\0'){
                    i++;
                    goto printWord;
                } else  {
                    goto q4;
                }
            
            q6:
                c = words[i];
                finalState = 6;
                if(c >= 48 && c <= 57){
                    i++;
                    goto q6;
                } else if(c == 44 || c == 46){
                    i++;
                    goto q3;
                } else if(c == 32 || c == '\0'){
                    i++;
                    goto printWord;
                } else  {
                    goto q4;
                }

            
            printWord:

                if(finalState == 4){
                    printf("ERROR\n");
                    fprintf(file, "ERROR\n");
                    
                    while(c != 32 && c != '\0'){
                            i++;
                            c = words[i];
                    }

                } else if(finalState == 5 || finalState == 6){
                    printf("INTEGER\n");
                    fprintf(file,"INTEGER\n");
                } else if(finalState == 2){
                    printf("FLOATING POINT\n");       
                    fprintf(file,"FLOATING POINT\n");
                }  
                
                if(c == '\0'){ 
                    break;
                }
                goto back;
    }

    fclose(file);
}

int main(){

    char words[MAX_LEN_WORDS] = "-21 +45.67 0.123 .456 42 23. xx";
    processWords(words);

    return 0;
}