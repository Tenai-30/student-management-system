
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 300
#define SUBJECTS 3

// Structure to hold student information
struct Student {
    char name[50];
    char admission_no[20];
    int age;
    float marks[SUBJECTS];
    float average;
    char grade;
};

// Global array of structures
struct Student students[MAX_STUDENTS];
int student_count = 0;

// Function prototypes
void display_menu();

int main() {
    int choice;

    printf("\n==================================================\n");
    printf("     WELCOME TO STUDENT MANAGEMENT SYSTEM\n");
    printf("==================================================\n");

    while (1) {
        display_menu();
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

        switch(choice ) {
      case 1:
        printf("\nAdd student\n");
        break;
        case 2:
                printf("\nDisplay All Students selected\n");
                break;

            case 3:
                printf("\nSearch Student selected\n");
                break;

            case 4:
                printf("\nUpdate Student Marks selected\n");
                break;

            case 5:
                printf("\nBest Performing Student selected\n");
                break;

            case 6:
                printf("\nThank you for using the system.\n");
                return 0;

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}

void display_menu() {
    printf("\n==================================================\n");
    printf("      STUDENT MANAGEMENT SYSTEM\n");
    printf("==================================================\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student (by Admission No.)\n");
    printf("4. Update Student Marks\n");
    printf("5. Best Performing Student\n");
    printf("6. Exit\n");
    printf("==================================================\n");
}
