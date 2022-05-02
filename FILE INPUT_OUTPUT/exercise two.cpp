#include <stdio.h>
#include <stdlib.h>
int main()
{
	char c;
	FILE *myfile;
	myfile = fopen("details.txt","r");
	if (myfile == NULL){
		printf("cant open the file");
		exit(0);
	}
	c = getc(myfile);
	printf("%c", c);
	fclose(myfile);
}
