#include <stdio.h>
#include <stdlib.h>

int binary_search(int array[], int start, int end, int n){
    if(start > end) return -1;
    else{
        int mid = (start+end)/2;
        if(n == array[mid]) return mid;
        else if(array[mid] > n) return binary_search(array, start, mid - 1, n);
        else return binary_search(array, mid+1, end, n);
    }

}

int main(){

    int array[] = {1,2,3,4,5,6,7,8,9,10};
    printf("enter the number\n");
    int x;
    scanf("%d", &x);
    printf(" %d ", binary_search(array, 0,10, x));

    return 0;
}