#include <stdio.h>

typedef int new_thing;
float func(new_thing x){
        float new_thing;
        new_thing = x;
        return new_thing;
}
int main(){
	float var1;
	var1 = func(23);
	printf("%f", var1);	
}
