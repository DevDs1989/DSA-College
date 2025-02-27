// 1. Write a C program to implement the basic operations of stack using
// LinkedList. Write a C program to reverse a stack using operations push and
// pop only.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

Stack *createStack() {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->top = NULL;
  return stack;
}

int pop(Stack *stack) {
  if (stack->top == NULL) {
    printf("Stack is empty\n");
    return -1;
  }
  Node *temp = stack->top;
  stack->top = stack->top->next;
  int data = temp->data;
  free(temp);
  return data;
}

void push(Stack *stack, int data) {
  Node *newNode = createNode(data);
  newNode->next = stack->top;
  stack->top = newNode;
}

void printStack(Stack *stack) {
  Node *temp = stack->top;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

Stack *reverseStack(Stack *stack) {
  Stack *tempStack = createStack();
  while (stack->top != NULL) {
    push(tempStack, pop(stack));
  }
  return tempStack;
}

void peek(Stack *stack) {
  if (stack->top == NULL) {
    printf("Stack is empty\n");
    return;
  }
  printf("Top: %d\n", stack->top->data);
}
void freeStack(Stack *stack) {
  while (stack->top != NULL) {
    pop(stack);
  }
  free(stack);
}
void stackSize(Stack *stack) {
  int size = 0;
  Node *temp = stack->top;
  while (temp != NULL) {
    size++;
    temp = temp->next;
  }
  printf("Size: %d\n", size);
}
int main() {
  Stack *stack;
  stack = createStack();
  while (1) {
    printf("1. Push\n2. Pop\n3. Print\n4. Peek\n5.Size\n6. Reverse\n7. Exit\n");
    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter data: ");
      int data;
      scanf("%d", &data);
      push(stack, data);
      break;
    case 2:
      printf("Popped: %d\n", pop(stack));
      break;
    case 3:
      printStack(stack);
      break;
    case 4:
      peek(stack);
      break;
    case 5:
      stackSize(stack);
      break;
    case 6:
      Stack *reversedStack = reverseStack(stack);
      printf("Reversed stack: ");
      printStack(reversedStack);
      stack = reversedStack;
      break;
    case 7:
      freeStack(stack);
      exit(0);
      break;
    default:
      printf("Invalid choice\n");
    }
  }
}
