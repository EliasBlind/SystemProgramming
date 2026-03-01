#include <pthread.h>
#include <stdio.h>

pthread_mutex_t lock;

void *writer(void *arg) {
  pthread_mutex_lock(&lock);
  printf("Поток %ld записывает данные...\n", (long)arg);
  pthread_mutex_unlock(&lock);
  return NULL;
}

int main() {
  pthread_t threads[2];
  pthread_mutex_init(&lock, NULL);

  for (long i = 0; i < 2; i++)
    pthread_create(&threads[i], NULL, writer, (void *)i);

  for (int i = 0; i < 2; i++)
    pthread_join(threads[i], NULL);

  pthread_mutex_destroy(&lock);
  return 0;
}
