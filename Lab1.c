#include <stdio.h>

void traversal(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d\n", arr[i]);
  }
}

int search(int arr[], int n, int value) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == value) {
      printf("\nValue found at index %d\n", i);
      return i;
    }
  }
  printf("\nValue was not found\n");
  return 0;
}

void insertion(int arr[], int value, int index, int n) {
  // shifting
  for (int i = n; i > index; i--) {
    arr[i] = arr[i - 1];
  }
  arr[index] = value;
}

int main() {
  int size, insert_value, search_target, deletion_index, index_value;
  int array[100];

  printf("Enter Size of the Array: ");
  scanf("%d", &size);
  for (int i = 0; i < size; i++) {
    printf("Enter value at index %d: ", i);
    scanf("%d", &array[i]);
  }

  traversal(array, size);

  printf("Enter value to search: ");
  scanf("%d", &search_target);
  search(array, size, search_target);

  printf("Enter value to insert: ");
  scanf("%d", &insert_value);

  printf("Enter insert index: ");
  scanf("%d", &index_value);

  insertion(array, insert_value, index_value, size);

  traversal(array, size + 1);
}
