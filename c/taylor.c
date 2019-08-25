#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long fatorial(int n){
    if (n <= 0) return 1;
    else    return n * fatorial(n - 1);
}

/*

    Taylor expansion for e^x

    n -> number of terms
    x -> expoent
*/
double taylorExpansion(int n, double x){
    double convergeTo = 0;

    for(int i = 0; i < n; i++){
        convergeTo += pow(x, i)/fatorial(i);
    }

    return convergeTo;

}


int main(){

    int n = 20;
    double x = 2;

    double convergeTo = taylorExpansion(n, x);
    
    printf("Converge to  %g\n", convergeTo);


    return 0;
}
