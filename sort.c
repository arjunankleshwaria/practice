/*********** Sorting Algorithms ***********/

#include<stdio.h>

void print_array(int array[]);
void exchange_sort(int a[]);
void insertion_sort(int b[]);
void selection_sort(int c[]);
void merge_sort(int d[], int low, int high);
void merge(int arr[], int low, int mid, int high);
void heap_sort(int e[]);
void quick_sort(int f[]);
void bubble_sort(int g[]);
void shell_sort(int h[]);

int main()
{
	int a[10] = {7, 4, 2, 8, 1, 0, 6, 5, 9, 3}; // for exchange sort
	int b[10] = {7, 4, 2, 8, 1, 0, 6, 5, 9, 3}; // for insertion sort
	int c[10] = {7, 4, 2, 8, 1, 0, 6, 5, 9, 3}; // for selection sort
	int d[10] = {7, 4, 2, 8, 1, 0, 6, 5, 9, 3}; // for merge sort
	int e[10] = {7, 4, 2, 8, 1, 0, 6, 5, 9, 3}; // for heap sort
	int f[10] = {7, 4, 2, 8, 1, 0, 6, 5, 9, 3}; // for quick sort
	int g[10] = {7, 4, 2, 8, 1, 0, 6, 5, 9, 3}; // for bubble sort
	int h[10] = {7, 4, 2, 8, 1, 0, 6, 5, 9, 3}; // for shell sort

	printf("\noriginal array: ");
	print_array(a);
	exchange_sort(a);
	insertion_sort(b);
	selection_sort(c);
	merge_sort(d, 0, 9);
	printf("after merge sort: ");
	print_array(d);
	heap_sort(e);
	quick_sort(f);
	bubble_sort(g);
	shell_sort(h);
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

void exchange_sort(int a[])
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
	
	printf("after exchange sort: ");
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
	int index_of_min; // selected (minimum) element
	
	for(i = 0; i < n - 1; i++)
	{
		index_of_min = i;
		for(j = i + 1; j < n; j++)
			if(c[index_of_min] > c[j])
				index_of_min = j;
		if(c[index_of_min] != c[i])
		{
			temp = c[index_of_min];
			c[index_of_min] = c[i];
			c[i] = temp;
		}
	}

	printf("after selection sort: ");
	print_array(c);
}

void merge_sort(int d[], int low, int high)
{
	if(low < high)
	{
		int mid = (low + high) / 2;
		merge_sort(d, low, mid);
		merge_sort(d, mid + 1, high);
		merge(d, low, mid, high);
	}
}

void merge(int arr[], int low, int mid, int high)
{
	int left = low;
	int right = mid + 1;
	int temp[high - low + 1];
	int k = 0;

	while(left <= mid && right <= high)
	{
		if(arr[left] < arr[right])
			temp[k++] = arr[left++];
		else
			temp[k++] = arr[right++];
	}

	while(left <= mid)
		temp[k++] = arr[left++];
	while(right <= high)
		temp[k++] = arr[right++];

	int m = 0;
	while(m < (high - low + 1))
	{
		arr[low + m] = temp[m];
		m++;
	}
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

void bubble_sort(int g[])
{
	int i, j, temp;
	int n = 10; // array size

	for(i = 0; i < n - 1; i++)
		for(j = 0; j < n - 1 - i; j++)
			if(g[j] > g[j + 1])
			{
				temp = g[j + 1];
				g[j + 1] = g[j];
				g[j] = temp;
			}
	
	printf("after bubble sort: ");
	print_array(g);
}

void shell_sort(int h[])
{
	
	printf("after shell sort: ");
	print_array(h);
}
