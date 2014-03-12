#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define STDIN		0
#define STDOUT		1

#define ALPHABET_COUNT		26
#define LOWER_CASE_START	97
#define UPPER_CASE_START	65
#define MAX_LINE_LENGTH		100

struct node
{
	uint32_t count;
	char *str;
	struct node *left;
	struct node *right;
};

struct node* newNode(char *buf)
{
	struct node *node = (struct node *) malloc(sizeof(struct node));
	if(node == NULL)
	{
		perror("Error using malloc.\n");
		exit(-1);
	}
	node->count = 1;
	node->str = malloc(strlen(buf) + 1);
	strncpy(node->str, buf, strlen(buf));
	node->str[strlen(buf)] = '\0';
	node->left = NULL;
	node->right = NULL;
	return node;
}

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

int main()
{
	struct node *arr[ALPHABET_COUNT + 1] = {0};

	while(1)
	{
		printf("\nInput:\n");
		char buf[MAX_LINE_LENGTH] = {0};
		int r = read(STDIN, buf, MAX_LINE_LENGTH);
		if(r < 0)
		{
			perror("Error reading from STDIN.\n");
			exit(-1);
		}
		if(r == 0)
			continue;

		printf("\nOutput:\n");

		buf[r - 1] = '\0';

		int8_t index;
		if(buf[0] < LOWER_CASE_START)
			index = buf[0] - UPPER_CASE_START;
		else
			index = buf[0] - LOWER_CASE_START;

		if(!(index >= 0 && index < ALPHABET_COUNT))
			index = ALPHABET_COUNT;

		updateCount(&(arr[index]), buf);
		printCounts(arr);
	}
	return 0;
}
