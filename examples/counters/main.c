#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  int i;

  for (i = 0; i < 10; i++) {
    pid_t pid = fork();
    if (pid == 0) {
      execl("counter", NULL);
      _exit(EXIT_FAILURE);
    } else if (pid < 0) {
      return -1;
    }
  }

  wait(NULL);

  return 0;
}
