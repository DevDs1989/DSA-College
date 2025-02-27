#include <stdio.h>

int globalArray[5];
int main() {
  int localArray[5];
  for (int i = 0; i < 5; i++) {
    printf("%d\n", localArray[i]);
  }
}
