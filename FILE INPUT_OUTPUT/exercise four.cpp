//Program to write and read integer into a file:
#include  <stdio.h>                                               
int main(void)                                                            
{                                                                 
	FILE  *f1, *f2, *f3;                                          
    int   number, i;                                                          
    f1 = fopen("DATA", "w");     
    for(i = 1; i <= 30; i++)                                      
    {
    	scanf("%d", &number);                                      
        if(number == -1) break;                                    
        putw(number,f1);                                           
    }                                                             
    fclose(f1);                                                   
	f1 = fopen("DATA", "r");                                      
    f2 = fopen("ODD", "w");                                       
    f3 = fopen("EVEN", "w");       
	/* Read from DATA file */                                                                 
	while((number = getw(f1)) != EOF) 
 	{
  		if(number %2 == 0)                                        
  		putw(number, f3);   /*  Write to EVEN file  */   
  		else                                                      
  		putw(number, f2);   /*  Write to ODD file   */   
  	}                                                             
    fclose(f1);                                                   
    fclose(f2);                                                   
    fclose(f3);                                                   
}                                                         

