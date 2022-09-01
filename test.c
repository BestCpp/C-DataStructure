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
//œ£∂˚≈≈–Ú
void HillSort(int* arr, int n)
{
	assert(arr);
	int gap = n;
	int end = 0;
	int tmp = 0;
	while (gap > 1)
	{
		gap /= 2;
		for (int i = 0; i < n - gap; i++)
		{
			end = i;
			tmp = arr[end + gap];
			while (end >= 0)
			{
				if (tmp < arr[end])
				{
					arr[end + 1] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
	}
	
}

//—°‘Ò≈≈–Ú
void SelectSort(int* arr, int n)
{
	assert(arr);
	int begin = 0;
	int end = n - 1;
	int min = begin;
	int max = begin;
	while (begin < end)
	{
		for (int i = begin+1; i <= end; i++)
		{
			if (arr[i] < arr[min])
			{
				min = i;
			}
			if (arr[i] > arr[max])
			{
				max = i;
			}
		}
		Swap(&arr[begin], &arr[min]);
		if (max == begin)
		{
			max = min;
		}
		Swap(&arr[end], &arr[max]);
		begin++;
		max--;
	}
}

//√∞≈›≈≈–Ú
void BubbleSort(int* arr, int n)
{
	assert(arr);
	int flag = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n-i-1;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				flag = 1;
			}
		}
		if (!flag)
		{
			break;
		}
	}
}
int main()
{
	int size = 10000000;
	int* arr = (int*)malloc(sizeof(int) * size);
	assert(arr);
	srand((unsigned int)time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = i;
	}
	//HillSort(arr, size);
	//SelectSort(arr, size);
	BubbleSort(arr, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}