#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TXT_MAX_LEN 140


int *count_all_letters(char string[TXT_MAX_LEN]){
    int counter = 0;
    int letter_value = 0;
    int i = 0;

    int *letters_count = malloc(26*sizeof(int));
    for (int j = 0; j < 26; j++) letters_count[j] = 0;
    
    while(string[i] != '\0'){
        
        if(string[i] >= 'a' && string[i] <= 'z'){
            letter_value = string[i] - 'a';
            letters_count[letter_value]++;
        }
        i++;
    }

   return letters_count;
}

void print_frequency(int *arr){
    char a = 'a';
    for(int i = 0; i < 26; i++){
        printf(" %c = %d \n", a, arr[i]);
        a++;
    }
}


void find_language(char text[TXT_MAX_LEN]){

    char result[TXT_MAX_LEN] = "The language is ";
    //strcat(result, text);
    //printf("%s", result);

    int *letters_frequency = count_all_letters(text);
    print_frequency(letters_frequency);
}

int main(){

    char text[TXT_MAX_LEN];

    printf("Write some message\n");
    if(fgets(text, sizeof(text), stdin)){
        find_language(text);
    }
    
    return 0;
}