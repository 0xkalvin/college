#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
  return a > b ? a : b;
}

int naiveKnapsack(int capacity, int weigths[], int values[], int n)
{

  if (n == 0 || capacity == 0)
    return 0;

  if (weigths[n - 1] > capacity)
    return naiveKnapsack(capacity, weigths, values, n - 1);

  else
    return max(values[n - 1] + naiveKnapsack(capacity - weigths[n - 1], weigths, values, n - 1),
                  naiveKnapsack(capacity, weigths, values, n - 1));
}

int main()
{
  int values[] = {10, 20, 30};
  int weigths[] = {5, 15, 25};
  int capacity = 40;
  int n = sizeof(values) / sizeof(values[0]);

  printf("max value in knapsack is %d \n", naiveKnapsack(capacity, weigths, values, n));

  return 0;
}