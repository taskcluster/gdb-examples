/**
 * This is just a simple example of recursion.
 * It has a simple implementation and a tail call optimization.
 * It's also possible to pass parameters to it through CLI.
 */


#include <stdlib.h>
#include <stdio.h>

#define NUM 10

long factorial(int);
long factorial_tail_call(int, int);

int main(int argc, char **argv) {
  int num = argc > 1 ? atoi(argv[1]) : NUM;
  printf("%d! = %ld (simple)\n", num, factorial(num));
  printf("%d! = %ld (tail call)\n", num, factorial_tail_call(1, num));
  return 0;
}

long factorial(int n) {
  return n == 0 ? 1 : n * factorial(n - 1);
}

long factorial_tail_call(int acc, int n) {
  return n == 0 ? acc : factorial_tail_call(n * acc, n - 1);
}
