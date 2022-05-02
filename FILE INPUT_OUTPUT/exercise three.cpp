#include <stdio.h>
#include <stdlib.h>
int main()
{
	int c;
	FILE *myfile;
	myfile = fopen("details.txt","r");
	
	c = getc(myfile);
	if (myfile == NULL){
		printf("cant open the file");
		exit(0);
	}
	else{
		while(c != EOF){
			putchar(c);
			c = getc(myfile);
		}
	}
	fclose(myfile);
}
