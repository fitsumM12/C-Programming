//OPEN THE TEXT FILE AND READ IT USING THE C PROGRAMMING LANGAUGE
#include <stdio.h>
int main(void){
	FILE *myfile;
	myfile = fopen("mytext.txt","w");
	if(myfile == NULL){
		printf("Not created");
	}
	else{
		printf("created");
	}
	fclose(myfile);
	return (0);
}
