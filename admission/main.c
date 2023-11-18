#include <stdio.h>
#include <string.h>

int main() {
    char name[50];
    char grade[3];
    char course[20];

    // Input student's name
    printf("Enter student's name: ");
    fgets(name, sizeof(name), stdin);

    // Input student's grade
    printf("Enter student's grade: ");
    fgets(grade, sizeof(grade), stdin);

    // Check the grade and determine the course
    switch (grade[0]) {
        case 'A':
        case 'A-':
        case 'B+':
        case 'B':
        case 'B-':
        case 'C+':
            strcpy(course, "Degree");
            break;
        case 'C':
        case 'D+':
            strcpy(course, "Diploma");
            break;
        case 'D':
            strcpy(course, "Certificate");
            break;
        case 'D-':
        case 'E':
            strcpy(course, "Artisan");
            break;
        default:
            printf("Invalid grade entered.\n");
            return 1;
    }

    // Check for transitions between courses
    if (strcmp(course, "Diploma") == 0) {
        printf("Since the student has completed a Diploma, they can do a Degree course.\n");
    } else if (strcmp(course, "Certificate") == 0) {
        printf("Since the student has a Certificate, they can do a Diploma course.\n");
    } else if (strcmp(course, "Artisan") == 0) {
        printf("Since the student is an Artisan, they can do a Certificate course.\n");
    } else {
        printf("No further course transitions are available for this student.\n");
    }

    // Display the student's details
    printf("Student's Name: %s", name);
    printf("Student's Grade: %s\n", grade);
    printf("Recommended Course: %s\n", course);

    return 0;
}
