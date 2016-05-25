/*
    viginere-0.c - CS50 pset2 standard edition
    
    - Testing for Vigenere pset
    
    - Encrypt a message using Vigenere's cipher
    - Accept key as a command line argument
    - Prompt user for string to encrypt
    
    Tim Hodge - 2016-05-25
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
    
    // check to make sure it's alphabetic
    for ( int j = 0, argLength = strlen(argv[1]); j < argLength; j++ ) {
        if ( !isalpha(argv[1][j]) ) {
            printf("Alphabet characters only, please\n");
            return 1;
        }
    }
    
    string key = argv[1];
    
    int keyLength = strlen(key);
    
    printf("Key: %s (%i)\n", key, keyLength);
    
    printf("What is your phrase: ");
    string phrase = GetString();
    
    int phraseLength = strlen(phrase);
    //char e[phraseLength];
    
    printf("Phrase: %s (%i)\n", phrase, phraseLength);
    
    for ( int i=0, count=0; i < phraseLength; i++) {
        
        if ( isalpha(phrase[i]) ) {
            printf("%c - %i - %c\n", phrase[i], count, key[count]);
            
            if ( count == keyLength - 1)
                count = 0;
            else
                count++;
        }
        else {
            printf("%c - %i\n", phrase[i], count);
        }
    }
    
/*
    // now that we know they input an integer, convert the input string to int
    int k = atoi(argv[1]);
    
    // get the message we would like to encrypt
    string message = GetString();

    for ( int i = 0, c, e, length = strlen(message); i < length; i++ ) {
        
        if ( isalpha(message[i]) ) { // if it is a letter, encrypt it
            
            if ( message[i] >= 65 && message[i] <= 90) {
                c = ( message[i] - 64 + k ) % 26;
                e = ( c + 64 );
            } else if ( message[i] >= 97 && message[i] <= 122) {
                c = ( message[i] - 96 + k ) % 26;
                e = ( c + 96 );
            }
        
            printf("%c", (char) e);
        }
        else { // if it is not a letter leave it alone
            printf("%c", message[i]);
        }
    }
    
    printf("\n");
    */
    
    return 0;
}