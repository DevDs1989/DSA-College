
/*write a program in c to add 2 matrix's and have to print new matrix*/
#include <stdio.h>
#include <stdlib.h>

int main() {
  int m, n, i, j;
  printf("Enter the size of the matrix A as m and n: ");
  scanf("%d %d", &m, &n);
  int matrixA[m][n], matrixB[m][n], res[m][n];
  printf("Enter the elements of matrix A: \n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &matrixA[i][j]);
    }
  }
  printf("Enter the elements of matrix B: \n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &matrixB[i][j]);
    }
  }
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      res[i][j] = matrixA[i][j] + matrixB[i][j];
    }
  }
  printf("The resultant matrix is: \n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", res[i][j]);
    }
    printf("\n");
  }
}
