#include <stdio.h>

long factorial(int);

int my_global = 10;

int main() {
  long res = factorial(my_global);
  printf("%d! = %ld\n", my_global, res);
  return 0;
}

long factorial(int n) {
  return n == 0 ? 1 : n * factorial(n - 1);
}
