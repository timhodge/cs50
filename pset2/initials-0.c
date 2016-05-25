/*
    initials-0.c - CS50 pset2 standard edition
    
    - fun with strings, prepping for the actual initials.c problem
    
    Tim Hodge - 2016-05-21
 */
 
 #include <stdio.h>
 #include <cs50.h>
 #include <string.h>
 
 int main(void)
 {
     printf("What is your name?\n");
     string name;
     name = GetString();
     
     printf("Your name is: ");
     
     int length = strlen(name);

     for (int i = 0; i < length; i++) {
         printf("%i ", (int) name[i]);
     }
     
     printf("\n");
     
     int lastLetter = length - 1;
     
     printf("First letter: %c\n", name[0]);
     printf("Last letter: %c\n", name[lastLetter]);
     
     printf("Name length: %i\n", length);
     
     int prevChar = 32;
     
     for (int i = 0; i < length; i++) {
         if ( (name[i] >= 97) && (name[i] <= 122) && (prevChar == 32) ) {
             printf("%c", name[i] - 32);
         }
         else {
             printf("%c", name[i]);
         }
         
         prevChar = name[i];
     }
     
     printf("\n");
     
     prevChar = 32;
     
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