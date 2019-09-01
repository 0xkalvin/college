#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long fatorial(int n){
    long long fat = 1;
    for(int i = 1; i < n + 1; i++)  fat *= i;
    return fat;
}

/*

    Taylor expansion for e^x

    n -> number of terms
    x -> expoent
*/
long double taylorExpansion(int n, double x){
    long double convergeTo = 0;

    for(int i = 0; i < n; i++){
        convergeTo += pow(x, i)/fatorial(i);
    }

    return convergeTo;

}

long double taylorExpansionInPureC(int n, double x){
    long double convergeTo = 0;
    long long int fatorial = 1;
    long double potencia = 1;
    for(int i = 1; i < n + 1; i++){
        convergeTo += potencia/fatorial;
        fatorial = fatorial * i;
        potencia *= x;
    }
    return convergeTo;
}



int main(){

    int n = 10;
    double x = 3;

    double convergeTo = taylorExpansion(n, x);
    double convergeTo2 = taylorExpansionInPureC(n, x);
    
    printf("\nConverge to  %lf \n", convergeTo);
    printf("Converge to  %lf \n", convergeTo2);


    return 0;
}
