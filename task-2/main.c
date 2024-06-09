#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "time_conversion.h"
#include "character_combine.h"



void printOptions(){
    puts("Please select an option:");
    puts("1. Time Conversion");
    puts("2. Character Combine");
    puts("3. Exit");
}


int main(){
    int selectedOption;

    printOptions();
    printf("Enter your option: ");
    scanf("%d", &selectedOption);

    printf("\n");

    switch (selectedOption)
    {
    case 1:
        runTimeConversion();
        break;

    case 2:
        runCharacterCombine();
        break;
    
    default:
        exit(1);
        break;
    }

    return 0;
}


