#include <stdio.h>

int main(void) {
  int a[5] = {10, 20, 30, 40, 50};

  printf("Адрес массива а: %p\n", (void *)a);
  printf("Адрес первого элемента &a[0]: %p\n", (void *)&a[0]);
  printf("Адрес третьего элемента &a[2]: %p\n", (void *)&a[2]);
  printf("Адреса + 1: %p\n", (void *)(a + 1));
  printf("Значение *(a + 1): %d\n", *(a + 1));

  return 0;
}