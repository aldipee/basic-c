
void printOptions(){
    puts("Please select an option:");
    puts("1. Time Conversion");
    puts("2. Character Combine");
    puts("3. Exit");
}


// Ansi Output format styling
// https://gist.github.com/radxene/f1e286301763b921baf06074ea46c800
#define ANSI_COLOR_GREEN        "\x1b[32m"
#define ANSI_COLOR_BLUE         "\x1b[34m"
#define ANSI_STYLE_BOLD         "\x1b[1m"
#define ANSI_STYLE_ITALIC       "\x1b[3m"
#define ANSI_STYLE_UNDERLINE    "\x1b[4m"
#define ANSI_RESET_ALL          "\x1b[0m"

void printSeperator(int length, char seperator){
    for (int i = 0; i < length; i++)
    {
        printf("%c", seperator);
    }
    printf("\n");
}



int getTotalEligbleDisount(float billingDurationInHours){
    int totalEligbleDiscount = 0;
    if(billingDurationInHours > 4 && billingDurationInHours <= 6){
        totalEligbleDiscount = 10;
    } else if(billingDurationInHours > 6 && billingDurationInHours <= 8){
        totalEligbleDiscount = 15;
    } else if(billingDurationInHours > 8 && billingDurationInHours <= 10){
        totalEligbleDiscount = 20;
    } else if(billingDurationInHours > 10){
        totalEligbleDiscount = 25;
    } 

    return totalEligbleDiscount;
}

int isValidNumericNumber(char *inputString){
    int i = 0;
    for (; inputString[i] != '\0'; i++)
    {
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
        puts("Please enter a valid number in minutes format: ");
        scanf("%s", string);
        isValidNumber = isValidNumericNumber(string);
    }
    return atoi(string);
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

void printWelcomeMessage(){
    printf("==========================\n");
    printf("| Selamat Datang di Warnet Point Blank |\n");
    printf("---------------------------\n");
    printf("| Bebas internet tanpa khawatir di block Kominfo |\n");
    printf("| Bocil dilarang berisik |\n");
    printf("==========================\n");
    printf("\n");
}


void warnetCashier(){
    int basedRentPerHour = 10000;
    float rentDurationInHours = 0;
    int rentDurationInMinutes = 0;
    int applicableDiscountInPercentage = 0;
    char inputString[20];

    printWelcomeMessage();


    puts("Enter the time in minutes: ");
    scanf("%s", &inputString);

    rentDurationInMinutes = sanitizeInput(inputString);
    rentDurationInHours = rentDurationInMinutes / 60.0;
    applicableDiscountInPercentage = getTotalEligbleDisount(rentDurationInHours);
    int totalBill = basedRentPerHour * rentDurationInHours;
    int totalDiscount = totalBill * applicableDiscountInPercentage / 100;
    int finalBill = totalBill - totalDiscount;


    char *totalBillInRupiah = rupiahFormatter(totalBill);
    char *totalDiscountInRupiah = rupiahFormatter(totalDiscount);
    char *finalBillInRupiah = rupiahFormatter(finalBill);


    printSeperator(40);
    printf("| %-37s |\n", "Tagihan Billing Inet");
    printSeperator(40);
    printf("| %-20s | %14.1f \n", "Durasi Jam", rentDurationInHours);
    printf("| %-20s | %15s \n", "Total Tagihan", totalBillInRupiah);
    printf("| %-20s | %15s \n", "Total Discount", totalDiscountInRupiah);
    printf("| %-20s | %15s \n", "Total Bayar", finalBillInRupiah);
    printf("| %-20s | %10s \n", "Total CashBon", "Rp. 0");
    printSeperator(40);
    !!applicableDiscountInPercentage &&  printf(ANSI_COLOR_GREEN ANSI_STYLE_BOLD "Selamat! Kamu dapet diskon %d%%\n" ANSI_RESET_ALL, applicableDiscountInPercentage);
    !!applicableDiscountInPercentage &&  printf(ANSI_COLOR_BLUE ANSI_STYLE_BOLD "Sering-sering dateng lagi yeee!!\n" ANSI_RESET_ALL);
}