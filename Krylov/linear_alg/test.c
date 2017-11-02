#include "matrix.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
  double** a = (double**)create_empty_array(2, 2);

  double array[2][MAX_SIZE] = {
    {0, 9},
    {8, 7}
  };

  a = array_to_double_pointer(array, 2, 2);

  matrix_t* A = define_matrix(a, 2, 2);

  for(int i = 0; i<A->n; i++){
    printf("|");
    for(int j = 0; j<A->m; j++){
      printf("%f ", A->content[i][j]);
    }
    printf("|\n");
  }

  free(A);

  return 1;
}
