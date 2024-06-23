#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "custom_utils.h"


void printWelcomeMessageScoring(){
    printf("\n");
    printSeperator(60, '=');
    printf("| Selamat Datang di Centoso University \n");
    printSeperator(60, '-');
    printf("| Menuju Indonesia Emas 2045 (?)\n");
    printSeperator(60, '=');
    printf("\n");
}


char *getGradeGroupingByScore(float score){
    if(score > 85.0){
        return "A";
    } else if(score > 75.0 && score <= 85.0){
        return "B";
    } else if(score > 65.0 && score <= 75.0){
        return "C";
    } else if(score > 55.0 && score <= 65.0){
        return "D";
    } else {
        return "E";
    }
}


// Full Name Input Validation

int validateStringOnly(char *string) {
    int i = 0;
    for (; string[i] != '\0'; i++) {
        if (!isalpha(string[i]) && string[i] != ' ') {
            return 0;
        }
    }
    return 1;
}

char* sanitizeStudentNameInput(char *string){
    int isValidName = validateStringOnly(string);
    while (!isValidName)
    {
        // Ask the user to enter a valid number
        puts("Invalid name input! Please enter a valid name: ");
        scanf(" %[^\n]s", string);
        isValidName = validateStringOnly(string);
    }
    return string;
}


// Student Score Input Validation
int validateScoreOnly(char *string) {
    char *endptr;
    float score = strtof(string, &endptr);

    // Check if the entire string was converted to a float
    if (*endptr != '\0') {
        return 0;
    }

    // Check if the score is between 0 and 100
    if (score < 0.0 || score > 100.0) {
        return 0;
    }

    return 1;
}

float sanitizeScoreInput(char *typeScore, char studentName[100], const char *textColor) {
    char input[100];
    int isValidScore = 0;
    
    while (!isValidScore) {
        // Ask the user to enter a valid score
       printf("%sEnter %s (0-100) for %s: " ANSI_RESET_ALL,textColor, studentName, typeScore);
       scanf(" %[^\n]s", input);
       isValidScore = validateScoreOnly(input);
        if (!isValidScore) {
            printf("\n");
            puts(ANSI_COLOR_RED ANSI_STYLE_ITALIC "Invalid score input! Please enter a valid score (0-100)." ANSI_RESET_ALL);
        }
    }

    return strtof(input, NULL);


}

int runStudentScoringSystem(){
     // array of string to hold student names
    char studentNames[20][100];
    // array of integer to hold student quiz scores
    float studentQuizScores[20];
    // array of float to hold student assesment scores
    float studentAssesmentScores[20];
    // array of fload to hold student absen scores
    float studentAbsenScores[20];
    // array of float to hold student task scores
    float studentTaskScores[20];
    // array of float to hold student exam scores
    float studentExamScores[20];

    // array of float to hold student average scores
    float studentAverageScores[20];
    // array of string to hold student grades
    char studentGrades[20][3];

    

    int indexInputCounter = 0;

    printWelcomeMessageScoring();

    // loop to get student names and scores
    printf("Enter student data: \n");
    int totalStudent = 2;

    for (int i = 0; i < totalStudent; i++)
    {
        printf("%d). Enter student name: ", i+1);
        // it seems like scanf is not able to read string with space, so we need to use this scanf(" %[^\n]s", studentNames[i]);
        // ref: https://stackoverflow.com/questions/6282198/reading-string-from-input-with-space-character
        scanf(" %[^\n]s", studentNames[i]);
        strcpy(studentNames[i], sanitizeStudentNameInput(studentNames[i]));
        
        studentQuizScores[i] = sanitizeScoreInput("Quiz Score", studentNames[i], ANSI_COLOR_GREEN);

        // printf(ANSI_COLOR_BLUE "Enter Assesment score for %s: " ANSI_RESET_ALL, studentNames[i]);
        // scanf("%f", &studentAssesmentScores[i]);

        studentAssesmentScores[i] = sanitizeScoreInput("Assesment Score", studentNames[i], ANSI_COLOR_BLUE);

        // printf(ANSI_COLOR_YELLOW "Enter Absen score for %s: " ANSI_RESET_ALL, studentNames[i]);
        // scanf("%f", &studentAbsenScores[i]);

        studentAbsenScores[i] = sanitizeScoreInput("Absen Score", studentNames[i], ANSI_COLOR_YELLOW);

        // printf(ANSI_COLOR_CYAN "Enter Task score for %s: " ANSI_RESET_ALL, studentNames[i]);
        // scanf("%f", &studentTaskScores[i]);

        studentTaskScores[i] = sanitizeScoreInput("Task Score", studentNames[i], ANSI_COLOR_CYAN);

        // printf(ANSI_COLOR_MAGENTA "Enter Exam score for %s: " ANSI_RESET_ALL, studentNames[i]);
        // scanf("%f", &studentExamScores[i]);

        studentExamScores[i] = sanitizeScoreInput("Exam Score", studentNames[i], ANSI_COLOR_MAGENTA);

        studentAverageScores[i] = (studentQuizScores[i] + studentAssesmentScores[i] + studentAbsenScores[i] + studentTaskScores[i] + studentExamScores[i]) / 5;
        // In c, an array is assignable only in the initialization period, citizen1.name is an array of char type. To solve your problem, you may use this:
        // strcpy(citizen1, "John Doe");
        // Ref: https://stackoverflow.com/questions/37016819/expression-must-be-modifiable-lvalue-char-array
        // studentGrades[i] = getGradeGroupingByScore(studentAverageScores[i]); -> Not working dude.
        strcpy(studentGrades[i], getGradeGroupingByScore(studentAverageScores[i]));

        printSeperator(20, '-');
    }

    printf("\n");
    printf("Processing student data...\n");
    printf("\n\n");



    printf("Results: \n \n");



    
    // loop to display student data
    printf("| %-3s | %-20s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s |\n", "#", "Student Name", "Quiz", "Assesment","Absen", "Task", "Exam", "Average", "Grade");
    printSeperator(120, '-');
    for (int i = 0; i < totalStudent; i++)
    {
        int serialNumber = i + 1;
        printf("| %-3d | %-20s | %-10.2f | %-10.2f | %-10.2f | %-10.2f | %-10.2f | %-10.2f | %-10s |\n", serialNumber, studentNames[i], studentQuizScores[i], studentAssesmentScores[i], studentAbsenScores[i], studentTaskScores[i], studentExamScores[i], studentAverageScores[i], studentGrades[i]);
    }
    printSeperator(120, '-');
}