/*
    greedy.c - CS50 pset1 standard edition
    
    - Calculates the minimum number of coins required to make change
    
    Tim Hodge - 2016-05-17
 */
 
 #include <stdio.h>
 #include <cs50.h>
 #include <math.h>
 
 int main(void)
 {
    float change;
     
    do {
        printf("How much do I owe you?\n");
        change = GetFloat();
    } while ( change < 0 );
     
    if( change == 0 ) {
        return 0;
    }
    
    // turn imprecises float into a precise integer and express it in cents

    int realChange = round( change * 100 );
    
    int quarters = 0, dimes = 0, nickels = 0, pennies = 0;
    
    if ( realChange >= 25 ) {
        quarters = realChange / 25;
        realChange = realChange - (quarters * 25);
    }
    if ( realChange >= 10 ) {
        dimes = realChange / 10;
        realChange = realChange - (dimes * 10);
    }
    if ( realChange >= 5 ) {
        nickels = realChange / 5;
        realChange = realChange - (nickels * 5);
    }
    if ( realChange > 0 ) {
        pennies = realChange;
        realChange = realChange - pennies;
    }
    
    if ( realChange == 0 ){
        printf("%i\n", quarters + dimes + nickels + pennies);
    } else {
        printf("You somehow still have coins, or negative coins: %i\n", realChange);
    }
    
    return 0;

}