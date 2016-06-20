#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main() {
  int i;
  int token = rand() % 100;

  srand(time(NULL) ^ (getpid()<<16));

  for (i = 0; i < 10; i++) {
    printf("%i child is counting: %i\n", token, i);
    sleep(rand() % 5);
  }

  return 0;
}

