#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "utils.h"

/* Function to create a new node */
struct node* newNode(char *buf)
{
	struct node *node = (struct node *) Malloc(sizeof(struct node));
	node->count = 1;
	node->str = (char *) Malloc(strlen(buf) + 1);
	strncpy(node->str, buf, strlen(buf));
	node->str[strlen(buf)] = '\0';
	node->left = NULL;
	node->right = NULL;
	return node;
}

/* Functions to print all the strings and their count */
void printInOrder(struct node *node)
{
	if(node == NULL)
		return;

	printInOrder(node->left);
	printf("%u %s\n", node->count, node->str);
	printInOrder(node->right);
}

void printCounts(struct node **arr)
{
	int i;
	for(i = 0; i <= ALPHABET_COUNT; i++)
		printInOrder(arr[i]);
}

/* Functions to free each node of each BST of the array */
void freePostOrder(struct node *node)
{
	if(node == NULL)
		return;

	freePostOrder(node->left);
	freePostOrder(node->right);
	free(node->str);
	free(node);
}

void freeAllData(struct node **arr)
{
	int i;
	for(i = 0; i <= ALPHABET_COUNT; i++)
		freePostOrder(arr[i]);
}

/* This function checks the input string and compares it with all
 * the data read till now. If match found, just increment the count.
 * Else, create a new node in the corresponding BST.
 */
void updateCount(struct node **node, char *buf)
{
	if(*node == NULL)
		*node = newNode(buf);

	else
	{
		int cmp = strcmp(buf, (*node)->str);
		if(cmp < 0)
			updateCount(&((*node)->left), buf);

		else if(cmp > 0)
			updateCount(&((*node)->right), buf);

		else
			(*node)->count++;
	}
}
