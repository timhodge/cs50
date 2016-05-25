/*
    caesar-0.c - CS50 pset2 standard edition
    
    - prep for real caesar.c problem
    - Encrypt a message using Caesar's cipher
    - Accept key as a command line argument
    
    Tim Hodge - 2016-05-21
 */
 
 #include <stdio.h>
 #include <stdlib.h> // for atoi()
 #include <cs50.h>
 #include <string.h> // for string functions
 #include <ctype.h> // for isdigit()
 
int main(int argc, string argv[])
{
    // no command line argument given, so exit
    if (argc == 1) {
        printf("Please specify k\n");
        return 1;
    }
    // too many command line arguments given, so exit
    if (argc > 2) {
        printf("Too many command line arguments\n");
        return 1;
    }
    
    // check to make sure they input an integer
    for ( int j = 0, argLength = strlen(argv[1]); j < argLength; j++ ) {
        if ( !isdigit(argv[1][j]) ) {
            printf("I'm looking for an integer, please\n");
            return 1;
        }
    }
    
    // now that we know they input an integer, convert the input string to int
    int k = atoi(argv[1]);
    
    printf("k: %i\n", k);
    
    printf("What is your secret message?\n");
    
    string message = GetString();

    for ( int i = 0, c, e, length = strlen(message); i < length; i++ ) {
        
        if ( isalpha(message[i]) ) {
            
            if ( message[i] >= 65 && message[i] <= 90) {
                c = ( message[i] - 64 + k ) % 26;
                e = ( c + 64 );
            } else if ( message[i] >= 97 && message[i] <= 122) {
                c = ( message[i] - 96 + k ) % 26;
                e = ( c + 96 );
            }
        
            printf("%c - %i - %i - %i - %c\n", message[i], (int) message[i], c, e, (char) e);
        }
        else {
            printf("%c\n", message[i]);
        }
    }
    
    printf("\n");
    
    return 0;
}