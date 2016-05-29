/*
    ascii.c
    - accept a string as command line argument
    - print corresponding ascii codes
    
    Tim Hodge - 2016-05-28
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    int length = strlen(argv[1]);
    
    for ( int i=0; i<length; i++)
        printf("%c ", argv[1][i]);
    
    printf("\n");
    
    return 0;
}