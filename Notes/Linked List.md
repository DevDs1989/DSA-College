## Time Complexity:

- O(1) insertion
- O(1) deletion
- O(n) traversal
### Singly Linked List

- Contains Data and Pointer to the Next Node


```
#include <stdio.h>
#include <stdlib.h>

 struct Node{
  int value;
  struct Node *next;
};

struct Node *create_node(int data){
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->value = data;
  newNode->next = NULL;
  return newNode;
}

void print_list(struct Node* head){
  struct Node *temp = head;
  while(temp != NULL){
    printf("%d -> ", temp->value);
    temp = temp->next;

  }
  printf("NULL\n");
}

int main (int argc, char *argv[]) {
  struct Node * head = create_node(10);
  head-> next = create_node(20);
  head->next->next = create_node(30);
    print_list(head);
  return 0;
}
```

### Doubly Linked List

- Contains Data and pointers to prev and next nodes of the Linked List