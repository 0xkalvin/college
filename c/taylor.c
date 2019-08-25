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


int main(){

    int n = 50;
    double x = 2;

    double convergeTo = taylorExpansion(n, x);
    
    printf("Converge to  %lf \n", convergeTo);


    return 0;
}
