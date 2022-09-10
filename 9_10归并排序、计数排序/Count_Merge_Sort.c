#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

void Print(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}


void CountSort(int* a, int n)
{
	assert(a);
	//�ҵ����������С��Ԫ��
	int max = 0, min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
		if (min > a[i])
		{
			min = a[i];
		}
	}
	//����tmp���飬���ҽ���ӳ��
	int size = max - min + 1;
	int* tmp = (int*)calloc(1,sizeof(int) * size);
	assert(tmp);
	for (int i = 0; i < n; i++)
	{
		tmp[a[i] - min]++;
	}
	//��tmp����Ч�±꿽����arr����
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		while (tmp[i] != 0)
		{
			a[count++] = i;
			tmp[i]--;
		}
	}
}

void _MergeSort(int* a, int begin, int end, int* tmp)
{
	assert(a && tmp);
	//�ݹ鷵������
	if (begin >= end)
	{
		return;
	}
	//�ݹ�֪��Ԫ�ظ���Ϊ1
	int mid = (end + begin) / 2;
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid+1,end, tmp);

	//��ʼ�鲢����
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin1;
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
	//�鲢��Ҫһ��ռ�洢��������
	int* tmp = (int*)malloc(sizeof(int) * n);
	assert(tmp);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
	tmp = NULL;
}

void MergeSortNonR(int* a, int n)
{
	assert(a);
	int* tmp = (int*)calloc(1,sizeof(int) * n);
	assert(tmp);

	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int j = begin1;
			//�����һ����������û��Ԫ�أ�������
			if (begin1 >= n)
			{
				break;
			}
			//����ڶ�����������û��Ԫ�أ�������
			if (begin2 >= n)
			{
				break;
			}
			//����ڶ�����������Ԫ�ظ�������gap
			//�ͽ���ЧԪ�����������������
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
			//ÿ�ɹ��鲢����һ�飬�͸���һ��
			//ע�⣺������ÿһ����������ٸ��ƻ�ԭ����
			memcpy(a + i, tmp + i, sizeof(int) * (end2-i + 1));
		}
		gap *= 2;
	}
	free(tmp);
	tmp = NULL;
}
int main()
{
	int size = 1000000;
	int* arr = (int*)malloc(sizeof(int) * size);
	assert(arr);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand();
	}
	//CountSort(arr, size);
	//MergeSort(arr, size);
	MergeSortNonR(arr, size);
	Print(arr, size);
	free(arr);
	arr = NULL;
	return 0;
}