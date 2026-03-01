#include "calc.h"
#include "input.h"

int main(void) {
  int a, b;
  get_numbers(&a, &b);
  CalcResult cr = calc(a, b);
  print_calc_result(&cr);
  return 0;
}