#define _CRT_SECURE_NO_WARNINGS 1


#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <stdio.h>
#include "Stack.h"

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

//插入排序
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



//希尔排序
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

//选择排序
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

//向下调整算法
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

//堆排序
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

//冒泡排序
void BubbleSort(int* a, int n)
{
	assert(a);
	int flag = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j] + 1);
				flag = 1;
			}
		}
		if (!flag)
		{
			break;
		}
	}
}

//三数取中
int GetMidNum(int* a, int left, int right)
{
	assert(a);
	int mid = (right + left) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

//Hoare法
int PartSort1(int* a, int left, int right)
{
	assert(a);
	int mid = GetMidNum(a, left, right);
	Swap(&a[left], &a[mid]);
	int keyi = left;
	while (left < right)
	{
		while (left<right && a[right] >= a[keyi])
		{
			right--;
		}
		while (left<right && a[left] <= a[keyi])
		{
			left++;
		}
		if (left < right)
		{
			Swap(&a[left], &a[right]);
		}
	}
	int meeti = left;
	Swap(&a[meeti], &a[keyi]);
	return meeti;
}

//挖坑法
int PartSort2(int* a, int left, int right)
{
	assert(a);
	int mid = GetMidNum(a, left, right);
	Swap(&a[left], &a[mid]);
	int key = a[left];
	int hole = left;
	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;

		while (left < right && a[left] <= key)
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}

//前后指针法
int PartSort3(int* a, int left, int right)
{
	assert(a);
	int mid = GetMidNum(a, left, right);
	Swap(&a[left], &a[mid]);
	int keyi = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			prev++;
			Swap(&a[cur], &a[prev]);
		}

		cur++;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}

//快速排序
void QuickSort(int* a, int left, int right)
{
	assert(a);

	//递归法
	//if (left >= right)
	//{
	//	return;
	//}
	////int keyi = PartSort1(a, left, right);
	////int keyi = PartSort2(a, left, right);
	//int keyi = PartSort3(a, left, right);

	//if (right - left <= 16)
	//{
	//	InsertSort(a+left, right - left + 1);
	//}
	//else
	//{
	//	QuickSort(a, left, keyi - 1);
	//	QuickSort(a, keyi + 1, right);
	//}


	//非递归
	Stack st;
	StackInit(&st);
	StackPush(&st, right);
	StackPush(&st, left);

	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);
		int right = StackTop(&st);
		StackPop(&st);

		int keyi = PartSort2(a, left, right);

		if (left < keyi - 1)
		{
			StackPush(&st, keyi - 1);
			StackPush(&st, left);
		}
		
		if (keyi + 1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, keyi + 1);
		}
		
	}
	StackDestroy(&st);
}
int main()
{
	int size = 1000;
	int* arr = (int*)malloc(sizeof(int)*size);
	assert(arr);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand();
	}
	//InsertSort(arr, size);
	//ShellSort(arr, size);
	//SelectSort(arr, size);
	//HeapSort(arr, size);
	//BubbleSort(arr, size);
	QuickSort(arr, 0, size - 1);
	Print(arr, size);
	return 0;
}