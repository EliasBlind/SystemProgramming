#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid1 = fork();

    if (pid1 < 0) {
        fprintf(stderr, "Ошибка при первом fork\n");
        return 1;
    } else if (pid1 == 0) {
        pid_t pid2 = fork();

        if (pid2 < 0) {
            fprintf(stderr, "Ошибка при втором fork\n");
            return 1;
        } else if (pid2 == 0) {
            printf("Я внук, мой PID: %d, уровень: 3\n", getpid());
        } else {
            printf("Я потомок, мой PID: %d, уровень: 2\n", getpid());
            wait(NULL);
        }
    } else {
        printf("Я родитель, мой PID: %d, уровень: 1\n", getpid());
        wait(NULL);
    }

    return 0;
}
