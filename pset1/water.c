/*
    water.c - CS50 pset1 standard edition
    
    - Calculates the equivalent number of bottles of water used in the course of a shower
    
    Tim Hodge - 2016-05-17
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    
    int time;
    
    do {
        printf("How long was your shower in minutes: ");
        time = GetInt();
    } while ( time < 0 );
    
    float gallons = time * 1.5;
    float ounces = gallons * 128;
    float bottles = ounces / 16;
    
    printf("Total bottles of water used: %.2f\n", bottles);
    
    return 0;
}