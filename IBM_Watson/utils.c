#include <stdlib.h>

/* Wrapper function for malloc() */
void *Malloc(size_t size)
{
	char *ptr = (char *) malloc(size);
	if(ptr == NULL)
	{
		perror("Error using malloc().\n");
		exit(-1);
	}
	return ptr;
}

