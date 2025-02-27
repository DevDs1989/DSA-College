#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int data;
    struct Queue *next;
} Queue;

Queue *front = NULL;
Queue *rear = NULL;

void enqueue(int data) {
  Queue *newNode = (Queue *)malloc(sizeof(Queue));
  newNode->data = data;
  newNode->next = NULL;
  if (front == NULL && rear == NULL) {
    front = rear = newNode;
  } else {
    rear->next = newNode;
    rear = newNode;
  }
}

int dequeue() {
  if (front == NULL) {
    printf("Queue is empty\n");
    return -1;
  }
  Queue *temp = front;
  int data = temp->data;
  front = front->next;
  if (front == NULL) {
    rear = NULL;
  }
  free(temp);
  return data;
}

void display() {
  if (front == NULL) {
    printf("Queue is empty\n");
    return;
  }
  Queue *temp = front;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int peek() {
  if (front == NULL) {
    printf("Queue is empty\n");
    return -1;
  }
  return front->data;
}

int rear_peek() {
  if (rear == NULL) {
    printf("Queue is empty\n");
    return -1;
  }
  return rear->data;
}

int isFull() {
  Queue *temp = (Queue *)malloc(sizeof(Queue));
  if (temp == NULL) {
    return 1;
  }
  free(temp);
  return 0;
}

int isEmpty() { return front == NULL; }

int main() {
  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(4);
  display();
  printf("Peek: %d\n", peek());
  printf("Rear Peek: %d\n", rear_peek());
  printf("Dequeued: %d\n", dequeue());
  display();
  return 0;
}
