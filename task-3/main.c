#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


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

void printWelcomeMessage() {
    printf("==========================\n");
    printf("| Welcome to distance converstion |\n");
    printf("==========================\n");
}

int main() {
    char inputString[20];
    float distanceInMeter, distanceInCM;
    
    printWelcomeMessage();
    printf("\n\n");


    
    // Input balance and cost
    printf("Enter Distance in KM: ");
    scanf("%s", inputString);

    printf("\n");

    float distanceInKM = sanitizeInput(inputString);

    distanceInMeter = distanceInKM * 1000;
    distanceInCM = distanceInMeter * 100;

    char *distanceInKMString = addThousandSeparator(distanceInKM);
    char *distanceInMeterString = addThousandSeparator(distanceInMeter);
    char *distanceInCMString = addThousandSeparator(distanceInCM);


    printf("==========================\n");
    printf("|Convertion Results|\n");
    printf("==========================\n");
    printf("| %-10s | %10s \n", "KM", distanceInKMString);
    printf("| %-10s | %10s \n", "Meters",distanceInMeterString);
    printf("| %-10s | %10s \n", "CM", distanceInCMString);
    printf("==========================\n");


    return 0;
}
