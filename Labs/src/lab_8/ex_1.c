#include <stdio.h>
#include <stdlib.h>

int global_var = 10;
static int static_var_initialized = 20;
static int static_var_uninitialized;

int main(void) {
  int local_var = 30;
  int *heap_var = (int *)malloc(sizeof(int));
  *heap_var = 40;

  printf("Адрес global_var: %p\n", (void *)&global_var);
  printf("Адрес static_var_initialized: %p\n", (void *)&static_var_initialized);
  printf("Адрес static_var_uninitialized: %p\n",
         (void *)&static_var_uninitialized);
  printf("Адрес local_var: %p\n", (void *)&local_var);
  printf("Адрес heap_var (указатель): %p\n", (void *)&heap_var);
  printf("Адрес данных в heap_var: %p\n", (void *)heap_var);

  free(heap_var);
  return 0;
}