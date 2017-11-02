#include "matrix.h"
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(void){
  /**double** a = (double**)create_empty_array(2, 2);
  //double b[2][2] = a;

  Matrix* A = define_matrix(a, 2, 2);
  **/

  Matrix* A = empty_matrix(2, 2);

  for(int i = 0; i<A->n; i++){
    printf("|");
    for(int j = 0; j<A->m; j++){
      printf("%f ", A->content[i][j]);
    }
    printf("|\n");
  }

  printf("%f", A->content[0][0]);

  free(A);

  return 1;
}
