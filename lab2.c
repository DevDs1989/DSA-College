
/* Build a Simplified employee management system that uses structs,array of structs and function pointer in a structure to perform operations 
 * like displaying employee details finding the highest salary and calculate the highest salary
 *
 * Problem Statement:
 * Allow input of details for an employee
 * Display the detail of all employees
 * Find and display the employee with the highest salary
 * Calculate the average salary
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee{
  char name[20];
  int salary;
  void (*print_employees)(struct Employee*);
  int (*highest_salary)(struct Employee*, int count);
  int (*avg_salary)(struct Employee*, int count);
};



void display(struct Employee *emp){
  printf("Employee name: %s", emp->name );
  printf("Employee salary: %d", emp->salary);
}

int highestSalary(struct Employee *employees, int count) {
  if (count == 0) return -1;

  int highest = employees[0].salary;
  int index = 0; 

  for (int i = 1; i < count; ++i) {
    if (employees[i].salary > highest) {
      highest = employees[i].salary;
      index = i;
    }
  }
  return index; 
}

int averageSalary(struct Employee *employees, int count) {
  if (count == 0) return -1; 
  int sum = 0;
  for (int i = 0; i < count; ++i) {

    sum += employees[i].salary;
  }
  return sum / count;
}
int main()
{
  struct Employee *employees = malloc(100*sizeof(struct Employee));
  struct Employee employee_functions;
  employee_functions.print_employees = display;
  employee_functions.highest_salary = highestSalary;
  employee_functions.avg_salary = averageSalary;
  int count = 0,choice,highest,average, highest_index;
  char temp_name[20];

  printf("\n1.Enter Employee\t2.Find highest salary\t3.Calculate average salary\n4.Exit\n");

  while (1) {
  printf("Enter choice: ");
  scanf("%d",&choice);
    switch (choice) {
    case 1:
      printf("Enter Employee Name: ");
      scanf("%s", &temp_name);
      strcpy(employees[count].name,temp_name);
      printf("Enter Employee Salary: ");
      scanf("%d" ,&employees[count].salary);
      count++;
      break;
    case 2:
   highest_index = employee_functions.highest_salary(employees,count);
  if (highest_index != -1) {
  printf("The employee with the highest salary is %s and their salary is %d.\n", employees[highest_index].name, employees[highest_index].salary);
  } else {
  printf("No employees found.\n");
  }
break;
    case 3:

   average = employee_functions.avg_salary(employees, count);
      if (average!= -1) {
        printf("The average salary is %d.\n", average);
      } else {
        printf("No employees found.\n");
      }
      break;
      case 4:
      printf("Exiting");
      exit(1);
    default:
      printf("\nWrong Choice\n");

    }
  }
  employees[0].salary = 1000;

  employee_functions.print_employees(&employees[0]);


  return 0;
}
