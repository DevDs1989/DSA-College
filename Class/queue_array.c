#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int front = -1, rear = -1;
int queue[MAX];

void enqueue(int data) {
  if (rear == MAX - 1) {
    printf("Queue is full\n");
    return;
  }
  if (front == -1) {
    front = 0;
  }
  rear++;
  queue[rear] = data;
}

int dequeue() {
  if (front == -1) {
    printf("Queue is empty\n");
    return -1;
  }
  int data = queue[front];
  front++;
  if (front > rear) {
    front = rear = -1;
  }
  return data;
}

void display() {
  if (front == -1) {
    printf("Queue is empty\n");
    return;
  }
  for (int i = front; i <= rear; i++) {
    printf("%d ", queue[i]);
  }
  printf("\n");
}

int peek() {
  if (front == -1) {
    printf("Queue is empty\n");
    return -1;
  }
  return queue[front];
}

int rear_peek() {
  if (rear == -1) {
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
  enqueue(6);
  enqueue(7);
  enqueue(8);
  enqueue(9);
  enqueue(10);
  display();
  printf("Dequeued: %d\n", dequeue());
  printf("Dequeued: %d\n", dequeue());
  display();
  printf("Peek: %d\n", peek());
  printf("Rear Peek: %d\n", rear_peek());
  return 0;
}
