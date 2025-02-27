#include <stdio.h>

#define MAX 10

int front = -1, rear = -1;
int queue[MAX];

int isFull() { return rear == MAX - 1; }

int isEmpty() { return front == -1; }

void enqueue(int data) {
  if (isFull()) {
    printf("Queue is full\n");
    return;
  }
  if (front == -1) {
    front = 0;
  }
  queue[++rear] = data;
}

int dequeue() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return -1;
  }
  int data = queue[front];
  if (front == rear) {
    front = rear = -1;
  } else {
    front++;
  }
  return data;
}

void printQueue() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return;
  }
  for (int i = front; i <= rear; i++) {
    printf("%d\n", queue[i]);
  }
  printf("NULL\n");
}

int peekFront() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return -1;
  }
  return queue[front];
}

int peekRear() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return -1;
  }
  return queue[rear];
}

int main() {
  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(4);
  enqueue(5);
  printQueue();
  dequeue();
  dequeue();
  printQueue();
  printf("Front: %d\n", peekFront());
  printf("Rear: %d\n", peekRear());
  return 0;
}
