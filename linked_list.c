                 /***** Linked List *****/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int value;
	struct node *next;
}mynode;

mynode *head = NULL;
mynode *tail = NULL;
mynode *current;
mynode *temp;

void add(int value);
void delete(int value);
void print();

int main()
{
	printf("\n");
	print();
	add(0);
	print();
	add(1);
	add(2);
	add(3);
	add(4);
	add(5);
	print();
	delete(3);
	delete(5);
	print();
	add(6);
	delete(2);
	print();
	delete(1);
	add(7);
	add(8);
	delete(4);
	print();
	delete(0);
	delete(8);
	delete(6);
	add(9);
	print();
	printf("\n");
	return 0;
}

void add(int value)
{
	current = (mynode *) malloc(sizeof(mynode));
	current->value = value;
	current->next = NULL;
	
	if(head == NULL)
	{
		head = current;
		tail = current;
	}
	else
	{
		tail->next = current;
		tail = current;
	}
}

void delete(int value)
{
	if(head == NULL)
		return;
	
	if(head->value == value)
	{
		if(head == tail)
			tail = NULL;

		temp = head;
		head = head->next;
		free(temp);
		return;
	}

	for(current = head; current->next != NULL; current = current->next)
		if(current->next->value == value)
			break;
	
	temp = current->next;
	current->next = temp->next;
	
	if(temp == tail)
		tail = current;

	free(temp);
}

void print()
{
	if(head == NULL)
	{
		printf("empty list\n");
	}
	else
	{
		for(current = head; current != NULL; current = current->next)
		{
			printf("%d ", current->value);
		}
		printf("\n");
	}
}
