#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/types.h>
#include "ex1.h"
#define SIZE 16
#define ALIGN 1048576
int main()
{
	for (int i = 2; i < 100000; i = i * 2)
	{
		void *p;
		p = aligned_malloc(SIZE, i);
		printf("%p %ld\n", p, ((long int)p) % i);
		aligned_free(p);
	}
	//printf("%d ", sizeof(uintptr_t));	
	return 0;
}
