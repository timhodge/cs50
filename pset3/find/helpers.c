/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Search an array for a value using binary search
 * Returns true if value is in array of n values, else false.
 * 
 * Tim Hodge = 2016-05-28
 */
bool search(int value, int values[], int n)
{
    
    int target = value;
    int arrayStart = 0;
    int arrayEnd = n-1;
    int arrayMiddle =(arrayStart + arrayEnd) / 2;
    
    while ( arrayStart <= arrayEnd ) {
        
        //printf("Target: %i; Start: %i; End: %i; Middle: %i\n", target, arrayStart, arrayEnd, arrayMiddle);

        if ( values[arrayMiddle] == target ) {
            return true;
        }
        else if ( values[arrayMiddle] < target ) {
            arrayStart = arrayMiddle + 1;
            arrayMiddle = (arrayStart + arrayEnd) / 2;
        }
        else if ( values[arrayMiddle] > target ) {
            arrayEnd = arrayMiddle - 1;
            arrayMiddle = (arrayStart + arrayEnd) / 2;
        }
    
    }
    
    return false;
}

/**
 * Sorts array of n values using bubble sort
 * 
 * Tim Hodge - 2015-05-28
 */
void sort(int values[], int n)
{
    
    /*
    printf("\n-- search.c output --\n\n");
    
    printf("Unsorted Haystack: ");
    for ( int j=0; j<n; j++)
        printf("%i ", values[j]);
    printf("\n\n");
    */
    
    int holder, m=0, count=0, didNothing;
    
    for ( ; m<n; m++) {
        
        didNothing = 0;
        
        // for each value in the array, check the value to its right
        for ( int i=0; i<n-1; i++) {
            
            // if the number to the right is smaller, move it left
            if ( values[i+1] < values[i] ) {
                
                holder = values[i];
                values[i] = values[i+1];
                values[i+1] = holder;
                
            } else {
                didNothing = didNothing + 1;
            }
            
            count = count + 1;
            // if we make it through an iteration without moving anything, end the parent loop
            if ( didNothing == n-1 ) {
                m=n;
            }
            
        }

   }
    
    /*
    printf("Sorted Haystack of %i values in %i moves: ", n, count);
    for ( int k=0; k<n; k++)
        printf("%i ", values[k]);
    printf("\n");
    
    printf("\n-- end search.c --\n");
    */
    
    return;
}