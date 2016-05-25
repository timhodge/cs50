/*
    credit.c - CS50 pset1 hacker edition
    
    - Validates a credit card number as Amex, MC, Visa, or invalid
        - Amex is 15 digits and starts with 34 or 37
        - Mastercard is 16 digits and starts with 51-55
        - Visa is 13 or 16 digits and starts with 4
    - Does a checksum as well to make sure it is a valid number
    
    Tim Hodge - 2016-05-19
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long long cardNum;
    
    printf("Credit card #: ");
    cardNum = GetLongLong();
    
    if ( (cardNum < 4000000000000) || (cardNum > 5599999999999999) ) {
        printf("INVALID\n");
        exit(0);
    }
    
    long long digitCount = cardNum;
    int x, numDigits, cardDigit, evenCount = 0, oddCount = 0, totalCount;
    
    // count the digits in the card and make sure it's a valid card number
    
    for (numDigits = 0; digitCount > 0; numDigits++) {
        
        cardDigit = digitCount % 10;
        digitCount /= 10;
        
        // printf("Digit: %i - ", cardDigit);
        
        // do a checksum to make sure it's a valid card number
        if ( numDigits % 2 == 0 ){
            evenCount = (cardDigit + evenCount);
            //printf("even %i\n", evenCount);
        }
        if ( numDigits %2 != 0 ){
            x = (cardDigit * 2);
            x = ((x - (x % 10)) / 10) + ( x % 10);
            oddCount = x + oddCount;
            //printf("odd - %i, %i\n", x, oddCount);
        }
    }
    
    // final checksum value should end in 0
    totalCount = evenCount + oddCount;
    
    printf("Total count: %i\n", totalCount);
    
    if ( totalCount % 10 != 0 ) {
        printf("INVALID\n");
        exit(0);
    }
    
    //printf("Total count: %i\n", totalCount);
    
    // Find the first and second digits to define a card prefix
    
    int i, firstDigit, secondDigit, cardPrefix;
    
    for (i = numDigits; i > 0; i--) {
        cardDigit = cardNum % 10;
        cardNum /= 10;
        if ( i == 1 )
            firstDigit = cardDigit;
        if ( i == 2 )
            secondDigit = cardDigit;
    }
    
    if ( firstDigit == 4 ) {
        cardPrefix = 4;
    } else {
        cardPrefix = (firstDigit * 10) + secondDigit;
    }

    // Based on the prefix let's figure out what kind of card it is
    
    string cardType;
    
    if ( (cardPrefix == 4) && ((numDigits == 13) || (numDigits == 16)) ) {
        cardType = "VISA";
    }
    if ( ((cardPrefix == 34) || (cardPrefix == 37)) && (numDigits == 15)) {
        cardType = "AMEX";
    }
    if ( ((cardPrefix >= 51) && (cardPrefix <= 55)) && (numDigits == 16) ) {
        cardType = "MASTERCARD";
    }
    
    printf("%s\n", cardType);
    
    return 0;
}