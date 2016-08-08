#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define COUNTERS_COUNT 10

int main() {
  int i;
  pid_t counters[COUNTERS_COUNT];

  for (i = 0; i < COUNTERS_COUNT; i++) {
    pid_t pid = fork();
    if (pid < 0) {
      return -1;
    } else if (pid == 0) {
      execl("counter", 0);
      _exit(EXIT_FAILURE);
    } else {
      counters[i] = pid;
    }
  }

  for (i = 0; i < COUNTERS_COUNT; i++) {
    waitpid(counters[i], 0, 0);
  }

  return 0;
}
