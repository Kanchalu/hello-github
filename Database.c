#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int id;
    float marks;
};

int main() {
    struct Student* students = NULL;
    int studentCount = 0;
    int choice;

    do {
        printf("\n===== Dynamic Student Database =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char newName[50];
                int newID;
                float newMarks;
                printf("Enter student name: ");
                scanf(" %49[^\n]", newName);
                printf("Enter student ID: ");
                scanf("%d", &newID);
                printf("Enter student marks: ");
                scanf("%f", &newMarks);

                struct Student* temp = realloc(students, (studentCount + 1) * sizeof(struct Student));
                if (temp == NULL) {
                    printf("Error: Could not allocate memory to add a new student.\n");
                } else {
                    students = temp;
                    strcpy(students[studentCount].name, newName);
                    students[studentCount].id = newID;
                    students[studentCount].marks = newMarks;
                    printf("New student added successfully!\n");
                    studentCount++;
                }
                break;
            }
            case 2:
                if (studentCount == 0) {
                    printf("The database is currently empty. Please add students first.\n");
                } else {
                    printf("\n===== All Student Records =====\n");
                    for (int i = 0; i < studentCount; i++) {
                        printf("Student %d:\n", i + 1);
                        printf("  Name: %s\n", students[i].name);
                        printf("  ID: %d\n", students[i].id);
                        printf("  Marks: %.2f\n", students[i].marks);
                        printf("------------------------------\n");
                    }
                }
                break;
            case 3: {
                int searchID;
                int found = 0;
                printf("Enter the ID of the student you want to search for: ");
                scanf("%d", &searchID);
                for (int i = 0; i < studentCount; i++) {
                    if (students[i].id == searchID) {
                        printf("\nStudent Found!\n");
                        printf("  Name: %s\n", students[i].name);
                        printf("  ID: %d\n", students[i].id);
                        printf("  Marks: %.2f\n", students[i].marks);
                        found = 1;
                        break;
                    }
                }
                if (found == 0) {
                    printf("No student with ID %d found.\n", searchID);
                }
                break;
            }
            case 4: {
                int deleteID;
                int foundIndex = -1;
                printf("Enter the ID of the student to delete: ");
                scanf("%d", &deleteID);
                for (int i = 0; i < studentCount; i++) {
                    if (students[i].id == deleteID) {
                        foundIndex = i;
                        break;
                    }
                }
                if (foundIndex != -1) {
                    for (int i = foundIndex; i < studentCount - 1; i++) {
                        students[i] = students[i + 1];
                    }
                    studentCount--;
                    if (studentCount > 0) {
                        struct Student* temp = realloc(students, studentCount * sizeof(struct Student));
                        if (temp == NULL) {
                            printf("Warning: Failed to reallocate memory after deletion, but the student was removed.\n");
                        } else {
                            students = temp;
                        }
                    } else {
                        free(students);
                        students = NULL;
                    }
                    printf("Student with ID %d deleted successfully!\n", deleteID);
                } else {
                    printf("No student with ID %d found.\n", deleteID);
                }
                break;
            }
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
                break;
        }
    } while (choice != 5);
    free(students);
    return 0;
}
