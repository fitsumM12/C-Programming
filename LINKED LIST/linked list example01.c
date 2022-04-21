//linked list concepts
#include <stdio.h>
#include <stdlib.h>
typedef struct node *nodePtr;
struct node{
	int value;
	nodePtr next;
};
typedef struct node node;
int main(void){
	nodePtr first = NULL,third = NULL, second;
	first = malloc(sizeof(node));
	third = mallc(sizeof(node));
	
	first->value = 24;
	first->next = third;
	third->value = 25;
	third->next = NULL;
	while(1)
	{
		second = first;
		if(second->next == NULL){
			break;
		}
		else{
			printf("%d\n",second->value);
			second = second->next;
		}
	}
	printf("hello world\n");
}
