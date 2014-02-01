#include <stdio.h>
#include <stdlib.h>

typedef struct MaxHeap{
	int size;
	int *arr;
}MaxHeap;

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

void heapify(MaxHeap* maxheap, int idx)
{
	int largest = idx;
	int left = (2 * idx) + 1;
	int right = (2 * idx) + 2;

	if(maxheap->arr[left] > maxheap->arr[largest] && left < maxheap->size)
		largest = left;

	if(maxheap->arr[right] > maxheap->arr[largest] && right < maxheap->size)
		largest = right;

	if(largest != idx)
	{
		swap(&maxheap->arr[largest], &maxheap->arr[idx]);
		heapify(maxheap, largest);
	}
}

MaxHeap* buildHeap(int* arr, int size)
{
	MaxHeap* maxheap = malloc(sizeof(MaxHeap));
	maxheap->arr = arr;
	maxheap->size = size;

	int i;
	for(i = (maxheap->size - 2) / 2; i >= 0; i--)
		heapify(maxheap, i);

	return maxheap;
}

void heapSort(int* arr, int size)
{
	MaxHeap *maxheap = buildHeap(arr, size);
	while(maxheap->size > 1)
	{
		swap(&maxheap->arr[0], &maxheap->arr[maxheap->size - 1]);
		maxheap->size--;
		heapify(maxheap, 0);
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
