#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
  pid_t pid = fork();

  if (pid < 0) {
    fprintf(stderr, "Ошибка при fork\n");
    return 1;
  } else if (pid == 0) {
    printf("Я ребёнок, вот мой PID: %d\n", getpid());
  } else {
    printf("Я родитель, мой PID: %d\n", getpid());
  }

  return 0;
}
