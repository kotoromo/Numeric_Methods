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

/** Creates an empty matrix with n rows and m columns.
  * Returns a matrix : matrix_t
**/
matrix_t* empty_matrix(int n, int m){
  // [ [] ] = [ [](1) [](2) ... [](n) ]
  double** array = (double**) calloc(n, sizeof(double*));

  for(int i = 0; i<n; i++){
    array[i] = (double*) calloc(m, sizeof(double));
  }

  matrix_t* A = (matrix_t*) calloc(1, sizeof(matrix_t));

  A->n = n;

  A->m = m;

  A->content = array;

  return A;
}

/** Function which copies given matrix A
  * Returns a pointer copy of matrix A.
**/
matrix_t* copy_matrix(matrix_t A){
  matrix_t* C = empty_matrix(A.n, A.m);

  for(int i = 0; i<A.n; i++)
    for(int j = 0; j<A.m; j++)
      C->content[i][j] = A.content[i][j];

  return C;
}

/** Performs scalar multiplication
  * Returns a pointer to the scaled matrix.
**/
matrix_t* scale_by(matrix_t A, double p){
  matrix_t* B = copy_matrix(A);

  for(int i = 0; i<B->n; i++){
    for(int j = 0; j<B->m; j++){
      //B->content[i][j] *= B->content[i][j]*p;
      B->content[i][j] *= p;
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
matrix_t* add(matrix_t A, matrix_t B){
  // Can only sum same order matrices.
  if(A.n != B.n || A.m != B.m)
    return NULL;

  matrix_t* C = empty_matrix(A.n, A.m);

  for(int i = 0; i<C->n; i++)
    for(int j = 0; j<C->m; j++){
      C->content[i][j] = A.content[i][j] + B.content[i][j];

    }

  return C;
}

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

/** Defines a matrix given a double pointer representing an array, n rows, and
  * m columns
  *
  * Returns a matrix defined by the given parameters
**/
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


/** Frees the space in memory used by the matrix R instance. **/
int free_matrix(matrix_t* R){
  for(int i = 0; i<R->n; i++){
    free(R->content[i]);
  }

  free(R->content);

  free(R);

  return EXIT_SUCCESS;

}

/** Computes whether the given matrix A is a square matrix
  * Returns boolean
**/
bool is_square(matrix_t A){
  if(&A != NULL)
    if(A.n == A.m)
      return true;
    else
      return false;
}


/** Prints a given matrix A **/
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

/** Creates an empty double pointer element of nxm items
  * Returns double pointer array
**/
double** create_empty_array(int n, int m){
  double** a = (double**) calloc(n, sizeof(double*));
  for(int i = 0; i<n; i++){
    a[i] = (double*) calloc(m, sizeof(double));
  }

  return a;
}

/** Converts given array of variable rows but MAX_SIZE (1024 bytes) columns of
  * n rows and m columns into a double pointer equivalent
  *
  * Retruns array equivalent in double**
**/
double** array_to_double_pointer(double array [][MAX_SIZE], int n, int m){
  double** output = (double**) calloc(n, sizeof(double*));

  for(int i = 0; i<n; i++){
    output[i] = (double*) calloc(m, sizeof(double));
  }

  for(int i = 0; i<n; i++){
    for(int j = 0; j<m; j++){
      output[i][j] = array[i][j];
    }
  }

  return output;
}
