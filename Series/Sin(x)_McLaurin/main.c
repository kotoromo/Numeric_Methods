#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <float.h>
#include "util.h"

#define PI 3.1416
double sum_iter_fn(int sup_lim, int inf_lim, double (*fn)(double, int), double x);

int main(int argc, char const *argv[]) {

  if(argc < 2){printf("Es necesario pasar un ángulo como parámetro al binario.\n"); return 0;}
  double angle;

  // Hacemos un 'parseo' de la entrada.
  sscanf(argv[1],"%lf", &angle);
  angle = PI*angle;

  if(angle > 2*PI){
    angle = 0;
  }

  // Definimos la función a evaluar en la suma.
  double function(double x, int n){
    double res = 0.0;

    res = pow(-1, n)*pow(x, 2*n+1)*(1/factorial(2*n+1));

    return res;
  }

  double (*f)(double, int) = &function;
  printf("sin(%f*PI) = %.*e\n", angle/PI, DECIMAL_DIG-17, sum_iter_fn_while(f, angle));

  return 0;
}
