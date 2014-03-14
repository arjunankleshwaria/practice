#ifndef __UTILS_H
#define __UTILS_H

#include <stdlib.h>

#define STDIN		0
#define STDOUT		1

#define ALPHABET_COUNT		26
#define LOWER_CASE_START	97
#define UPPER_CASE_START	65
#define MAX_LINE_LENGTH		1024

/* Structure of a node */
struct node
{
	uint32_t count;
	char *str;
	struct node *left;
	struct node *right;
};

/* Wrapper function for malloc() */
void *Malloc(size_t size);

#endif	/* __UTILS_H */
