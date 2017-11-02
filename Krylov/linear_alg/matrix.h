#ifndef stdbool
#include<stdbool.h>
#endif

typedef struct matrix_t Matrix;

/** Performs scalar multiplication **/
Matrix* scale_by(Matrix, double);

/** Takes two matrices A, and B, and performs matrix multiplication.
  * Returns a Matrix pointer.
  *
**/
Matrix* multiply(Matrix, Matrix);

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
double det(Matrix);

/** Assigns memory space for matrix and initializes them with the given 2-d
  * array.
  * Returns Matrix pointer.
**/

Matrix* define_matrix(double**, int, int);

bool is_square(Matrix);

Matrix* empty_matrix(int, int);

void free_matrix(Matrix*);

char** convert_matrix_to_string(Matrix);

double** create_empty_array(int, int);
