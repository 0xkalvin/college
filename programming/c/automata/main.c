/*Kalvin 31894666
  Roger  31849571
  Wendel 31811957 */

#include <stdio.h>
#define MAX_INPUT_LEN 200

void scanner(char word[MAX_INPUT_LEN])
{
    FILE * fp;
    int wordSize = MAX_INPUT_LEN;
    int notAccepted = 0;
    int finalState = 0;
    int i = 0;
    fp = fopen("result.txt", "w");
    char c;
   
    while (i < wordSize)
    {
    goback:

        c = word[i];

    q0:
        c = word[i];
        finalState = 0;

        if (c >= 48 && c <= 57)
        {
            i++;
            goto q6;
        }
        else if (c == 43 || c == 45)
        {
            i++;
            goto q1;
        }
        else if (c == 32)
        {
            i++;
            finalState = 0;
            goto whitespace;
        }
        else if (c == '\0')
        {
            finalState = 0;
            break;
        }
        else
        {
            goto q4;
        }

    q1:
        c = word[i];

        if (c >= 48 && c <= 57)
        {
            i++;
            goto q5;
        }
        else if (c == '\0')
        {
            finalState = 1;
            break;
        }
        else if (c == 32)
        {
            i++;
            finalState = 1;

            goto whitespace;
        }
        else
            goto q4;

    q2:
        c = word[i];

        if (c >= 48 && c <= 57)
        {
            i++;
            goto q2;
        }
        else if (c == '\0')
        {
            finalState = 2;
            break;
        }
                else if (c == 32)
        {
            i++;
            finalState = 2;

            goto whitespace;
        }
        else
            goto q4;
    q3:
        c = word[i];

        if (c >= 48 && c <= 57)
        {
            i++;
            goto q2;
        }
        else if (c == '\0')
        {
            finalState = 3;
            break;
        }
        else if (c == 32)
        {
            i++;
            finalState = 3;

            goto whitespace;
        }

        else
            goto q4;

    q4:
        i++;
        notAccepted = 1;
        finalState = 4;
        goto whitespace;

    q5:
        c = word[i];

        if (c >= 48 && c <= 57)
        {
            i++;
            goto q5;
        }
        else if (c == 44 || c == 46)
        {
            i++;
            goto q3;
        }
        else if (c == '\0')
        {
            finalState = 5;
            break;
        }
        else if (c == 32)
        {
            i++;
            finalState = 5;

            goto whitespace;
        }
        else
            goto q4;
    q6:
        c = word[i];

        if (c >= 48 && c <= 57)
        {
            i++;
            goto q6;
        }
        else if (c == 44 || c == 46)
        {
            i++;
            goto q3;
        }
        else if (c == 32)
        {
            i++;
            finalState = 6;
            goto whitespace;
        }
        else if (c == '\0')
        {
            finalState = 6;
            break;
        }

        else
            goto q4;

    
    whitespace:
        if (notAccepted)
        {
            printf("Error\n");
            fprintf(fp, "ERRO\n");
        }

        if (finalState == 6 || finalState == 5)
        {
            printf("INTEIRO\n");
            fprintf(fp, "<NUMERO INTEIRO>\n");
        }
        else if (finalState == 2)
        {
            printf("PONTO FLUTUANTE\n");
            fprintf(fp, "<NUMERO COM PONTO FLUTUANTE>\n");
        }
        fclose(fp);
        if(c != '\0')   goto goback;
    }
}

int main(void)
{

    char word[MAX_INPUT_LEN] = "-21 +45.67 0.123 .456 42 23. xx";

    scanner(word);

    return 0;
}