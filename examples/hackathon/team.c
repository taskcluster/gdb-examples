#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include "globals.h"
#include "programmer/index.h"

// Initializing globals.
int bugs_remain, bugs_fixed;
pthread_mutex_t assign_lock, commit_lock;
pid_t pid;

int main() {
  srand(time(0));

  // Assigning globals.
  pid = getpid();
  bugs_remain = BUGS_COUNT;
  bugs_fixed = 0;

  // Initializing locals.
  int i;
  pthread_t programmers[PROGRAMMERS_COUNT];
  sem_t chopsticks[PROGRAMMERS_COUNT];
  sem_t eating;

  // Initializing mutexes and semaphores.
  if (pthread_mutex_init(&assign_lock, 0) != 0 ||
    pthread_mutex_init(&commit_lock, 0) != 0 ||
    sem_init(&eating, 0, PROGRAMMERS_COUNT - 1) != 0) {
    return -1;
  }

  for (i = 0; i < PROGRAMMERS_COUNT; i++) {
    if (sem_init(&(chopsticks[i]), 0, 1) != 0) return -1;
  }

  // Running threads.
  for (i = 0; i < PROGRAMMERS_COUNT; i++) {
    spawn_programmer_args *args = malloc(sizeof(*args));
    args->id = i;
    args->eating = &eating;
    args->left_chopstick = &(chopsticks[i]);
    args->right_chopstick = &(chopsticks[(i + 1) % PROGRAMMERS_COUNT]);
    if (pthread_create(&(programmers[i]), 0, &spawn_programmer, args) != 0) {
      return -1;
    }
  }

  // Waiting for threads to finish.
  for (i = 0; i < PROGRAMMERS_COUNT; i++) {
    pthread_join(programmers[i], 0);
  }

  // Destoying mutexes and semaphores.
  pthread_mutex_destroy(&assign_lock);
  pthread_mutex_destroy(&commit_lock);
  sem_destroy(&eating);

  for (i = 0; i < PROGRAMMERS_COUNT; i++) {
    sem_destroy(&(chopsticks[i]));
  }

  return 0;
}
