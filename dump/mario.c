#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i,j,k,num;
    
    do {
        printf("how many stairs? \n");
        
        num = GetInt();
    } while (num <0 || num >23);
    
    for (i=num; i>=1; i--) {
        
        for (j=0; j<i-1; j++) {
            printf(" ");
        }
        
        for (k=num+1; k>=i; k--) {
            printf("#");
        }
        
        printf("\n");
    }
    
}