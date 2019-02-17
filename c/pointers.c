#include <stdio.h>
int main()
{
   int x;
   x = 10;
   
   // creates a pointer that points to a integer variable
   int *p;

   // now p points to x, which means p stores the value of x
   p = &x;

   //
   printf("%p\n", &p); // pointer address
   printf("%p\n", p); // address stored in p, which is the address of x
   printf("%p\n", &x); // x address
   printf("%d\n", *p); // the value of the address stored in p,  which is the value of x 

   

   return 0;
}