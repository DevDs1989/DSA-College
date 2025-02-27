/* 3. To delete a node from beginning, from end and from a specific position
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
void deleteFromBeginning(Node **head) {
  if (*head == NULL) {
    printf("List is empty\n");
    return;
  }
  Node *temp = *head;
  *head = temp->next;
  free(temp);
}
void free_memory(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    Node *next = temp->next;
    free(temp);
    temp = next;
  }
}
void deleteFromEnd(Node **head) {
  if (*head == NULL) {
    printf("List is empty\n");
    return;
  }
  if ((*head)->next == NULL) {
    free(*head);
    *head = NULL;
    return;
  }
  Node *temp = *head;
  while (temp->next->next != NULL) {
    temp = temp->next;
  }
  free(temp->next);
  temp->next = NULL;
}

void deleteFromPosition(Node **head, int position) {
  if (*head == NULL) {
    printf("List is empty\n");
    return;
  }
  if (position == 0) {
    deleteFromBeginning(head);
    return;
  }
  Node *temp = *head;
  if (temp == NULL) {
    printf("Invalid position\n");
    return;
  }
  for (int i = 0; i < position - 1; i++) {
    temp = temp->next;
  }
  if (temp->next == NULL) {
    printf("Invalid position\n");
    return;
  }
  Node *delete = temp->next;
  temp->next = delete->next;
  free(delete);
}
void print(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    printf("%d->", temp->value);
    temp = temp->next;
  }
  printf("NULL\n");
}

int main() {
  Node *list1 = NULL;
  int value;
  int choice;
  int position;
  printf("1. Insert a Node\n");
  printf("2. Delete Node from beginning\n");
  printf("3. Delte Node from end\n");
  printf("4. Delete Node from a position");
  printf("5. Print\n");

  while (1) {
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      printf("Enter a value: ");
      scanf("%d", &value);
      insert(&list1, value);
      break;
    case 2:
      deleteFromBeginning(&list1);
      break;
    case 3:
      deleteFromEnd(&list1);
      break;
    case 4:
      printf("Enter a position: ");
      scanf("%d", &position);
      deleteFromPosition(&list1, position);
      break;
    case 5:
      print(list1);
      break;
    default:
      printf("Invalid choice\n");
      free_memory(list1);
      break;
    }
  }
}
