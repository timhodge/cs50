/*
    viginere.c - CS50 pset2 standard edition
    
    - Encrypt a message using Vigenere's cipher
    - Accept key as a command line argument
    - Prompt user for string to encrypt
    
    Tim Hodge - 2016-05-25
 */
 
 #include <stdio.h>
 #include <cs50.h>
 #include <string.h>
 #include <ctype.h>
 
int main( int argc, string argv[] )
{
    // no command line argument given, so exit
    if (argc == 1) {
        printf("Please specify key\n");
        return 1;
    }
    
    // too many command line arguments given, so exit
    if (argc > 2) {
        printf("Too many command line arguments\n");
        return 1;
    }
    
    // check to make sure key is alphabetic
    for ( int j = 0, argLength = strlen(argv[1]); j < argLength; j++ ) {
        if ( !isalpha(argv[1][j]) ) {
            printf("Alphabet characters only, please\n");
            return 1;
        }
    }
    
    string key = argv[1], phr = GetString();
    
    int keyLen = strlen(key), phrLen = strlen(phr);
    
    for ( int e, i=0, count=0, thisKey; i < phrLen; i++) {
        
        // if it's an alphabetic character do the things
        if ( isalpha(phr[i]) ) {
            
            thisKey = tolower(key[count]) - 97;
            
            if ( phr[i] >= 65 && phr[i] <= 90) {
                e = ( phr[i] - 65 + thisKey ) % 26;
                e = ( e + 65 );
            } else if ( phr[i] >= 97 && phr[i] <= 122) {
                e = ( phr[i] - 97 + thisKey ) % 26;
                e = ( e + 97 );
            }
            
            printf("%c", e);
            
            if ( count == keyLen - 1)
                count = 0;
            else
                count++;
        }
        // if it's not alphabetic just print it
        else {
            printf("%c", phr[i]);
        }
    }
    
    printf("\n");
    
    return 0;
}