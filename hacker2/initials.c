/*
    initials.c - CS50 pset2 hacker edition
    
    - accept a name as input and print the initials, capitalizing if necessary
    - remove extraneous spaces
    
    Tim Hodge - 2016-05-26
 */
 
 #include <stdio.h>
 #include <cs50.h>
 #include <string.h>
 #include <ctype.h>
 
 int main(void)
 {
     string name = GetString();
     
     int length = strlen(name), prevChar = 32;
     
     for (int i = 0; i < length; i++) {
         
         if ( isalpha(name[i]) && prevChar == 32)
            printf("%c", toupper(name[i]) );

         prevChar = name[i];
     }
     
     printf("\n");
     
     return 0;
 }