#include <stdio.h>

int main(void) {
  char c;
  short s;
  int i;
  long l;
  long long ll;
  float f;
  double d;
  int *ptr;

  printf("Размер char: %zu байт\n", sizeof(c));
  printf("Размер short: %zu байт\n", sizeof(s));
  printf("Размер int: %zu байт\n", sizeof(i));
  printf("Размер long: %zu байт\n", sizeof(l));
  printf("Размер long long: %zu байт\n", sizeof(ll));
  printf("Размер float: %zu байт\n", sizeof(f));
  printf("Размер double: %zu байт\n", sizeof(d));
  printf("Размер указателя int*: %zu байт\n", sizeof(ptr));
  printf("Размер size_t: %zu байт\n", sizeof(size_t));

  return 0;
}