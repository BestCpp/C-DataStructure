#define _CRT_SECURE_NO_WARNINGS 1


#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <stdio.h>


void Swap(int* p1, int* p2)
{
	assert(p1 && p2);
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void Print(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

//²åÈëÅÅÐò
void InsertSort(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end>=0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}

		}
		a[end + 1] = tmp;
	}
}



//Ï£¶ûÅÅÐò
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap /= 2;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

//Ñ¡ÔñÅÅÐò
void SelectSort(int* a, int n)
{
	assert(a);
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int mini = begin;
		int maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		if (maxi == mini)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}

//ÏòÏÂµ÷ÕûËã·¨
void AdjustDown(int* heap, int n, int parent)
{
	assert(heap);
	int minchild = parent * 2 + 1;
	while (minchild < n)
	{
		if (minchild + 1 < n && heap[minchild + 1] > heap[minchild])
		{
			minchild++;
		}
		if (heap[minchild] > heap[parent])
		{
			Swap(&heap[minchild], &heap[parent]);
			parent = minchild;
			minchild = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//¶ÑÅÅÐò
void HeapSort(int* a, int n)
{
	assert(a);
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	while (n)
	{
		Swap(&a[0], &a[n - 1]);
		AdjustDown(a, n - 1, 0);
		n--;
	}
}
int main()
{
	int size = 1000000;
	int* arr = (int*)malloc(sizeof(int)*size);
	assert(arr);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % size;
	}
	//InsertSort(arr, size);
	//ShellSort(arr, size);
	//SelectSort(arr, size);
	HeapSort(arr, size);
	Print(arr, size);
	return 0;
}