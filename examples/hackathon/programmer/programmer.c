#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdbool.h>
#include "programmer/actions/index.h"
#include "programmer/index.h"
#include "globals.h"

void* spawn_programmer(void *args) {
  spawn_programmer_args *programmer_args = args;

  // Getting arguments.
  bool done = false;
  int id = programmer_args->id;
  sem_t *eating = programmer_args->eating;
  sem_t *left_chopstick = programmer_args->left_chopstick;
  sem_t *right_chopstick = programmer_args->right_chopstick;

  while (!done) {
    // Assigning a bug.
    pthread_mutex_lock(&assign_lock);

    if (bugs_remain == 0) {
      done = true;
    } else {
      bugs_remain--;
    }

    pthread_mutex_unlock(&assign_lock);

    if (!done) {
      // Doing some work.
      fix_bug(id);
      eat_sushi(id, eating, left_chopstick, right_chopstick);

      // Committing results.
      pthread_mutex_lock(&commit_lock);

      bugs_fixed++;
      printf("%i team fixed %i bugs.\n", pid, bugs_fixed);

      pthread_mutex_unlock(&commit_lock);
    }
  }

  free(programmer_args);

  return 0;
}

