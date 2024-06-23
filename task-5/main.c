#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "billing_warnet.h"
#include "student_scoring.h"
#include "custom_utils.h"



void printOptions(){
    puts("Please select an option:");
    puts("1). Warnet Billing System");
    puts("2). Access Student Scoring System");
    puts("3). Exit");
}


int main(){

    int selectedOption;

    int isShutDown = 0;

    printOptions();
    printf("Enter your option: ");
    scanf("%d", &selectedOption);
    while (!isShutDown)
    {
        printf("\n");

        switch (selectedOption)
        {
        case 1:
            runWarnetBillingSystem();
            break;

        case 2:
            runStudentScoringSystem();
            break;
        
        default:
            exit(1);
            break;
        }


        printf("\n\n");
        printSeperator(40, '=');
        printf("[Q] Quit [C] Continue run program [M] Main Menu\n");
        printSeperator(40, '=');
        printf("Enter your option: ");
        char option;
        scanf(" %c", &option);

        if (option == 'Q' || option == 'q')
        {
            isShutDown = 1;
        } else if (option == 'M' || option == 'm')
        {
            printf("\n");
            printOptions();
            printf("Enter your option: ");
            scanf("%d", &selectedOption);
        } else if (option == 'C' || option == 'c')
        {
            continue;
        }
    }
    

    return 0;
}


