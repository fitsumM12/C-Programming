#include<stdio.h>
struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

int main(){
	struct list_t *n;
	printf("%d", sizeof(n));
}
