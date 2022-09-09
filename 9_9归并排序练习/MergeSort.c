#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

//void _MergeSort(int* a, int begin, int end, int* tmp)
//{
//	assert(a && tmp);
//	if (begin >= end)
//	{
//		return;
//	}
//	//µÝ¹é
//	int mid = (begin + end) / 2;
//	_MergeSort(a, begin, mid, tmp);
//	_MergeSort(a, mid + 1, end, tmp);
//
//	//¹é²¢0
//	int begin1 = begin, end1 = mid;
//	int begin2 = mid + 1, end2 = end;
//	int i = begin;
//	while (begin1 <= end1 && begin2 <= end2)
//	{
//		if (a[begin1] <= a[begin2])
//		{
//			tmp[i++] = a[begin1++];
//		}
//		else
//		{
//			tmp[i++] = a[begin2++];
//		}
//	}
//	while (begin1 <= end1)
//	{
//		tmp[i++] = a[begin1++];
//	}
//	while (begin2 <= end2)
//	{
//		tmp[i++] = a[begin2++];
//	}
//
//	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
//}


//void MergeSort(int* a, int n)
//{
//	assert(a);
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	assert(tmp);
//	_MergeSort(a, 0, n - 1, tmp);
//	free(tmp);
//	tmp = NULL;
//}

//·ÇµÝ¹é
void _MergeSortNonR(int* a, int n)
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
			if (end1 >= n)
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
			memcpy(a+i, tmp+i, sizeof(int) * (end2-i+1));

		}
		gap *= 2;
	}
	free(tmp);
	tmp = NULL;

}
void MergeSortNonR(int* a, int n)
{
	assert(a);
	_MergeSortNonR(a, n);
}

void Print(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
int main()
{
	int size = 1000000;
	int* arr = (int*)malloc(sizeof(int) * size);
	assert(arr);
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand();
	}
	//MergeSort(arr, size);
	MergeSortNonR(arr, size);
	Print(arr, size);
	return 0;
}