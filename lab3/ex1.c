#include <stdio.h>
#include <stdlib.h>
#include "ex1.h"

void *aligned_malloc(unsigned int size, unsigned int align)
{
	if (align < 0)
		return NULL;

	void *p, *ptr;
	p = (void*)malloc(size + align - 1 + sizeof(void*));
	if (p != (void*) - 1)
	{
		size_t addr = (size_t)p + align - 1 + sizeof(void*);
		ptr = (void*)(addr - (addr % align));
		*((size_t*)ptr - 1) = (size_t)p;
		return ptr;	
	}
	return NULL;
}

void *aligned_free(void* ptr)
{
	free((void*)(*((size_t*)ptr - 1)));
}
