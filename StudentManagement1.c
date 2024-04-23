
//*******STUDENT GRADE MANAGEMENT PROJECT IN C LANGUAGE*******


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure to represent a student
struct Student {
    int rollNumber;
    char name[50];
    float marks;
    char grade;
};

// Function prototypes
void addStudent(struct Student students[], int *numStudents);
void displayAllStudents(struct Student students[], int numStudents);
void searchStudent(struct Student students[], int numStudents);
void deleteStudent(struct Student students[], int *numStudents);

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;
    int choice;

    do {
        // Display menu
        printf("\nStudent Record Management System\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &numStudents);
                break;
            case 2:
                displayAllStudents(students, numStudents);
                break;
            case 3:
                searchStudent(students, numStudents);
                break;
            case 4:
                deleteStudent(students, &numStudents);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

void addStudent(struct Student students[], int *numStudents) {
    if (*numStudents >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }

    printf("\nEnter details of student %d:\n", *numStudents + 1);
    printf("Roll Number: ");
    scanf("%d", &students[*numStudents].rollNumber);
    printf("Name: ");
    scanf("%s", students[*numStudents].name);
    printf("Marks: ");
    scanf("%f", &students[*numStudents].marks);
    printf("Grade: ");
    scanf(" %c", &students[*numStudents].grade);  // Corrected format specifier for grade

    (*numStudents)++;
}

void displayAllStudents(struct Student students[], int numStudents) {
    if (numStudents == 0) {
        printf("No records found.\n");
        return;
    }

    printf("\nAll Students:\n");
    printf("Roll Number\tName\t\tMarks\tGrade\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%d\t\t%s\t\t%.2f\t%c\n", students[i].rollNumber, students[i].name, students[i].marks, students[i].grade);
    }
}

void searchStudent(struct Student students[], int numStudents) {
    int rollNumber;
    printf("Enter roll number to search: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("\nStudent found:\n");
            printf("Roll Number\tName\t\tMarks\tGrade\n");
            printf("%d\t\t%s\t\t%.2f\t%c\n", students[i].rollNumber, students[i].name, students[i].marks, students[i].grade);
            return;
        }
    }

    printf("Student with roll number %d not found.\n", rollNumber);
}

void deleteStudent(struct Student students[], int *numStudents) {
    int rollNumber;
    printf("Enter roll number to delete: ");
    scanf("%d", &rollNumber);

    int found = 0;
    for (int i = 0; i < *numStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            found = 1;
            // Shift elements to left to overwrite the deleted record
            for (int j = i; j < *numStudents - 1; j++) {
                students[j] = students[j + 1];
            }
            (*numStudents)--;
            printf("Student with roll number %d deleted successfully.\n", rollNumber);
            break;
        }
    }

    if (!found) {
        printf("Student with roll number %d not found.\n", rollNumber);
    }
}