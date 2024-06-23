#include <stdio.h>

void printSeperator(int length, char seperator){
    for (int i = 0; i < length; i++)
    {
        printf("%c", seperator);
    }
    printf("\n");
}
