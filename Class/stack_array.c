#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Stack {
    int top;
    int array[MAX];
} Stack;

Stack *createStack() {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->top = -1;
  return stack;
}

int isFull(Stack *stack) { return stack->top == MAX - 1; }

int isEmpty(Stack *stack) { return stack->top == -1; }

Stack *push(Stack *stack, int data) {
  if (isFull(stack)) {
    printf("Stack is full\n");
    return stack;
  }
  stack->array[++stack->top] = data;
  return stack;
}

Stack *pop(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack is empty\n");
    return stack;
  }
  stack->top--;
  return stack;
}

void printStack(Stack *stack) {
  for (int i = 0; i <= stack->top; i++) {
    printf("%d\n", stack->array[i]);
  }
  printf("NULL\n");
}

int size(Stack *stack) { return stack->top + 1; }

int peek(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack is empty\n");
    return -1;
  }
  return stack->array[stack->top];
}

int main() {
  Stack *stack = createStack();
  stack = push(stack, 1);
  stack = push(stack, 2);
  stack = push(stack, 3);
  stack = push(stack, 4);
  stack = push(stack, 5);
  stack = push(stack, 6);
  stack = push(stack, 7);
  stack = push(stack, 8);
  stack = push(stack, 9);
  stack = push(stack, 10);
  stack = push(stack, 11);

  printStack(stack);
  printf("Peek: %d\n", peek(stack));
  for (int i = 0; i < 9; i++) {
    stack = pop(stack);
  }
  isFull(stack) ? printf("Stack is full\n") : printf("Stack is not full\n");
  isEmpty(stack) ? printf("Stack is empty\n") : printf("Stack is not empty\n");
  printf("Size: %d\n", size(stack));

  return 0;
}
