/*
    mario2.c - CS50 pset1 hacker edition
    
    - Creates two half pyramids of size defined by user (<= 23)
    - Pyramids are mirrored with a two space gap between them
    
    Tim Hodge - 2016-05-19
 */
 
 #include <stdio.h>
 #include <cs50.h>
 
 int main(void)
 {
     int height;

     do {
        printf("Pyramid height? (1-23): ");
        height = GetInt();
     } while (height < 0 || height > 23);
     
     if(height == 0) {
         exit(0);
     }
     
     int i, leftBlock = 1, rightBlock = 1, spaces = height - 1;
     
     while( height >= 1) {
         for(i = 1; i <= spaces; i++) {
             printf(" ");
         }
         for(i = 1; i <= leftBlock; i++) {
             printf("#");
         }
         printf("  ");
         for(i = 1; i <= rightBlock; i++) {
             printf("#");
         }
         printf("\n");

         leftBlock++;
         rightBlock++;
         spaces--;
         height--;
     }
 }