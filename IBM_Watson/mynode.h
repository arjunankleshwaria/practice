#ifndef __MYNODE_H
#define __MYNODE_H

#include <string.h>

/* Function to create a new node */
struct node* newNode(char *buf);

/* Functions to print all the strings and their count */
void printInOrder(struct node *node);
void printCounts(struct node **arr);

/* Functions to free each node of each BST of the array */
void freePostOrder(struct node *node);
void freeAllData(struct node **arr);

/* This function checks the input string and compares it with all
 * the data read till now. If match found, just increment the count.
 * Else, create a new node in the corresponding BST.
 */
void updateCount(struct node **node, char *buf);

#endif	/* __MYNODE_H */
