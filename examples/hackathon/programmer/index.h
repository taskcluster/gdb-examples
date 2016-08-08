#ifndef programmer
#define programmer

#include <semaphore.h>

typedef struct {
  int id;
  sem_t *eating;
  sem_t *left_chopstick;
  sem_t *right_chopstick;
} spawn_programmer_args;

void* spawn_programmer(void *args);

#endif
