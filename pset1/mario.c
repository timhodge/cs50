/*
    mario.c - CS50 pset1 standard edition
    
    - Create a half pyramid of height defined by user, no greater than 23
    - Top level of pyramid is two columns wide
    
    Tim Hodge - 2016-05-25
 */
 
 #include <stdio.h>
 #include <cs50.h>
 
 int main(void)
 {
     int height;

     do {
        printf("Height of pyramid? (0-23): ");
        height = GetInt();
     } while ( height < 0 || height > 23 );

     for ( int blocks = 2; height >= 1; blocks++, height-- ) {
         
         for (int i = 0; i < height - 1; i++ )
             printf(" ");

         for ( int j = 0; j < blocks; j++ )
             printf("#");

         printf("\n");
     }
     
     return 0;
 }