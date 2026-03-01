#include <stdio.h>
#include <stdlib.h>

int main() {
  int *arr;
  for (int i = 0; i < 20; i++) {
    arr = (int *)malloc(sizeof(int));

    if (arr == NULL) {
      fprintf(stderr, "Ошибка выделения памяти\n");
      return 1;
    }

    *arr = i;
    printf("%d ", *arr);
    free(arr);
  }

  printf("\nПрограмма завершена успешно.\n");
  return 0;
}
