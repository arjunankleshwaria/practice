#include<stdio.h>

void print_array(int array[]);
void bubble_sort(int a[]);
void insertion_sort(int b[]);
void selection_sort(int c[]);
void merge_sort(int d[]);
void heap_sort(int e[]);
void quick_sort(int f[]);

int main()
{
	int a[10] = {7, 4, 2, 8, 1, 0, 6, 5, 9, 3}; // for bubble sort
	int b[10] = {7, 4, 2, 8, 1, 0, 6, 5, 9, 3}; // for insertion sort
	int c[10] = {7, 4, 2, 8, 1, 0, 6, 5, 9, 3}; // for selection sort
	int d[10] = {7, 4, 2, 8, 1, 0, 6, 5, 9, 3}; // for merge sort
	int e[10] = {7, 4, 2, 8, 1, 0, 6, 5, 9, 3}; // for heap sort
	int f[10] = {7, 4, 2, 8, 1, 0, 6, 5, 9, 3}; // for quick sort

	printf("\noriginal array: ");
	print_array(a);
	bubble_sort(a);
	insertion_sort(b);
	selection_sort(c);
	merge_sort(d);
	heap_sort(e);
	quick_sort(f);
	printf("\n");
	return 0;
}

void print_array(int array[10])
{
	int i;
	for(i = 0; i < 10; i++)
		printf("%d ", array[i]);
	printf("\n");
}

void bubble_sort(int a[])
{
	int i, j, temp;
	int n = 10; // array size
	
	for(i = 0; i < n - 1; i++)
		for(j = i + 1; j < n; j++)
			if(a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
	
	printf("after bubble sort: ");
	print_array(a);
}

void insertion_sort(int b[])
{
	int i, j, temp;
	int n = 10; // array size
	
	for(i = 0; i < n - 1; i++)
	{
		j = i + 1;
		while((b[j - 1] > b[j]) && (j > 0))
		{
			temp = b[j - 1];
			b[j - 1] = b[j];
			b[j] = temp;
			j--;
		}
	}
	
	printf("after insertion sort: ");
	print_array(b);
}

void selection_sort(int c[])
{
	int i, j, temp;
	int n = 10; // array size
	int *s; // pointer to selected element
	
	for(i = 0; i < n - 1; i++)
	{
		s = &c[i];
		for(j = i + 1; j < n; j++)
			if(*s > c[j])
				s = &c[j];
		temp = *s;
		*s = c[i];
		c[i] = temp;
	}

	printf("after selection sort: ");
	print_array(c);
}

void merge_sort(int d[])
{

	printf("after merge sort: ");
	print_array(d);
}

void heap_sort(int e[])
{

	printf("after heap sort: ");
	print_array(e);
}

void quick_sort(int f[])
{

	printf("after quick sort: ");
	print_array(f);
}
