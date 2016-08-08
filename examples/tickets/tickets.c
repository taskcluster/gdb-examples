#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

#define TICKETS_COUNT 100
#define SELLERS_COUNT 5

typedef struct {
  int id;
} spawn_seller_args;

// Initializing globals.
static int tickets = TICKETS_COUNT;
static pthread_mutex_t lock;

void* spawn_seller(void *args);
void find_customer();

int main() {
  srand(time(0));

  // Initializing locals.
  int i;
  pthread_t sellers[SELLERS_COUNT];

  // Initializing the mutex.
  if (pthread_mutex_init(&lock, 0) != 0) return -1;

  // Running threads.
  for (i = 0; i < SELLERS_COUNT; i++) {
    spawn_seller_args *args = malloc(sizeof(*args));
    args->id = i;
    int status = pthread_create(&(sellers[i]), 0, &spawn_seller, args);
    if (status != 0) return -1;
  }

  // Waiting for threads to finish.
  for (i = 0; i < SELLERS_COUNT; i++) {
    pthread_join(sellers[i], 0);
  }

  // Destroying the mutex.
  pthread_mutex_destroy(&lock);

  return 0;
}

void* spawn_seller(void *args) {
  spawn_seller_args *seller_args = args;

  bool done = false;
  int tickets_sold = 0;
  int id = seller_args->id;

  while (!done) {
    // Doing some time-consuming work.
    find_customer();

    // Selling the ticket.
    pthread_mutex_lock(&lock);

    if (tickets == 0) {
      done = true;
    } else {
      tickets--;
      tickets_sold++;
      printf("%i seller sold  %i tickets, %i remain\n",
        id, tickets_sold, tickets);
    }

    pthread_mutex_unlock(&lock);
  }

  free(seller_args);

  return 0;
}

void find_customer() {
  sleep(rand() % 5); // Uh oh, sleeping on the job!
}
