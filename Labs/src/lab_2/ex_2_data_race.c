#include <pthread.h>
#include <stdio.h>

#define ITERATIONS 1000000
int counter = 0;

void *increment(void *arg) {
  (void)arg;

  for (int i = 0; i < ITERATIONS; i++) {
    counter++;
  }
  return NULL;
}

int main() {
  pthread_t t1, t2;

  if (pthread_create(&t1, NULL, increment, NULL) != 0) {
    perror("Ошибка создания потока 1");
    return 1;
  }
  if (pthread_create(&t2, NULL, increment, NULL) != 0) {
    perror("Ошибка создания потока 2");
    return 1;
  }

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  printf("Финальное значение счетчика: %d\n", counter);
  printf("Ожидаемое значение: %d\n", ITERATIONS * 2);

  return 0;
}
