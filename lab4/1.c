/* 1. Write a c program to create a linked list for 10 elements and arrange in
 * descending order
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *createNode(int value) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->value = value;
  node->next = NULL;
  return node;
}

void insert(Node **head, int value) {
  Node *newNode = createNode(value);
  if (*head == NULL) {
    *head = newNode;
    return;
  }

  Node *temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
}

void print(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    printf("%d->", temp->value);
    temp = temp->next;
  }
  printf("NULL\n");
}

void sort(Node **head) {
  Node *temp = *head;
  while (temp != NULL) {
    Node *temp2 = temp->next;
    while (temp2 != NULL) {
      if (temp->value < temp2->value) {
        int tempValue = temp->value;
        temp->value = temp2->value;
        temp2->value = tempValue;
      }
      temp2 = temp2->next;
    }
    temp = temp->next;
  }
}

void free_memory(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    Node *next = temp->next;
    free(temp);
    temp = next;
  }
}
int main() {
  printf("Linked List in descending order\n");
  Node *list1 = NULL;
  int value;
  for (int i = 0; i < 10; i++) {
    printf("Enter element %d: ", i + 1);
    scanf("%d", &value);
    insert(&list1, value);
  }

  printf("Sorting\n");
  sort(&list1);

  printf("Printing Sorted Linked List\n");
  print(list1);

  free_memory(list1);
}
