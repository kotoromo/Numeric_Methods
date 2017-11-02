#ifndef stdbool
#include<stdbool.h>
#endif

#define MAX_SIZE 1024

typedef struct Matrix{
  int n;
  int m;

  double** content;

}matrix_t;

/** Performs scalar multiplication **/
matrix_t* scale_by(matrix_t, double);

/** Takes two matrices A, and B, and performs matrix multiplication.
  * Returns a matrix_t pointer.
  *
**/
matrix_t* multiply(matrix_t, matrix_t);

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
double det(matrix_t);

/** Assigns memory space for matrix and initializes them with the given 2-d
  * array.
  * Returns matrix_t pointer.
**/

matrix_t* define_matrix(double**, int, int);

bool is_square(matrix_t);

matrix_t* empty_matrix(int, int);

void free_matrix(matrix_t*);

char** convert_matrix_to_string(matrix_t);

double** create_empty_array(int, int);

double** array_to_double_pointer(double[][MAX_SIZE], int, int);

void print_matrix(matrix_t);
