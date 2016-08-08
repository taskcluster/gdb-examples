#ifndef globals
#define globals

#include <pthread.h>

#define BUGS_COUNT 20
#define PROGRAMMERS_COUNT 5

extern pid_t pid;
extern int bugs_remain;
extern int bugs_fixed;
extern pthread_mutex_t assign_lock;
extern pthread_mutex_t commit_lock;

#endif
