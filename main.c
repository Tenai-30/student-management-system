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
void add_student();
void display_students();
void search_student();
void update_student();
void best_student();

float calculate_average(float marks[]);
char calculate_grade(float average);
void clear_input_buffer();

int main() {
    int choice;

    printf("\n==================================================\n");
    printf("     WELCOME TO STUDENT MANAGEMENT SYSTEM\n");
    printf("==================================================\n");

    while (1) {
        display_menu();
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch(choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                update_student();
                break;
            case 5:
                best_student();
                break;
            case 6:
                printf("\nThank you for using Student Management System!\n");

                return 0;
            default:
                printf("\nInvalid choice! Please enter 1-6.\n");
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
//Adding student function
void add_student() {

    int i;

    if (student_count >= MAX_STUDENTS) {
        printf("\nMaximum students reached.\n");
        return;
    }

    printf("\n--- ADD STUDENT ---\n");

    printf("Enter name: ");
    fgets(students[student_count].name, 50, stdin);

    students[student_count].name[
        strcspn(students[student_count].name, "\n")
    ] = '\0';

    printf("Enter admission number: ");
    fgets(students[student_count].admission_no, 20, stdin);

    students[student_count].admission_no[
        strcspn(students[student_count].admission_no, "\n")
    ] = '\0';

    printf("Enter age: ");
    scanf("%d", &students[student_count].age);

    for (i = 0; i < SUBJECTS; i++) {

        do {

            printf("Enter marks for subject %d: ", i + 1);
            scanf("%f", &students[student_count].marks[i]);

            if (students[student_count].marks[i] < 0 ||
                students[student_count].marks[i] > 100) {

                printf("Marks must be between 0 and 100.\n");
            }

        } while (students[student_count].marks[i] < 0 ||
                 students[student_count].marks[i] > 100);
    }

    clear_input_buffer();

    students[student_count].average =
        calculate_average(students[student_count].marks);

    students[student_count].grade =
        calculate_grade(students[student_count].average);

    printf("\nStudent added successfully!\n");
    printf("Average: %.2f\n",
           students[student_count].average);

    printf("Grade: %c\n",
           students[student_count].grade);

    student_count++;
}

float calculate_average(float marks[]) {
    int i;
    float sum = 0;
    for ( i = 0; i < SUBJECTS; i++) {
        sum += marks[i];
    }
    return sum / SUBJECTS;
}

char calculate_grade(float average) {
    if (average >= 90) return 'A';
    else if (average >= 80) return 'B';
    else if (average >= 70) return 'C';
    else if (average >= 60) return 'D';
    else if (average >= 50) return 'E';
    else return 'F';
}
void display_students() {

    int i, j;

    if (student_count == 0) {
        printf("\nNo students available.\n");
        return;
    }

    printf("\n--- ALL STUDENTS ---\n");

    for (i = 0; i < student_count; i++) {

        printf("\nStudent %d\n", i + 1);

        printf("Name: %s\n", students[i].name);
        printf("Admission No: %s\n", students[i].admission_no);
        printf("Age: %d\n", students[i].age);

        for (j = 0; j < SUBJECTS; j++) {
            printf("Subject %d: %.2f\n",
                   j + 1,
                   students[i].marks[j]);
        }

        printf("Average: %.2f\n", students[i].average);
        printf("Grade: %c\n", students[i].grade);
    }
}
//search student
void search_student() {

    char adm[20];
    int i;
    int found = 0;

    printf("Enter admission number: ");

    fgets(adm, 20, stdin);

    adm[strcspn(adm, "\n")] = '\0';

    for (i = 0; i < student_count; i++) {

        if (strcmp(students[i].admission_no, adm) == 0) {

            printf("\nStudent Found\n");

            printf("Name: %s\n", students[i].name);
            printf("Admission No: %s\n",
                   students[i].admission_no);

            printf("Age: %d\n", students[i].age);
            printf("Average: %.2f\n",
                   students[i].average);

            printf("Grade: %c\n",
                   students[i].grade);

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nStudent not found.\n");
    }
}
//update student in4
void update_student() {

    char adm[20];
    int i, j;

    printf("Enter admission number: ");

    fgets(adm, 20, stdin);

    adm[strcspn(adm, "\n")] = '\0';

    for (i = 0; i < student_count; i++) {

        if (strcmp(students[i].admission_no, adm) == 0) {

            printf("\nEnter new marks:\n");

            for (j = 0; j < SUBJECTS; j++) {

                do {

                    printf("Subject %d: ", j + 1);

                    scanf("%f",
                          &students[i].marks[j]);

                    if (students[i].marks[j] < 0 ||
                        students[i].marks[j] > 100) {

                        printf("Invalid marks.\n");
                    }

                } while (students[i].marks[j] < 0 ||
                         students[i].marks[j] > 100);
            }

            clear_input_buffer();

            students[i].average =
                calculate_average(students[i].marks);

            students[i].grade =
                calculate_grade(students[i].average);

            printf("\nStudent updated successfully.\n");

            return;
        }
    }

    printf("\nStudent not found.\n");
}
//display best student
void best_student() {

    int i;
    int best = 0;

    if (student_count == 0) {
        printf("\nNo students available.\n");
        return;
    }

    for (i = 1; i < student_count; i++) {

        if (students[i].average >
            students[best].average) {

            best = i;
        }
    }

    printf("\n--- BEST STUDENT ---\n");

    printf("Name: %s\n",
           students[best].name);

    printf("Admission No: %s\n",
           students[best].admission_no);

    printf("Average: %.2f\n",
           students[best].average);

    printf("Grade: %c\n",
           students[best].grade);
}
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

