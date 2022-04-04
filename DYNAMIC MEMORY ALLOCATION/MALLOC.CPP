// C Program to dynamically allocate an int ptr
#include <stdio.h>
#include <stdlib.h>

int main() {
	// Dynamically allocated variable, sizeof(char) = 1 byte. 
	char *ptr = (char *)malloc(sizeof(char));

	if (ptr == NULL) {
		printf("Memory Error!\n");
	} else {
		*ptr = 'S';
		printf("%c", *ptr);
	}

	return 0;
}

