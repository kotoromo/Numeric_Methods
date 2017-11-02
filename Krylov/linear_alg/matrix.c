#ifndef stdlib
#include <stdlib.h>
#endif

#ifndef stdio
#include <stdio.h>
#endif

#ifndef stdbool
#include<stdbool.h>
#endif

#include "matrix.h"

matrix_t* empty_matrix(int n, int m){
  // [ [] ] = [ [](1) [](2) ... [](n) ]
  double** array = (double**) calloc(1, n);

  for(int i = 0; i<n; i++){
    array[i] = (double*) calloc(m, sizeof(double));
  }

  matrix_t* A = (matrix_t*) calloc(1, sizeof(matrix_t));

  A->n = n;

  A->m = m;

  A->content = array;

  for(int i = 0; i<A->n; i++){
    free(array[i]);

  }

  free(array);

  return A;
}

/** Performs scalar multiplication **/
matrix_t* scale_by(matrix_t A, double p){
  matrix_t* B = &A;

  for(int i = 0; i<A.n; i++){
    for(int j = 0; j<A.m; j++){
      B->content[i][j] = B->content[i][j]*p;
    }
  }

  return B;
}

/** Takes two matrices A, and B, and performs matrix multiplication.
  * Returns a matrix_t pointer.
  *
**/
matrix_t* multiply(matrix_t A, matrix_t B){
  // check for not null.
  if(&A == NULL || &B == NULL) // NOTE Check for possible future errors.
    return NULL;

  // check whether rank condition is satisfied.
  // (AB exists iff a(ij), b(kl) | j = k)
  if(A.m != B.n){
    return NULL;
  }

  matrix_t* C = empty_matrix(A.m, B.n);

  return C;

}

/** Takes two matrices A, and B, and performs matrix addition.
  * Returns a matrix_t pointer.
**/
matrix_t* add(matrix_t, matrix_t);

/** Computes the transpose of the given matrix_t.
  * Returns a matrix_t pointer.
**/
matrix_t* transpose(matrix_t);

/** Computes the inverse of a matrix_t.
  * Returns a matrix_t pointer.

**/
matrix_t* inverse(matrix_t);

/** Computes the determinant of a matrix_t.
  * Returns result:double
**/
double det(matrix_t A);


matrix_t* define_matrix(double** array, int n, int m){

  if(array == NULL || &n == NULL || &m == NULL){
    return NULL;
  }

  matrix_t* A = (matrix_t*) calloc(1, sizeof(matrix_t));

  A->n = n;

  A->m = m;

  A->content = array;

  return A;
}


void free_matrix(matrix_t* A){
  double** array = A->content;

  for(int i = 0; i<A->n; i++){
    free(array[i]);
  }

  free(array);

  free(A);

  return;
}

bool is_square(matrix_t A){
  if(&A != NULL)
    if(A.n == A.m)
      return true;
    else
      return false;
}

void print_matrix(matrix_t A){
  for(int i = 0; i<A.n; i++){
    printf("|");
    for(int j = 0; j<A.m; j++){
      printf("%f ", A.content[i][j]);
    }
    printf("|\n");
  }

  return;
}

double** create_empty_array(int n, int m){
  double** a = (double**) calloc(n, sizeof(double*));
  for(int i = 0; i<n; i++){
    a[i] = (double*) calloc(m, sizeof(double));
  }

  return a;
}
