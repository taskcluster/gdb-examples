#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include "programmer/actions/index.h"
#include "globals.h"

void eat_sushi(int id, sem_t *eating, sem_t *left_chopstick, sem_t *right_chopstick) {
  printf("Programmer %i of %i team is waiting for his turn to eat sushi.\n", id, pid);
  sem_wait(eating);
  printf("Programmer %i of %i team is waiting for the left chopstick.\n", id, pid);
  sem_wait(left_chopstick);
  printf("Programmer %i of %i team is waiting for the right chopstick.\n", id, pid);
  sem_wait(right_chopstick);
  printf("Programmer %i of %i team is eating sushi.\n", id, pid);
  sleep(rand() % 5);
  printf("Programmer %i of %i team finished eating sushi.\n", id, pid);
  sem_post(right_chopstick);
  sem_post(left_chopstick);
  sem_post(eating);
}
