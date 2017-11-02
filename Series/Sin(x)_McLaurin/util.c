#ifndef stdlib
#include <stdlib.h>
#endif

#ifndef stdlib
#include <stdio.h>
#endif

#ifndef math
#include <math.h>
#endif

#include "util.h"

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

  for(int i = l_inf; i<l_sup; i++){
    res += (function)(i); //NOTE THIS COULD BREAK!

  }

  return res;
}

// Función que define la suma de una función que se encuentra en función de su posición en una serie  dado un limite superior y un limite inferior
double sum_iter_fn(int inf_lim, int sup_lim, double (*f)(double, int), double x){
  double res = 0.0;

  for(int i = 0; i < sup_lim; i++){
    res += (*f)(x, i);
  }

  return res;
}

double sum_iter_fn_while(double (*f)(double, int), double x){
  double res = 0.0;
  double previous = 0.0;
  int i = 0;
  do{
    previous = absolute(res);
    res += (*f)(x, i);
    i++;
    //printf("res = %lf\n", absolute(res-previous));

  }while(absolute(res - previous) > 0.00005);

  printf("Iteraciones hechas: %d\nDelta X = %lf\n", i, absolute(res-previous)); //DEBUG

  if(isnan(res)){
    (res > 0)?(res = 1):(res = -1);
  }
  
  return res;
}

double absolute(double x){
  if(x < 0){
    return x*(-1);
  }else{
    return x;
  }
}
