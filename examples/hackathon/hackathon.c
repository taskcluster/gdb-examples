#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define TEAMS_COUNT 5

int main() {
  int i;
  pid_t teams[TEAMS_COUNT];

  for (i = 0; i < TEAMS_COUNT; i++) {
    pid_t pid = fork();
    if (pid < 0) {
      return -1;
    } else if (pid == 0) {
      execl("team", 0);
      _exit(EXIT_FAILURE);
    } else {
      teams[i] = pid;
    }
  }

  pid_t first = wait(0);

  for (i = 0; i < TEAMS_COUNT; i++) {
    kill(teams[i], SIGTERM);
  }

  printf("%i team is a winner!\n", first);

  return 0;
}
