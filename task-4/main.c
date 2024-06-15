#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


// Ansi Output format styling
// https://gist.github.com/radxene/f1e286301763b921baf06074ea46c800
#define ANSI_COLOR_GREEN        "\x1b[32m"
#define ANSI_COLOR_BLUE         "\x1b[34m"
#define ANSI_STYLE_BOLD         "\x1b[1m"
#define ANSI_STYLE_ITALIC       "\x1b[3m"
#define ANSI_STYLE_UNDERLINE    "\x1b[4m"
#define ANSI_RESET_ALL          "\x1b[0m"

char *getDescriptiveTotalTranasction(int totalTransaction){
    char *totalTransactionOrder;
    if (totalTransaction == 1)
    {
        totalTransactionOrder = "1st";
    }
    else if (totalTransaction == 2)
    {
        totalTransactionOrder = "2nd";
    }
    else if (totalTransaction == 3)
    {
        totalTransactionOrder = "3rd";
    }
    else
    {
        totalTransactionOrder = "4th";
    }

    return totalTransactionOrder;
}


int getTotalEligibleDiscount(int totalAmountTransaction){
    int totalEligbleDiscount = 0;
    if (totalAmountTransaction >= 200000 && totalAmountTransaction <= 550000){
        totalEligbleDiscount = 10;
    } else if (totalAmountTransaction > 550000 && totalAmountTransaction <= 1000000){
        totalEligbleDiscount = 20;
    }
    else if (totalAmountTransaction > 1000000){
        totalEligbleDiscount = 30;
    }
  

    return totalEligbleDiscount;
}


float getDiscountAmount(int totalAmountTransaction, int totalEligbleDiscount){
    float totalAmountDiscount = 0;
    totalAmountDiscount = (totalAmountTransaction * totalEligbleDiscount) / 100;
    return totalAmountDiscount;
}

char* rupiahFormatter(int number) {
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

    char *formattedResult = malloc(resultSize + 5);
    sprintf(formattedResult, "Rp. %s", result);
    return formattedResult;

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
        puts("Please enter a valid amount: ");
        scanf("%s", string);
        isValidNumber = isValidNumericNumber(string);
    }
    // ref https://www.geeksforgeeks.org/convert-string-to-int-in-c/
    return atoi(string);
}


int main() {
    int totalTransactionThisMount = 1;
    float totalAmountTransaction = 0;
    char totalAmountTransactionInput[20];
    float totalAmountDiscount = 0;
    int totalEligbleDiscount = 0;

    int isShutDown = 0;


    while (!isShutDown)
    {
        /* code */

        char *totalTransactionOrder = getDescriptiveTotalTranasction(totalTransactionThisMount);
        printf("Welcome! This is your %s transaction\n", totalTransactionOrder);

        printf("Enter the total amount of transaction: ");
        scanf("%s", totalAmountTransactionInput);

        totalAmountTransaction = sanitizeInput(totalAmountTransactionInput);

        totalEligbleDiscount = getTotalEligibleDiscount(totalAmountTransaction);
        if(totalTransactionThisMount == 3){
            printf(ANSI_COLOR_GREEN "You are eligible for a 20%% discount for your next transaction\n" ANSI_RESET_ALL);
        }

        if(totalTransactionThisMount == 4){
            totalEligbleDiscount += 20;
            // Reset transaction count
            totalTransactionThisMount = 0;
        }

        totalAmountDiscount = getDiscountAmount(totalAmountTransaction, totalEligbleDiscount);
        float totalAmountAfterDiscount = totalAmountTransaction - totalAmountDiscount;

        char *formattedTotalAmountTransaction = rupiahFormatter(totalAmountTransaction);
        char *formattedTotalAmountDiscount = rupiahFormatter(totalAmountDiscount);
        char *formattedTotalAmountAfterDiscount = rupiahFormatter(totalAmountAfterDiscount);

        totalEligbleDiscount && printf(ANSI_COLOR_BLUE "Congratulations! You are eligible for additional %d discount for this transaction\n" ANSI_RESET_ALL, totalEligbleDiscount);
        printf("============================================\n");
        printf("Subtotal: %s\n", formattedTotalAmountTransaction);
        printf("Total Discount: %s\n", formattedTotalAmountDiscount);
        printf("Total Amount After Discount: %s\n", formattedTotalAmountAfterDiscount);
        printf("\n\n");
        printf("====================================\n");
        printf("[Q] Quit [C] Continue to next transaction\n");
        printf("====================================\n");
        printf("Enter your option: ");
        char option;
        scanf(" %c", &option);
        if (option == 'Q' || option == 'q')
        {
            isShutDown = 1;
        }
        totalTransactionThisMount++;
    }
    
    


}