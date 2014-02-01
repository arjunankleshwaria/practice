#include <stdio.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArray(int *arr, int size)
{
	int i = 0;
	printf("\n");
	for(i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void heapify(int *arr, int idx, int size)
{
	int largest = idx;
	int left = (2 * idx) + 1;
	int right = (2 * idx) + 2;

	if(arr[left] > arr[largest] && left < size)
		largest = left;

	if(arr[right] > arr[largest] && right < size)
		largest = right;

	if(largest != idx)
	{
		swap(&arr[largest], &arr[idx]);
		heapify(arr, largest, size);
	}
}

void buildHeap(int* arr, int size)
{
	int i;
	for(i = (size - 2) / 2; i >= 0; i--)
		heapify(arr, i, size);
}

void heapSort(int* arr, int size)
{
	buildHeap(arr, size);
	while(size > 1)
	{
		swap(&arr[0], &arr[size - 1]);
		size--;
		heapify(arr, 0, size);
	}
}

int main()
{
	int arr[] = {5, 2, 8, 3, 9, 4, 1, 0, 7, 6};
	int size = sizeof(arr) / sizeof(arr[0]);

	printArray(arr, size);
	heapSort(arr, size);
	printArray(arr, size);

	return 0;
}
