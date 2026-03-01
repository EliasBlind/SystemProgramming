#include <pthread.h>
#include <stdio.h>

void *myThread(void* arg) {
    printf("Hello from thread!\n");
    return NULL;
}

int main(void) {
    pthread_t my_thread;

    if (pthread_create(&my_thread, NULL, myThread, NULL) != 0) {
        perror("Failed to create thread");
        return 1;
    }

    printf("Hello from main!\n");

    pthread_join(my_thread, NULL);

    return 0;
}
