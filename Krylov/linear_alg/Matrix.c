#include "matrix.h"

/** Performs scalar multiplication **/
Matrix* scale_by(Matrix A, double p){
  Matrix* B = &A;

  for(int i = 0; i<A.n; i++){
    for(int j = 0; j<A.m; j++){
      B->content[i][j] = B->content[i][j]*p;
    }
  }

  return B;
}

/** Takes two matrices A, and B, and performs matrix multiplication.
  * Returns a Matrix pointer.
  *
**/
Matrix* multiply(Matrix A, Matrix B){
  // check for not null.
  if(&A == NULL || &B == NULL) // NOTE Check for possible future errors.
    return NULL;

  // check whether rank condition is satisfied.
  // (AB exists iff a(ij), b(kl) | j = k)
  if(A.m != B.n){
    return NULL;
  }

  Matrix* C = define_matrix(A.m, B.n);

  return C;

}

/** Takes two matrices A, and B, and performs matrix addition.
  * Returns a Matrix pointer.
**/
Matrix* add(Matrix, Matrix);

/** Computes the transpose of the given Matrix.
  * Returns a Matrix pointer.
**/
Matrix* transpose(Matrix);

/** Computes the inverse of a Matrix.
  * Returns a Matrix pointer.

**/
Matrix* inverse(Matrix);

/** Computes the determinant of a Matrix.
  * Returns result:double
**/
double det(Matrix A);

Matrix* define_matrix(double** array, int n, int m){

  if(array == NULL || &n == NULL || &m == NULL){
    return NULL;
  }

  Matrix* A = (Matrix*) calloc(1, sizeof(Matrix));

  A->n = n;

  A->m = m;

  A->content = array;

  return A;
}

Matrix* empty_matrix(int n, int m){
  // [ [] ] = [ [](1) [](2) ... [](n) ]
  double** array = (double**) calloc(1, n);

  for(int i = 0; i<n; i++){
    array[i] = (double*) calloc(m, sizeof(double));
  }

  Matrix* A = (Matrix*) calloc(1, sizeof(Matrix));

  A->n = n;

  A->m = m;

  A->content = array;

  for(int i = 0; i<A->n; i++){
    free(array[i]);

  }

  free(array);

  return A;
}

void free_matrix(Matrix* A){
  double** array = A->content;

  for(int i = 0; i<A->n; i++){
    free(array[i]);
  }

  free(array);

  free(A);

  return;
}

bool is_square(Matrix* A){
  if(A != NULL)
    if(A.n == A.m)
      return true;
    else
      return false;
}
