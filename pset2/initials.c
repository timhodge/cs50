/*
    initials.c - CS50 pset2 standard edition
    
    - accept a name as input and print the initials, capitalizing if necessary
    
    Tim Hodge - 2016-05-21
 */
 
 #include <stdio.h>
 #include <cs50.h>
 #include <string.h>
 
 int main(void)
 {
     string name;
     name = GetString();
     
     int length = strlen(name), prevChar = 32;
     
     for (int i = 0; i < length; i++) {
         
         if ( (name[i] >= 97) && (name[i] <= 122) && (prevChar == 32) )
            printf("%c", name[i] - 32);

         else if ( (name[i] >= 65) && (name[i] <= 90) && (prevChar == 32) )
            printf("%c", name[i]);

         prevChar = name[i];
     }
     
     printf("\n");
     
     return 0;
 }