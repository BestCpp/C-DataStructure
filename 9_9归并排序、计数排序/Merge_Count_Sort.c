#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}


//计数排序
void CountSort(int* arr, int n)
{
	
	//找最大、最小
	int max = 0;
	int min = arr[0];
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	int size = max - min + 1;
	int* count = (int*)calloc(1, sizeof(int) * size);
	assert(count);

	//计数
	for (int i = 0; i < n; i++)
	{
		count[arr[i] - min]++;
	}

	//拷贝至原数组
	int reti = 0;
	for (int i = 0; i < size; i++)
	{
		while (count[i] != 0)
		{
			arr[reti++] = i + min;
			count[i]--;
		}
	}
}

//归并排序——递归
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	assert(a && tmp);
	//递归停止条件
	if (begin >= end)
	{
		return;
	}
	int mid = (begin + end) / 2;
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid+1, end, tmp);

	//归并排序
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));

}
void MergeSort(int* a, int n)
{
	assert(a);
	int* tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp);

	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
	tmp = NULL;
}

//归并排序——非递归
void MergeSortNonR(int* a, int n)
{
	assert(a);
	int* tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp);

	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int j = begin1;
			if (begin1 >= n)
			{
				break;
			}
			if (begin2 >= n)
			{
				break;
			}
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] <= a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
			memcpy(a + i, tmp +i, sizeof(int) * (j - i));
		}
		gap *= 2;
	}
}
int main()
{
	int n = 10;
	int* arr = (int*)malloc(sizeof(int) * n);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}
	assert(arr);
	//CountSort(arr, n);
	//MergeSort(arr, n);
	MergeSortNonR(arr, n);
	Print(arr, n);


	free(arr);
	arr = NULL;
	return 0;
}