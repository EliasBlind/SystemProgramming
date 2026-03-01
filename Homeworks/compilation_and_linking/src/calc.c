#include "calc.h"
#include <stdio.h>

CalcResult calc(int a, int b) {
  return (CalcResult){
      .sum = a + b,
      .prod = a * b,
  };
}

void print_calc_result(CalcResult *cr) {
  printf("Сумма = %d\n", cr->sum);
  printf("Произведение = %d\n", cr->prod);
}
