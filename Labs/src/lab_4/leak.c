#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *ptr = (int *)malloc(10 * sizeof(int));

  if (ptr == NULL) {
    return 1; // Ошибка выделения памяти
  }

  for (int i = 0; i < 10; i++) {
    ptr[i] = i * 2;
  }

  printf("Программа завершена без освобождения памяти.\n");

  return 0;
}
