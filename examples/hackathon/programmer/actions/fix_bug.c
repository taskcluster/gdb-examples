#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "programmer/index.h"
#include "globals.h"

void fix_bug(int id) {
  printf("Programmer %i of %i team is fixing a bug.\n", id, pid);
  sleep(rand() % 5);
  printf("Programmer %i of %i team finished fixing a bug.\n", id, pid);
}
