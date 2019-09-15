#include <stdio.h>
#include <stdlib.h>
#include "factorial.h"
int multiply(int x, int res[], int res_size)
{

	int carry = 0;
       	for (int i=0; i<res_size; i++)
   	{
       		int prod = res[i] * x + carry;

         
      		 res[i] = prod % 10;

        
       		 carry  = prod/10;
   	 }

    
   	 while (carry)
   	 {
       		 res[res_size] = carry%10;
       		 carry = carry/10;
       		 res_size++;
   	 }
   	 return res_size;
}

 
char* factorial(const int aNumber) 
{ 
  	int res[100000]; 
	char *p;
    	int j = 0;
   	res[0] = 1; 
   	int res_size = 1; 
  	p = (char*)malloc(100000 * sizeof(char));
   
   	for (int x=2; x<=aNumber; x++) 
       		res_size = multiply(x, res, res_size); 
  
   	for (int i=res_size-1; i>=0; i--) 
       	{
		p[j] = res[i] + '0';
		j++;
		printf("%d", res[i]);
	}	
	return p;
} 
  

