#ifndef actions
#define actions

#include <semaphore.h>

void eat_sushi(int id, sem_t *eating, sem_t *left_chopstick,sem_t *right_chopstick);
void fix_bug(int id);

#endif
