/* write a c program multiplication of 2 matrix's and take the size from*/
/*    the user*/
#include <stdio.h>
#include <stdlib.h>

int main() {
  int m, n, p, q, i, j, k;
  printf("Enter the size of the matrix A as m and n: ");
  scanf("%d %d", &m, &n);
  printf("Enter the size of the matrix B as p and q: ");
  scanf("%d %d", &p, &q);
  if (n != p) {
    printf("Matrix multiplication is not possible\n");
    exit(0);
  }
  int matrixA[m][n], matrixB[p][q], res[m][q];
  printf("Enter the elements of matrix A: \n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &matrixA[i][j]);
    }
  }
  printf("Enter the elements of matrix B: \n");
  for (i = 0; i < p; i++) {
    for (j = 0; j < q; j++) {
      scanf("%d", &matrixA[i][j]);
    }
  }
  for (i = 0; i < m; i++) {
    for (j = 0; j < q; j++) {
      res[i][j] = 0;
      for (k = 0; k < n; k++) {
        res[i][j] = res[i][j] + matrixA[i][k] * matrixB[k][j];
      }
    }
  }
  printf("The resultant matrix is: \n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < q; j++) {
      printf("%d ", res[i][j]);
    }
    printf("\n");
  }
  return 0;
}
