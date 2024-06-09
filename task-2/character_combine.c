#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "character_combine.h"

#define ANSI_COLOR_GREEN        "\x1b[32m"

void printWelcomeMessageCombine(){
    printf("==========================\n");
    printf("| Welcome to character combine |\n");
    printf("==========================\n");
}

int validateStringSentence(char *string){
    int i = 0;
    for (; string[i] != '\0'; i++)
    {
        if(isalpha(string[i]) == 0){
            return 0;
        }
    }
    return 1;
}


char* sanitizeSentenceInput(char *string){
    int isValidSentence = validateStringSentence(string);
    while (!isValidSentence)
    {
        // Ask the user to enter a valid number
        puts("Please enter a valid sentence without number: ");
        scanf("%s", string);
        isValidSentence = validateStringSentence(string);
    }
    return string;
}

char* combineSentences(char *firstSentence, char *secondSentence, char *thirdSentence, char *result){

    int totalLength = strlen(firstSentence) + strlen(secondSentence) + strlen(thirdSentence) + 2 + 1;
    result = malloc(totalLength);

    sprintf(result, "%s %s %s", firstSentence, secondSentence, thirdSentence);
    return result;
}

char* combineAndReverseCharacters(char *firstSentence, char *secondSentence, char *thirdSentence, char *result){
 
    sprintf(result, "%s %s %s", firstSentence, secondSentence, thirdSentence);
    int i = 0;
    int j = strlen(result) - 1;
    while (i < j)
    {
        char temp = result[i];
        result[i] = result[j];
        result[j] = temp;
        i++;
        j--;
    }
    return result;
}


int runCharacterCombine(){

    printWelcomeMessageCombine();
    

    // runTimeConversion();
    char firstSentence[100];
    char secondSentence[100];
    char thirdSentence[100];

    puts("Please enter the first sentence: ");
    scanf("%s", firstSentence);
    char* firstSentenceSanitized =  sanitizeSentenceInput(firstSentence);


    puts("Please enter the second sentence: ");
    scanf("%s", secondSentence);
    char* secondSentenceSanitized = sanitizeSentenceInput(secondSentence);

    puts("Please enter the third sentence: ");
    scanf("%s", thirdSentence);
    char* thirdSentenceSanitized = sanitizeSentenceInput(thirdSentence);

    char *combinedSentence = combineSentences(firstSentenceSanitized, secondSentenceSanitized, thirdSentenceSanitized, combinedSentence);
    
    char *reversedSentence = malloc(strlen(combinedSentence));
    combineAndReverseCharacters(firstSentenceSanitized, secondSentenceSanitized, thirdSentenceSanitized, reversedSentence);


    printf("\n\n");
    printf("=========================================================\n");
    printf("| Result\n");
    printf("=========================================================\n");
    
    printf("Combined sentence: \x1b[32m %s \x1b[0m\n", combinedSentence) ;
    
    printf("Resersed sentence: \x1b[32m %s \x1b[0m\n \n", reversedSentence);
   

    int totalCharacterWithSpace = strlen(combinedSentence);
    int totalCharacterWithoutSpace = strlen(combinedSentence) - 2;
    int totalCharacterInFirstSentence = strlen(firstSentenceSanitized);
    int totalCharacterInSecondSentence = strlen(secondSentenceSanitized);
    int totalCharacterInThirdSentence = strlen(thirdSentenceSanitized);


    printf("=========================================================\n");
    printf("| Total Character\n");
    printf("=========================================================\n");
    printf("| %-40s | %-10d |\n", "Total Character in first sentence", totalCharacterInFirstSentence);
    printf("| %-40s | %-10d |\n", "Total Character in second sentence", totalCharacterInSecondSentence);
    printf("| %-40s | %-10d |\n", "Total Character in third sentence", totalCharacterInThirdSentence);
    printf("| %-40s | %-10d |\n", "Total Character with space", totalCharacterWithSpace);
    printf("| %-40s | %-10d |\n", "Total Character without space", totalCharacterWithoutSpace);
    printf("=========================================================\n");



    free(combinedSentence);
    free(reversedSentence);


    return 0;
}