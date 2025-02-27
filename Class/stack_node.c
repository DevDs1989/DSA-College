#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

Stack *createStack() {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->top = NULL;
  return stack;
}

Stack *push(Stack *stack, int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = stack->top;
  stack->top = newNode;
  return stack;
}

Stack *pop(Stack *stack) {
  if (stack->top == NULL) {
    printf("Stack is empty\n");
    return stack;
  }
  Node *temp = stack->top;
  stack->top = stack->top->next;
  free(temp);
  return stack;
}

void printStack(Stack *stack) {
  Node *temp = stack->top;
  while (temp != NULL) {
    printf("%d\n", temp->data);
    temp = temp->next;
  }
  printf("NULL");
}

int peek(Stack *stack) {
  if (stack->top == NULL) {
    printf("Stack is empty\n");
    return -1;
  }
  return stack->top->data;
}

int isEmpty(Stack *stack) { return stack->top == NULL; }

int size(Stack *stack) {
  int count = 0;
  Node *temp = stack->top;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }
  return count;
}

void clear(Stack *stack) {
  Node *temp = stack->top;
  while (temp != NULL) {
    Node *next = temp->next;
    free(temp);
    temp = next;
  }
  stack->top = NULL;
}

int main() {
  Stack *stack = createStack();
  stack = push(stack, 1);
  stack = push(stack, 2);
  stack = push(stack, 3);
  stack = push(stack, 4);
  printStack(stack);
  stack = pop(stack);
  printf("After 1 pop\n");
  printStack(stack);
  printf("Peek: %d\n", peek(stack));
  printf("Size: %d\n", size(stack));
  printf("Is empty: %d\n", isEmpty(stack));
  clear(stack);
  return 0;
}
