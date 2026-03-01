#ifndef CALC_H
#define CALC_H

typedef struct {
  int sum;
  int prod;
} CalcResult;

CalcResult calc(int a, int b);
void print_calc_result(CalcResult *cr);

#endif // CALC_H