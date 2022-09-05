#define _CRT_SECURE_NO_WARNINGS 1




//插入排序
//void InsertSort(int* a, int n)
//{
//	assert(a);
//	for (int i = 0; i < n - 1; i++)
//	{
//		int end = i;//记录从后向前比较的开始位置
//		int tmp = a[end + 1];
//		//当 end<0 时数组越界
//		while (end >= 0)
//		{
//			//如果tmp比比较的数字小，那么数组就进行覆盖调整
//			//我们的画图是让tmp移动，但是我们的代码是让数组移动
//			if (tmp < a[end])
//			{
//				a[end + 1] = a[end];
//				end--;
//			}
//			else
//			{
//				break;
//			}
//		}
//		//插入
//		a[end + 1] = tmp;
//	}
//}



//希尔排序
//void ShellSort(int* a, int n)
//{
//	assert(a);
//	int gap = n;//默认第一次的gap为n
//	while (gap > 1)
//	{
//		gap /= 2;//依次减小区间，最后一次gap一定为 1
//
//		直接插入排序
//		for (int i = 0; i < n - gap; i++)
//		{
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (tmp < a[end])
//				{
//					a[end + gap] = a[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			a[end + gap] = tmp;
//		}
//	}
//}


//选择排序
//void SelectSort(int* a, int n)
//{
//	assert(a);
//	int begin = 0;
//	int end = n - 1;
//	int maxi = begin;
//	int mini = end;
//	while (begin < end)
//	{
//		for (int i = begin + 1; i <= end; i++)
//		{
//			if (a[mini] > a[i])
//			{
//				mini = i;
//			}
//			if (a[maxi] < a[i])
//			{
//				maxi = i;
//			}
//		}
//		Swap(&a[begin], &a[mini]);
//
//		//如果begin位置上放的是最大的数
//		//那么就要改变一下maxi的位置
//		if (maxi == begin)
//		{
//			maxi = mini;
//		}
//		Swap(&a[end], &a[maxi]);
//		begin++;
//		end--;
//	}
//}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

void Print(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}


void Swap(int* p1, int* p2)
{
	assert(p1 && p2);
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

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

void HeapSort(int* a, int n)
{
	assert(a);
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	while (n)
	{
		Swap(&a[0], &a[n - 1]);
		AdjustDown(a, n-1, 0);
		n--;
	}
}
int main()
{
	//定义数组的大小
	int size = 1000000;
	int* arr = (int*)malloc(sizeof(int) * size);
	assert(arr);

	//给数组随机赋值
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand();
	}

	//InsertSort(arr, size);
	//ShellSort(arr, size);
	//SelectSort(arr, size);
	HeapSort(arr, size);
	Print(arr, size);
	return 0;
}