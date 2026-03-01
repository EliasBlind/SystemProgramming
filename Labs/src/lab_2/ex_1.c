#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *read_file(void *arg) {
  char *filename = (char *)arg;
  printf("Поток начал чтение файла: %s\n", filename);
  // Имитация работы с файлом
  return NULL;
}

int main() {
  pthread_t thread1, thread2;

  pthread_create(&thread1, NULL, read_file, "file1.txt");
  pthread_create(&thread2, NULL, read_file, "file2.txt");

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  printf("Все потоки чтения завершены.\n");
  return 0;
}
