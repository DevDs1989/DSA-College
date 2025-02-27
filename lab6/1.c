// 1. Write a C program to implement the basic operations of stack using arrays.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int Stack[MAX];
int top = -1;

int isFull() { return top == MAX - 1; }

int isEmpty() { return top == -1; }

void push(int data) {
  if (isFull()) {
    printf("Stack is full\n");
    return;
  }
  top++;
  Stack[top] = data;
}

void pop() {
  if (isEmpty()) {
    printf("Stack is empty\n");
    return;
  }
  top--;
}

void printStack() {
  for (int i = 0; i <= top; i++) {
    printf("%d ", Stack[i]);
  }
  printf("NULL\n");
}

int size() { return top == -1 ? 0 : top + 1; }

int peek() {
  if (isEmpty()) {
    printf("Stack is empty\n");
    return -1;
  }
  return Stack[top];
}

int main() {
  while (1) {
    printf("1. Push\n2. Pop\n3. Print\n4. Size\n5. Peek\n6. Exit\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter data: ");
      int data;
      scanf("%d", &data);
      push(data);
      break;
    case 2:
      pop();
      break;
    case 3:
      printStack();
      break;
    case 4:
      printf("Size: %d\n", size());
      break;
    case 5:
      printf("Peek: %d\n", peek());
      break;
    case 6:
      exit(0);
    default:
      printf("Invalid choice\n");
    }
  }
}
