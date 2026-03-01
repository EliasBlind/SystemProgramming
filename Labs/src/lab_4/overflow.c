#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *ptr = NULL;

  ptr = (int *)malloc(sizeof(int));

  if (ptr != NULL) {
    *ptr = 100;
    printf("Значение: %d\n", *ptr);
    free(ptr);
  }

  return 0;
}