#include <stdio.h>
#include <stdlib.h>

/* Imperative paradigm - Calculator exercise */

typedef struct fraction {
    int d;
    int n;
} fraction;

void printFraction(fraction a);
fraction simplify(fraction a);


int equal(fraction a, fraction b){
    return a.n * b.d == a.d * b.n;
}

fraction add(fraction a, fraction b){
    fraction sum;
    sum.d = a.d * b.d;
    sum.n = (a.n * b.d ) + (a.d * b.n);
    return simplify(sum);
}

fraction mult(fraction a, fraction b){
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

    char operation;
    fraction a, b;

    printf("Enter the first fraction (e.g. 1/2)\n");
    scanf("%d/%d", &a.n, &a.d);
    printf("Enter the second fraction\n");
    scanf("%d/%d", &b.n, &b.d);

    printf("Select an operator (+ * / =)\n");
    scanf(" %c",&operation);

    switch (operation)
    {
    case '+':
        printFraction(add(a,b));
        break;
    case '*':
        printFraction(mult(a,b));
        break;
    case '/':
        printFraction(divi(a,b));
        break;
    case '=':
        printf(equal(a,b) ? "True\n" : "False\n");
        break;
    
    default:
        printf("No valid operation was chosen\n");
        break;
    }

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