// 3. Write a C program to check a word is palindrome or not using stack.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack {
    char data[MAX];
    int top;
} Stack;

Stack *createStack() {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->top = -1;
  return stack;
}

int isFull(Stack *stack) { return stack->top == MAX - 1; }
int isEmpty(Stack *stack) { return stack->top == -1; }

void push(Stack *stack, char data) {
  if (isFull(stack)) {
    printf("Stack is full\n");
    return;
  }
  stack->top++;
  stack->data[stack->top] = data;
}

int pop(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack is empty\n");
    return -1;
  }
  int data = stack->data[stack->top];
  stack->top--;
  return data;
}

int main() {
  Stack *stack = createStack();
  Stack *stack2 = createStack();
  char word[MAX];
  printf("Enter a word: ");
  scanf("%s", word);
  for (int i = 0; word[i] != '\0'; i++) {
    push(stack, word[i]);
    push(stack2, word[i]);
  }
  for (int i = 0; word[i] != '\0'; i++) {
    if (pop(stack) != pop(stack2)) {
      printf("Not palindrome\n");
      return 0;
    }
  }
  printf("Palindrome\n");
  return 0;
}
