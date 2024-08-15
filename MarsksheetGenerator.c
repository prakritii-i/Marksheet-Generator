#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_SCHOOL_NAME_LENGTH 40
#define DOB_LENGTH 15

char name[MAX_NAME_LENGTH], fa_name[MAX_NAME_LENGTH], mo_name[MAX_NAME_LENGTH], s_name[MAX_SCHOOL_NAME_LENGTH], dob[DOB_LENGTH];
int roll_number, clas, hi_marks, eng_marks, san_marks, math_marks, sci_marks, so_sci_marks;

void generate_marksheet() {
    int grand_total;
    float percentage;

    grand_total = hi_marks + eng_marks + san_marks + math_marks + sci_marks + so_sci_marks;
    percentage = grand_total / 6.0; // Use floating-point division

    printf("\n------------------------------------------------------------------------------------\n");
    printf("|                          SECONDARY EDUCATION EXAMINATION                        |\n");
    printf("|------------------------------------------------------------------------------------\n");
    printf("|Student name: %s\t\tClass: %d\t\tRoll Number: %d\n", name, clas, roll_number);
    printf("|Father name: %s\n", fa_name);
    printf("|Mother name: %s\n", mo_name);
    printf("|Date of birth: %s\n", dob);
    printf("|School name: %s\n", s_name);
    printf("|------------------------------------------------------------------------------------\n");
    printf("|\tSUBJECTS      \tFULL MARKS\tPASS MARKS\tOBTAINED MARKS\n");
    printf("|------------------------------------------------------------------------------------\n");
    printf("|\tNEPALI       \t  100      \t   33       \t    %d\n", hi_marks);
    printf("|\tENGLISH      \t  100      \t   33       \t    %d\n", eng_marks);
    printf("|\tHPE          \t  100      \t   33       \t    %d\n", san_marks);
    printf("|\tMATHEMATICS   \t  100      \t   33       \t    %d\n", math_marks);
    printf("|\tSCIENCE       \t  100      \t   33       \t    %d\n", sci_marks);
    printf("|\tSOCIAL STUDIES\t  100      \t   33       \t    %d\n", so_sci_marks);
    printf("|------------------------------------------------------------------------------------\n");
    printf("|\t              \t  600    |    GRAND TOTAL\t    %d\n", grand_total);
    printf("|\t              \t  600    |     PERCENTAGE\t    %.2f%%\n", percentage);
    printf("|------------------------------------------------------------------------------------\n");

    if (percentage >= 81 && percentage <= 100) {
        printf("|RESULT : PASS IN FIRST DIVISION\n");
        printf("|GRADE  : A+\n");
    } else if (percentage >= 60 && percentage < 81) {
        printf("|RESULT : PASS IN FIRST DIVISION\n");
        printf("|GRADE  : A\n");
    } else if (percentage >= 41 && percentage < 60) {
        printf("|RESULT : PASS IN SECOND DIVISION\n");
        printf("|GRADE  : B\n");
    } else if (percentage >= 31 && percentage < 41) {
        printf("|RESULT : PASS IN THIRD DIVISION\n");
        printf("|GRADE  : C\n");
    } else {
        printf("|RESULT : Fail\n");
        printf("|GRADE  : D\n");
    }
    printf("|------------------------------------------------------------------------------------\n\n");
}

void take_user_info() {
    char yesNo;

    // Use fgets to read strings and remove any trailing newline characters
    printf("Enter your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline character if present

    printf("Enter father name: ");
    fgets(fa_name, MAX_NAME_LENGTH, stdin);
    fa_name[strcspn(fa_name, "\n")] = '\0'; // Remove newline character if present

    printf("Enter mother name: ");
    fgets(mo_name, MAX_NAME_LENGTH, stdin);
    mo_name[strcspn(mo_name, "\n")] = '\0'; // Remove newline character if present

    printf("Enter school name: ");
    fgets(s_name, MAX_SCHOOL_NAME_LENGTH, stdin);
    s_name[strcspn(s_name, "\n")] = '\0'; // Remove newline character if present

    printf("Enter date of birth: ");
    fgets(dob, DOB_LENGTH, stdin);
    dob[strcspn(dob, "\n")] = '\0'; // Remove newline character if present

    printf("Enter class: ");
    scanf("%d", &clas);

    printf("Enter roll No.: ");
    scanf("%d", &roll_number);

    // Validate and read marks
    do {
        printf("Nepali marks: ");
        scanf("%d", &hi_marks);
    } while (hi_marks < 0 || hi_marks > 100);

    do {
        printf("English marks: ");
        scanf("%d", &eng_marks);
    } while (eng_marks < 0 || eng_marks > 100);

    do {
        printf("HPE marks: ");
        scanf("%d", &san_marks);
    } while (san_marks < 0 || san_marks > 100);

    do {
        printf("Mathematics marks: ");
        scanf("%d", &math_marks);
    } while (math_marks < 0 || math_marks > 100);

    do {
        printf("Science marks: ");
        scanf("%d", &sci_marks);
    } while (sci_marks < 0 || sci_marks > 100);

    do {
        printf("Social studies marks: ");
        scanf("%d", &so_sci_marks);
    } while (so_sci_marks < 0 || so_sci_marks > 100);

    // Clear the input buffer to handle leftover newline
    while (getchar() != '\n');

    printf("\nIf you want to generate your marksheet then press 'Y' otherwise 'N': ");
    scanf(" %c", &yesNo); // Note the space before %c to skip any newline character

    if (yesNo == 'y' || yesNo == 'Y') {
        generate_marksheet();
    } else {
        exit(0);
    }
}

int main() {
    char yesNo;
    printf("\n             **Welcome to marksheet generation project**               \n\n");
    printf("If you want to generate your marksheet ");
    printf("then you have to provide some information\n");
    printf("If you want to provide information then press 'Y' otherwise 'N': ");
    scanf(" %c", &yesNo); // Note the space before %c to skip any newline character

    if (yesNo == 'y' || yesNo == 'Y') {
        // Clear input buffer before taking new inputs
        while (getchar() != '\n');
        take_user_info();
    } else {
        exit(0);
    }
}
