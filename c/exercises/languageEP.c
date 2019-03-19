#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TXT_MAX_LEN 140


void find_language(char text[TXT_MAX_LEN]){

    char result[TXT_MAX_LEN] = "The language is ";
    strcat(result, text);
    printf("%s", result);
}

int main(){

    char text[TXT_MAX_LEN];

    printf("Write some message\n");
    if(fgets(text, sizeof(text), stdin)){
        find_language(text);
    }
    
    return 0;
}