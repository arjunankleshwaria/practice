#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}mynode;

mynode* add(mynode* head, int v)
{
	mynode *newnode = malloc(sizeof(mynode));
	newnode->data = v;
	newnode->next = head;
	return newnode;
}

void print(mynode* head)
{
	mynode* c = head;
	printf("\n");
	while(c != NULL)
	{
		printf("%d ", c->data);
		c = c->next;
	}
	printf("\n");
}

mynode* merge_recursive(mynode* a, mynode* b)
{
	if(a == NULL)
		return b;
	else if(b == NULL)
		return a;

	mynode *result = NULL;

	if(a->data < b->data)
	{
		result = a;
		result->next = merge_recursive(a->next, b);
	}
	else
	{
		result = b;
		result->next = merge_recursive(a, b->next);
	}

	return result;
}

mynode* merge(mynode* left, mynode* right)
{
	mynode *a = left;
	mynode *b = right;
	mynode *c = NULL;
	mynode *newhead = NULL;

	while(a != NULL && b != NULL)
	{
		if(a->data < b->data)
		{
			if(c == NULL)
				c = a;
			else
			{
				c->next = a;
				c = c->next;
			}
			a = a->next;
		}
		else
		{
			if(c == NULL)
				c = b;
			else
			{
				c->next = b;
				c = c->next;
			}
			b = b->next;
		}
		if(newhead == NULL)
			newhead = c;
	}

	if(a == NULL && b == NULL)
		return newhead;
	if(a == NULL)
		c->next = b;
	else if(b == NULL)
		c->next = a;

	return newhead;
}

void split_list(mynode* head, mynode** left, mynode** right)
{
	if(head == NULL || head->next == NULL)
	{
		*left = head;
		*right = NULL;
	}

	mynode *slow = head;
	mynode *fast = head->next;

	while(fast != NULL)
	{
		fast = fast->next;
		if(fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	*left = head;
	*right = slow->next;
	slow->next = NULL;
}

void mergeSort(mynode** head)
{
	if(*head == NULL || (*head)->next == NULL)
		return;

	mynode *left;
	mynode *right;

	split_list(*head, &left, &right);

	mergeSort(&left);
	mergeSort(&right);

	*head = merge_recursive(left, right);
}

int main()
{
	int i = 1;
	mynode *head = NULL;
	for(; i <= 10; i++)
		head = add(head, i);

	print(head);
	mergeSort(&head);
	print(head);
	return 0;
}
