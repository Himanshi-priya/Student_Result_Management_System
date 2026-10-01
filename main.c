#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define SUBJECTS 5
#define NAME_LEN 50

typedef struct {
    int rollNo;
    char name[NAME_LEN];
    float marks[SUBJECTS];
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

float calculateTotal(Student s) {
    float total = 0;
    for (int i = 0; i < SUBJECTS; i++) {
        total += s.marks[i];
    }
    return total;
}

float calculateAverage(Student s) {
    return calculateTotal(s) / SUBJECTS;
}

int findStudent(int rollNo) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNo == rollNo) {
            return i;
        }
    }
    return -1;
}

void addStudent(void) {
    if (studentCount >= MAX_STUDENTS) {
        printf("\nStudent limit reached.\n");
        return;
    }

    Student s;

    printf("\nEnter Roll Number: ");
    scanf("%d", &s.rollNo);

    if (findStudent(s.rollNo) != -1) {
        printf("Roll number already exists.\n");
        return;
    }

    printf("Enter Student Name: ");
    scanf(" %49[^\n]", s.name);

    printf("Enter marks for %d subjects (out of 100):\n", SUBJECTS);
    for (int i = 0; i < SUBJECTS; i++) {
        do {
            printf("Subject %d: ", i + 1);
            scanf("%f", &s.marks[i]);
            if (s.marks[i] < 0 || s.marks[i] > 100)
                printf("Enter marks between 0 and 100.\n");
        } while (s.marks[i] < 0 || s.marks[i] > 100);
    }

    students[studentCount++] = s;
    printf("Student record added successfully.\n");
}

void displayStudent(Student s) {
    printf("\nRoll No : %d", s.rollNo);
    printf("\nName    : %s", s.name);
    printf("\nMarks   : ");
    for (int i = 0; i < SUBJECTS; i++) {
        printf("%.2f ", s.marks[i]);
    }
    printf("\nTotal   : %.2f / %d", calculateTotal(s), SUBJECTS * 100);
    printf("\nAverage : %.2f%%\n", calculateAverage(s));
}

void displayAll(void) {
    if (studentCount == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n========== ALL STUDENT RECORDS ==========\n");
    for (int i = 0; i < studentCount; i++) {
        displayStudent(students[i]);
        printf("-----------------------------------------\n");
    }
}

void searchStudent(void) {
    int rollNo;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &rollNo);

    int index = findStudent(rollNo);
    if (index == -1) {
        printf("Student not found.\n");
    } else {
        printf("\nStudent found:\n");
        displayStudent(students[index]);
    }
}

void updateStudent(void) {
    int rollNo;
    printf("\nEnter Roll Number to update: ");
    scanf("%d", &rollNo);

    int index = findStudent(rollNo);
    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    printf("Enter new Student Name: ");
    scanf(" %49[^\n]", students[index].name);

    printf("Enter new marks:\n");
    for (int i = 0; i < SUBJECTS; i++) {
        do {
            printf("Subject %d: ", i + 1);
            scanf("%f", &students[index].marks[i]);
            if (students[index].marks[i] < 0 || students[index].marks[i] > 100)
                printf("Enter marks between 0 and 100.\n");
        } while (students[index].marks[i] < 0 || students[index].marks[i] > 100);
    }

    printf("Student record updated successfully.\n");
}

void deleteStudent(void) {
    int rollNo;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &rollNo);

    int index = findStudent(rollNo);
    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    for (int i = index; i < studentCount - 1; i++) {
        students[i] = students[i + 1];
    }

    studentCount--;
    printf("Student record deleted successfully.\n");
}

void showTopper(void) {
    if (studentCount == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    int topperIndex = 0;
    for (int i = 1; i < studentCount; i++) {
        if (calculateAverage(students[i]) > calculateAverage(students[topperIndex])) {
            topperIndex = i;
        }
    }

    printf("\n========== TOPPER ==========\n");
    displayStudent(students[topperIndex]);
}

void generateReport(void) {
    if (studentCount == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    float classTotal = 0;
    int topperIndex = 0;

    printf("\n================ STUDENT RESULT REPORT ================\n");
    printf("%-8s %-20s %-10s %-10s\n", "Roll", "Name", "Total", "Average");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < studentCount; i++) {
        float total = calculateTotal(students[i]);
        float average = calculateAverage(students[i]);
        classTotal += average;

        if (average > calculateAverage(students[topperIndex])) {
            topperIndex = i;
        }

        printf("%-8d %-20s %-10.2f %-10.2f\n",
               students[i].rollNo, students[i].name, total, average);
    }

    printf("--------------------------------------------------------\n");
    printf("Number of Students : %d\n", studentCount);
    printf("Class Average      : %.2f%%\n", classTotal / studentCount);
    printf("Topper             : %s (Roll No: %d)\n",
           students[topperIndex].name, students[topperIndex].rollNo);
    printf("========================================================\n");
}

void menu(void) {
    printf("\n\n===== STUDENT RESULT MANAGEMENT SYSTEM =====\n");
    printf("1. Add Student Record\n");
    printf("2. Display All Students\n");
    printf("3. Search Student\n");
    printf("4. Update Student\n");
    printf("5. Delete Student\n");
    printf("6. Show Topper\n");
    printf("7. Generate Report\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
}

int main(void) {
    int choice;

    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: showTopper(); break;
            case 7: generateReport(); break;
            case 8: printf("\nThank you for using the system.\n"); break;
            default: printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
