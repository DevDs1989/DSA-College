// design and implement a circular doubly linked list in C program to manage the
// university course registration system the system showld allow students two
// following operations
// 1. register for a course (course id, course name)
// 2. drop a course
// 3. view registered courses
// 4. Move to next various courses
// 5. Insure navigation (after the last course it should go to the first course)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int courseID;
    char courseName[100];
    struct Node *next;
    struct Node *prev;
    int isFirst;
} Node;

void registerCourse(Node **head, int courseID, char courseName[]) {

  Node *newNode = (Node *)malloc(sizeof(Node));

  newNode->courseID = courseID;

  strcpy(newNode->courseName, courseName);

  newNode->next = newNode->prev = NULL;

  if (*head == NULL) {

    *head = newNode;

    (*head)->next = (*head)->prev = *head;
    (*head)->isFirst = 1;
    printf("Course Registerd\n");

  } else {
    Node *last = (*head)->prev;
    newNode->next = *head;
    (*head)->prev = newNode;
    newNode->prev = last;
    last->next = newNode;
    newNode->isFirst = 0;
    (*head) = (*head)->next;
    printf("Course Registered\n");
  }
}

void currentCourse(Node **head) {
  if (*head == NULL) {
    printf("No courses Registered\n");
    return;

    printf("Current Course: \nCourse ID: %d\nCourse Name: %s\n",
           (*head)->courseID, (*head)->courseName);
  }
}

void dropCourse(Node **head, int courseID) {
  if (head == NULL) {
    printf("No courses registed\n");
    return;
  }
  Node *temp = *head;
  Node *prev = NULL;
  while (temp->courseID != courseID) {
    if (temp->next == *head) {
      printf("Course not found\n");
      return;
    }
    prev = temp;
    temp = temp->next;
  }
  if (temp->next == *head && prev == NULL) {
    free(temp);
    *head = NULL;
    printf("Course dropped successfully\n");
    return;
  }
  if (temp == *head) {
    prev = (*head)->prev;
    *head = (*head)->next;
    prev->next = *head;
    (*head)->prev = prev;
    free(temp);
    printf("Course dropped successfully\n");
    return;
  }
  if (temp->next == *head) {
    prev->next = *head;
    (*head)->prev = prev;
    free(temp);
    printf("Course dropped successfully\n");
    return;
  }
  prev->next = temp->next;
  temp->next->prev = prev;
  free(temp);
  printf("Course dropped successfully\n");
}

void printCourses(Node *head) {
  if (head == NULL) {
    return;
  }
  Node *temp = head;
  printf("Courses Registered:\n");
  do {
    printf("Course ID: %d\n", temp->courseID);
    printf("Course Name: %s\n", temp->courseName);
    temp = temp->next;
  } while (temp != head);
}

void nextCourse(Node **head) {
  if (*head == NULL) {
    printf("No courses registered\n");
    return;
  }
  printf("Next Course is:\nCourse name: %s\nCourse ID: %d",
         (*head)->next->courseName, (*head)->next->courseID);
  *head = (*head)->next;
}

void prevCourse(Node **head) {
  if (*head == NULL) {
    printf("No courses registered\n");
    return;
  }
  printf("previous course is:\ncourse id: %d\ncourse name: %s\n",
         (*head)->prev->courseID, (*head)->prev->courseName);
  *head = (*head)->prev;
}

void firstCourse(Node **head) {
  Node *temp = *head;
  do {
    temp = temp->next;
  } while (temp->isFirst != 1);
  printf("first course is:\ncourse id: %d\ncourse name: %s\n", temp->courseID,
         temp->courseName);
}

int main() {
  Node *head = NULL;
  int choice;
  int courseID;
  char courseName[100];
  while (1) {
    printf("1. Register for a course\n");
    printf("2. Drop a course\n");
    printf("3. View registered courses\n");
    printf("4. Move to next course\n");
    printf("5. Current Course\n");
    printf("6. Move to previous course\n");
    printf("7. Exit\n");
    printf("8. First Course Registered\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();
    switch (choice) {
    case 1:
      printf("Enter course ID: ");
      scanf("%d", &courseID);
      getchar();
      printf("Enter course name: ");
      fgets(courseName, sizeof(courseName), stdin);
      courseName[strcspn(courseName, "\n")] = '\0';
      registerCourse(&head, courseID, courseName);
      break;
    case 2:
      printf("Enter course ID to drop: ");
      scanf("%d", &courseID);
      getchar();
      dropCourse(&head, courseID);
      break;
    case 3:
      printCourses(head);
      break;
    case 4:
      nextCourse(&head);
      break;
    case 5:
      currentCourse(&head);
    case 7:
      exit(0);
    case 8:
      firstCourse(&head);
    default:
      printf("Invalid choice\n");
    }
  }
  return 0;
}
