#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <float.h>

#define PI 3.1416

double factorial(double);
double sum(int, int, double (*)(double));
double sum_iter_fn(int inf_lim, int sup_lim, double (*f)(double, int), double x);

int main(int argc, char const *argv[]) {

  double angle = 0.0;

  if(argc < 2){
    printf("Introduce un múltiplo de PI para calcular el seno del ángulo.\n");
    scanf("%lf", &angle);

  }else{
    sscanf(argv[1],"%lf", &angle);

  }

  // Hacemos un 'parseo' de la entrada.
  angle = PI*angle;

  // Definimos la función a evaluar en la suma.
  double function(double x, int n){
    double res = 0.0;

    res = pow(-1, n)*pow(x, 2*n+1)*(1/factorial(2*n+1));

    return res;
  }

  double (*f)(double, int) = &function;
  printf("sin(%f*PI) = %*.e\n", angle/PI, DECIMAL_DIG - 17,sum_iter_fn(0, 15, f, angle));

  return 0;
}

// Definimos la función que calula de manera recursiva el factorial de un numero real x
double factorial(double x){
  double res = 0.0;

  if (x == 0){
    res =  1;

  }else{
    res = x*factorial(x-1);

  }

  return res;
}

// Función que define la suma de una función dado un limite superior y un limite inferior
double sum(int l_inf, int l_sup, double (*function)(double)){
  double res = 0.0;
  int i = 0;
  for(i = l_inf; i<l_sup; i++){
    res += (function)(i); //NOTE THIS COULD BREAK!

  }

  return res;
}

// Función que define la suma de una función que se encuentra en función de su posición en una serie  dado un limite superior y un limite inferior
double sum_iter_fn(int inf_lim, int sup_lim, double (*f)(double, int), double x){
  double res = 0.0;
  int i = 0;
  for(i = inf_lim; i < sup_lim; i++){
    res += (*f)(x, i);
  }

  return res;
}
