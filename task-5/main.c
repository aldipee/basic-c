#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void printSeperator(int length, char seperator){
    for (int i = 0; i < length; i++)
    {
        printf("%c", seperator);
    }
    printf("\n");
}


// Ansi Output format styling
// https://gist.github.com/radxene/f1e286301763b921baf06074ea46c800
#define ANSI_COLOR_GREEN        "\x1b[32m"
#define ANSI_COLOR_BLUE         "\x1b[34m"
#define ANSI_COLOR_BLACK        "\x1b[30m"
#define ANSI_COLOR_RED          "\x1b[31m"
#define ANSI_COLOR_YELLOW       "\x1b[33m"
#define ANSI_COLOR_MAGENTA      "\x1b[35m"
#define ANSI_COLOR_CYAN         "\x1b[36m"
#define ANSI_COLOR_WHITE        "\x1b[37m"
#define ANSI_STYLE_BOLD         "\x1b[1m"
#define ANSI_STYLE_ITALIC       "\x1b[3m"
#define ANSI_STYLE_UNDERLINE    "\x1b[4m"
#define ANSI_RESET_ALL          "\x1b[0m"


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




int main(){

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
        
        printf(ANSI_COLOR_GREEN "Enter Quiz score for %s: " ANSI_RESET_ALL, studentNames[i]);
        scanf("%f", &studentQuizScores[i]);

        printf(ANSI_COLOR_BLUE "Enter Assesment score for %s: " ANSI_RESET_ALL, studentNames[i]);
        scanf("%f", &studentAssesmentScores[i]);

        printf(ANSI_COLOR_YELLOW "Enter Absen score for %s: " ANSI_RESET_ALL, studentNames[i]);
        scanf("%f", &studentAbsenScores[i]);

        printf(ANSI_COLOR_CYAN "Enter Task score for %s: " ANSI_RESET_ALL, studentNames[i]);
        scanf("%f", &studentTaskScores[i]);

        printf(ANSI_COLOR_MAGENTA "Enter Exam score for %s: " ANSI_RESET_ALL, studentNames[i]);
        scanf("%f", &studentExamScores[i]);

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
    printf("| %-20s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s |\n", "Student Name", "Quiz", "Assesment","Absen", "Task", "Exam", "Average", "Grade");
    printSeperator(115, '-');
    for (int i = 0; i < totalStudent; i++)
    {
        printf("| %-20s | %-10.2f | %-10.2f | %-10.2f | %-10.2f | %-10.2f | %-10.2f | %-10s |\n", studentNames[i], studentQuizScores[i], studentAssesmentScores[i], studentAbsenScores[i], studentTaskScores[i], studentExamScores[i], studentAverageScores[i], studentGrades[i]);
    }
    printSeperator(115, '-');




    
    
    
}


