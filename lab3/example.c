#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <inttypes.h>
#define SIZE 16
#define ALIGN 1048576
void *aligned_malloc(unsigned int size, unsigned int align) {
    /* alignment could not be less then zero */
    if (align < 0) {
        return NULL;
    }
    void *ptr, *ptr_align;
    ptr = (void*)malloc(size + align + sizeof(void*));
	
    size_t addr = (size_t)ptr + align + sizeof(void*);
    ptr_align = (void*)(addr - (addr % align));
    *((size_t*)ptr_align - 1) = (size_t)ptr;
    return ptr_align;
}
 
void *aligned_free(void *p) {
    free((void*)(*((size_t*)p - 1)));
}


int  main ()
{

    unsigned int align = 1048576;
    void *p;
   p = aligned_malloc (SIZE, align);
       //v/ trying to see if its aligned properly by finding mode with align
       // mode operator should always return zero if memory is aligned to align
        printf (" %p %ld \n",  p, ((long int)p)%align);
        aligned_free (p);
    
    return 0;
}
