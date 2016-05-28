/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
//#include <stdio.h> uncomment for debug

#include "helpers.h"

/**
 * 
 * Linear serach returns true if value is in array of n values, else false.
 * 
 * Tim Hodge - 2016-05-28
 * 
 */
bool search(int value, int values[], int n)
{
    
    //printf("Needle: %i\n", value);
    
    //printf("Sorted Haystack: ");

    for ( int i=0; i<n ; i++) {
        
        //printf("%i ", values[i]);
        
        if ( values[i] == value ) 
            return true;
    }
    
    return false;
}

/**
 * 
 * Sorts array of n values using bubble sort
 * 
 * Tim Hodge - 2016-05-28
 */
void sort(int values[], int n)
{
    
    /* uncomment for debug
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
    
    /* uncomment for debug
    printf("Sorted Haystack of %i values in %i moves: ", n, count);
    for ( int k=0; k<n; k++)
        printf("%i ", values[k]);
    printf("\n");
    
    printf("\n-- end search.c --\n");
    */
    
    return;
}