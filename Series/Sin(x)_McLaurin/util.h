#ifndef stdlib
#include <stdlib.h>
#endif

double factorial(double);
double sum(int, int, double (*)(double));
double sum_iter_fn(int inf_lim, int sup_lim, double (*f)(double, int), double x);
