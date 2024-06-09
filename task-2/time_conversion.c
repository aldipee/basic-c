#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "time_conversion.h"

char* addThousandSeparator(int number) {
    char numStr[20];
    sprintf(numStr, "%d", number); // Convert the number to a string

    int len = strlen(numStr);
    int commaCount = (len - 1) / 3;
    int resultSize = len + commaCount + 1; // +1 for the null-terminator
    char *result = malloc(resultSize); // Allocate memory for the result string

    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    int resultIndex = resultSize - 1;
    result[resultIndex--] = '\0'; // Null-terminate the result string

    int numIndex = len - 1;
    for (int i = 1; numIndex >= 0; i++) {
        result[resultIndex--] = numStr[numIndex--];
        if (i % 3 == 0 && numIndex >= 0) {
            result[resultIndex--] = ',';
        }
    }

    return result;
}


int isValidNumericNumber(char *inputString){
    // Check if the input is a valid number
    int i = 0;
    for (; inputString[i] != '\0'; i++)
    {
      // ref: https://www.programiz.com/c-programming/library-function/ctype.h/isdigit
      if(isdigit(inputString[i]) == 0){
          return 0;
      }
    }
    
    return 1;
}

int sanitizeInput(char *string){
    int isValidNumber = isValidNumericNumber(string);
       while (!isValidNumber)
    {
        // Ask the user to enter a valid number
        puts("Please enter a valid number: ");
        scanf("%s", string);
        isValidNumber = isValidNumericNumber(string);
    }
    // ref https://www.geeksforgeeks.org/convert-string-to-int-in-c/
    return atoi(string);
}

void printWelcomeMessage(){
    printf("==========================\n");
    printf("| Welcome to time converstion |\n");
    printf("==========================\n");
}



void runTimeConversion(){
    // Convert hour to seconds, minute to seconds
    char inputString;
    int timeInSeconds;

    printWelcomeMessage();


    puts("Enter the time in seconds: ");
    scanf("%s", &inputString);
    
    // now assume the number is valid
    // convert the string to an integer
    timeInSeconds = sanitizeInput(&inputString);
    int timeInHours = timeInSeconds / 3600;
    int timeInDays = timeInHours / 24;
    int timeInMinutes = timeInSeconds / 60;
    int timeInWeeks = timeInDays / 7;
    int timeInMonths = timeInWeeks / 4;
    

    char* timeInMinutesString = addThousandSeparator(timeInMinutes);
    char* timeInSecondsString = addThousandSeparator(timeInSeconds);
    char* timeInHoursString = addThousandSeparator(timeInHours);
    char* timeInDaysString = addThousandSeparator(timeInDays);
    char* timeInWeeksString = addThousandSeparator(timeInWeeks);
    char* timeInMonthsString = addThousandSeparator(timeInMonths);
    printf("==========================\n");
    printf("|Convertion Results|\n");
    printf("==========================\n");
    printf("| %-10s | %10s \n", "Seconds", timeInSecondsString);
    printf("| %-10s | %10s \n", "Minutes",timeInMinutesString);
    !!timeInHours && printf("| %-10s | %10s \n", "Hours", timeInHoursString);
    !!timeInDays && printf("| %-10s | %10s \n", "Days", timeInDaysString);
    !!timeInWeeks && printf("| %-10s | %10s \n", "Weeks", timeInWeeksString);
    !!timeInMonths && printf("| %-10s | %10s \n", "Months", timeInMonthsString);
    printf("==========================\n");
}