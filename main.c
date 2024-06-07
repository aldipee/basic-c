#include <stdio.h>
#include <string.h>
#include <stdlib.h>




#define BOLD "ESC[1m"
#define GREEN "\x1B[32m"
#define GREEN_BOLD "\x1B[32;1;4m"


void printWelocomeMessage(){
    printf( "==============================================\n");
    printf( "|     Welcome to the discount calculator     |\n");
    printf( "==============================================\n");
}

float calculateDiscount(int totalAmout, float discount){
    return totalAmout - (totalAmout * discount / 100);
}

void renderInTable(int totalAmount, float discount, float priceAfterDiscount, float youSaved) {
    printf("\n");
    printf("==============================================\n");
    printf("|       Calculation Result                    |\n");
    printf("==============================================\n");
    printf("| %-20s | %10d |\n", "Total Amount", totalAmount);
    printf("| %-20s | %10.2f |\n", "Discount", discount);
    printf("| %-20s | %10.2f |\n", "Price After Discount", priceAfterDiscount);
    printf("| %-20s | %10.2f |\n", "You Saved", youSaved);
    printf("==============================================\n");
    printf("\n");
}




int main() {
    char name[50];
    char email[50];
    int totalAmount;
    float discount;
    float priceAfterDiscount;
    float youSaved;


    printWelocomeMessage();

  
    // Prompt the user for their name
    printf("Enter your name: ");
    // set the name variable to the user's input
    fgets(name, sizeof(name), stdin);
     name[strcspn(name, "\n")] = '\0';

    printf("Enter your email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';
    

    printf("Enter the total amount: ");
    scanf("%d", &totalAmount);

    printf("Enter the discount (%%): ");
    scanf("%f", &discount);

    // Calculate the discount amount
    priceAfterDiscount = calculateDiscount(totalAmount, discount);
    youSaved = totalAmount - priceAfterDiscount;


    renderInTable(totalAmount, discount, priceAfterDiscount, youSaved);
    // Print the discount amount
    printf("Congratulations %s! You saved %.2f \n", name, youSaved);


    return 0;
}
