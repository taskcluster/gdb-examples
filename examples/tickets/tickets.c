#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

#define TICKETS_COUNT 100
#define SELLERS_COUNT 5

static int tickets = TICKETS_COUNT;
static pthread_mutex_t lock;

void* sell_tickets();
void find_customer();

int main() {
  pthread_t sellers[SELLERS_COUNT];

  if (pthread_mutex_init(&lock, NULL) != 0) return -1;

  srand(time(NULL));

  for (int i = 0; i < SELLERS_COUNT; i++) {
    int status = pthread_create(&(sellers[i]), NULL,
      &sell_tickets, NULL);
    if (status != 0) return -1;
  }

  for (int i = 0; i < SELLERS_COUNT; i++) {
    pthread_join(sellers[i], NULL);
  }

  pthread_mutex_destroy(&lock);

  return 0;
}

void* sell_tickets() {
  bool done = false;
  int tickets_sold = 0;
  int seller_id = rand() % 100;

  while (!done) {
    find_customer();
    pthread_mutex_lock(&lock);

    if (tickets == 0) {
      done = true;
    } else {
      tickets--;
      tickets_sold++;
      printf("%i seller sold  %i tickets, %i remain\n",
        seller_id, tickets_sold, tickets);
    }

    pthread_mutex_unlock(&lock);
  }

  return NULL;
}

void find_customer() {
  sleep(rand() % 5); // Uh oh, sleeping on the work!
}
