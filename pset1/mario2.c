#include <stdio.h>
#include <cs50.h>

int main(void){

	int h; //variable for height
	int s; //variable for spaces
	int d; //variable for #

	do {
		printf("Height:");
		h = GetInt();
	} while (h < 0 || h > 23);
	
	if ( h == 0 )
	    return 0;

	//loop for the rows
	for (int i = 0; i < h; i++){

		//loop for the spaces and dashes per row
		for (s = (h - i); s >= 0; s--){
		printf(" ");
		}

		for (d = 1; d <= (i + 1); d++){
		printf("#"); 
		}

		printf("\n");
	}

	return 0;
}