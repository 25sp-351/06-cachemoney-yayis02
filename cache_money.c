#include <stdio.h>
#include <string.h>

#define MAX_CACHED_VALUE 1500

char memoization[MAX_CACHED_VALUE][512];

const char *convertTens(int n) {
    switch (n) {
        case 1:
            return "one";
        case 2:
            return "two";
        case 3:
            return "three";
        case 4:
            return "four";
        case 5:
            return "five";
        case 6:
            return "six";
        case 7:
            return "seven";
        case 8:
            return "eight";
        case 9:
            return "nine";
        case 10:
            return "ten";
        case 11:
            return "eleven";
        case 12:
            return "twelve";
        case 13:
            return "thirteen";
        case 14:
            return "fourteen";
        case 15:
            return "fifteen";
        case 16:
            return "sixteen";
        case 17:
            return "seventeen";
        case 18:
            return "eighteen";
        case 19:
            return "nineteen";
        default:
            return "";
    }
}

const char *convertTensPlace(int n) {
    switch (n) {
        case 2:
            return "twenty";
        case 3:
            return "thirty";
        case 4:
            return "forty";
        case 5:
            return "fifty";
        case 6:
            return "sixty";
        case 7:
            return "seventy";
        case 8:
            return "eighty";
        case 9:
            return "ninety";
        default:
            return "";
    }
}

void convertHundreds(int n, char *result) {
    if (n >= 100) {
        sprintf(result + strlen(result), "%s hundred", convertTens(n / 100));
        n = n % 100;
    }

    if (n > 0) {
        if (n < 20) {
            strcat(result, " ");
            strcat(result, convertTens(n));
        } else {
            strcat(result, " ");
            strcat(result, convertTensPlace(n / 10));
            if (n % 10 > 0) {
                strcat(result, "-");
                strcat(result,
                       convertTens(n % 10));  // Added hyphen
            }
        }
    }
}

void convertThousands(int n, char *result) {
    if (n >= 1000) {
        convertHundreds(n / 1000, result);  // Convert thousands
        strcat(result, " thousand ");
        n = n % 1000;
    }
    if (n > 0)
        convertHundreds(n, result);  // Convert remaining hundreds
}

char *convertMoneyToWords(int amount) {
    static char result[512];
    result[0]   = '\0';

    int dollars = amount / 100;
    int cents   = amount % 100;

    // Special case for 0
    if (amount == 0) {
        strcpy(result, "zero dollars");
        return result;
    }

    // Handle dollars
    if (amount < MAX_CACHED_VALUE && memoization[amount][0] != '\0')
        return memoization[amount];

    convertThousands(dollars, result);

    if (dollars == 1)
        strcat(result, " dollar");
    else if (dollars > 1)
        strcat(result, " dollars");

    if (cents > 0) {
        if (dollars > 0)
            strcat(result, " and");
        convertHundreds(cents, result);

        if (cents == 1)
            strcat(result, " cent");
        else if (cents > 1)
            strcat(result, " cents");
    }

    // Memoize the result for future use
    if (amount < MAX_CACHED_VALUE)
        strcpy(memoization[amount], result);

    return result;
}

int main() {
    int amount;

    // Initialize memoization array
    for (int i = 0; i < MAX_CACHED_VALUE; i++)
        memoization[i][0] = '\0';

    // Process inputs
    while (scanf("%d", &amount) != EOF) {
        char *result = convertMoneyToWords(amount);
        printf("%d = %s\n", amount, result);
    }

    return 0;
}
