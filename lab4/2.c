/* 2. Write a program to insert a node at the beginning and at a given specific
 * position
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *createNode(int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

void insertAtBeginning(Node **head, int value) {
  Node *newNode = createNode(value);
  newNode->next = *head;
  *head = newNode;
}

void insertAtEnd(Node **head, int value) {
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
void insertAtPosition(Node **head, int value, int position) {
  Node *newNode = createNode(value);
  Node *temp = *head;
  for (int i = 0; i < position - 1; i++) {
    if (temp == NULL) {
      printf("Invalid position\n");
      return;
    }
    temp = temp->next;
  }
  newNode->next = temp->next;
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

void free_memory(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    Node *next = temp->next;
    free(temp);
    temp = next;
  }
}
int main() {
  Node *LinkedList = NULL;
  int choice;
  int data;
  int position;
  printf("1. Insert at beginning\n");
  printf("2. Insert at end\n");
  printf("3. Insert at position\n");
  printf("4. Print\n");
  while (1) {
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter data: ");
      scanf("%d", &data);
      insertAtBeginning(&LinkedList, data);
      break;
    case 2:
      printf("Enter data: ");
      scanf("%d", &data);
      insertAtEnd(&LinkedList, data);
      break;
    case 3:
      printf("Enter data: ");
      scanf("%d", &data);
      printf("Enter position: ");
      scanf("%d", &position);
      insertAtPosition(&LinkedList, data, position);
      break;
    case 4:
      print(LinkedList);
      break;
    default:
      printf("Invalid choice\n");
      free_memory(LinkedList);
      exit(1);
    }
  }
}
