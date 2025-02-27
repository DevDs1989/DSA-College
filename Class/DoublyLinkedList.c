#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->value = value;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}
void forwardTraversal(Node *head) {
  Node *temp = head;
  while (temp != NULL) {

    printf("%d->", temp->value);
    temp = temp->next;
  }
  printf("NULL\n");
}
void backwardTraversal(Node *tail) {
  Node *temp = tail;
  while (temp != NULL) {
    printf("%d<-", temp->value);
    temp = temp->prev;
  }
  printf("NULL\n");
}

int main() {
  Node *List;
  List = createNode(1);
  List->next = createNode(2);
  List->next->prev = List;
  List->next->next = createNode(3);
  List->next->next->prev = List->next;
  forwardTraversal(List);
  backwardTraversal(List->next->next);
}
