#include <stdio.h>
#include <stdlib.h>


typedef struct fraction {
    int d;
    int n;
} fraction;

int gcd(int a, int b);
void printFraction(fraction a);
fraction simplify(fraction a);


fraction add(fraction a, fraction b){
    fraction sum;
    sum.d = a.d * b.d;
    sum.n = (a.n * b.d ) + (a.d * b.n);
    return simplify(sum);
}

fraction mul(fraction a, fraction b){
    fraction r;
    r.d = a.d * b.d;
    r.n = a.n * b.n;
    return r;
}

fraction divi(fraction a, fraction b){
    fraction r;
    r.d = a.d * b.n;
    r.n = a.n * b.d;
    return simplify(r);
}

int main(void){

    fraction a;
    fraction b;
    
    a.n = 1;
    a.d = 2;
    b.n = 1;
    b.d = 4;
    
    printFraction(add(a,b));
    printFraction(mul(a,b));
    printFraction(divi(a,b));

    return 0;
}


void printFraction(fraction a){
    printf("%d / %d \n", a.n, a.d);
}

int gcd(int a, int b){
    int g;
    
    for(int i = 1; i <= a && i <= b; i++){
        if(a % i == 0 && b % i == 0){
            g = i;
        }
    }

    return g;
}

fraction simplify(fraction a){
    int g = gcd(a.d, a.n);
    fraction f;
    f.d = a.d / g;
    f.n = a.n / g;
    return f;
}