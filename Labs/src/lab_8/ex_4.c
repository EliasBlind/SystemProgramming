#include <stdio.h>

void recursive_function(int n) {
  int local_x;
  printf("Вызов %2d: n=%d, Адрес local_x = %p\n", 5 - n, n, (void *)&local_x);
  if (n > 0) {
    recursive_function(n - 1);
  }
}

int main(void) {
  printf("Начало работы main\n");
  recursive_function(5);
  printf("Завершение работы main\n");
  return 0;
}