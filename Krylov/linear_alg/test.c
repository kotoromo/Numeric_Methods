#include "matrix.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(void){
  double** a = (double**)create_empty_array(2, 2);

  a[0][0] = 1;
  a[0][1] = 2;
  a[1][0] = 3;
  a[1][1] = 4;

  matrix_t* A = define_matrix(a, 2, 2);

  //matrix_t* A = empty_matrix(2, 2);

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
