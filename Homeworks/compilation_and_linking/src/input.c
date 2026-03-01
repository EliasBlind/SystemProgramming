#include <stdio.h>

void get_numbers(int *a, int *b) {
  while (scanf("%d %d", a, b) != 2) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
      ;
    if (c == EOF)
      return;
  }
}
