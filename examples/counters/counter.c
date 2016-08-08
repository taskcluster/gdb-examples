#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main() {
  srand(time(0) ^ (getpid()<<16));

  int i;
  pid_t pid = getpid();

  for (i = 0; i < 10; i++) {
    printf("%i child is counting: %i\n", pid, i);
    sleep(rand() % 5);
  }

  return 0;
}

