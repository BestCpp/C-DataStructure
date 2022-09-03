#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

void Swap(int* p1, int* p2)
{
	assert(p1 && p2);
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void Print(int* a,int n)
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
		while (end >= 0)
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
//三数取中
//假定给的数组是一个有序数列
//就找到中位数的下标
int Get_Mid_Key(int* a, int left, int right)
{
	assert(a);
	int mid = (left + right) / 2;
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

//hoare法
int PartSort1(int* a, int left, int right)
{
	assert(a);

	int mid = Get_Mid_Key(a, left, right);
	//我们是选取left做为key的
	//所以要保证left位置不能是最大值或者最小值
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
	Swap(&a[keyi], &a[meeti]);
	return meeti;

}

//挖坑法
int PartSort2(int* a, int left, int right)
{
	assert(a);
	int mid = Get_Mid_Key(a, left, right);
	Swap(&a[left], &a[mid]);
	int key = a[left];
	int hole = left;
	while (left < right)
	{
		//right找到比key小的，填坑
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;

		//left找到比key大的，填坑
		while (left < right && a[left] <= key)
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	//把key放到坑里
	a[hole] = key;
	//返回key的下标
	return hole;
}

//前后指针法
int PartSort3(int* a, int left, int right)
{
	assert(a);
	int mid = Get_Mid_Key(a, left, right);
	Swap(&a[left], &a[mid]);
	int keyi = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			prev++;
			Swap(&a[prev], &a[cur]);
		}

		cur++;
	}
	//最后cur越界，prev的值和keyi的值互换
	Swap(&a[keyi], &a[prev]);
	//返回key的下标
	return prev;
}

//快速排序
void QuickSort(int* a, int left, int right)
{
	assert(a);
	if (left >= right)
	{
		return;
	}

	//子区间优化
	if (right - left <= 16)
	{
		InsertSort(a + left, right - left+1);
	}
	else
	{
		//int keyi = PartSort1(a, left, right);
		//int keyi = PartSort2(a, left, right);
		int keyi = PartSort3(a, left, right);
		QuickSort(a, left, keyi - 1);
		QuickSort(a, keyi + 1, right);
	}

	

}
int main()
{
	int size = 1000;
	int* arr = (int*)malloc(sizeof(int) * size);
	assert(arr);
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand();
	}
	QuickSort(arr, 0, size - 1);
	Print(arr, size);
	return 0;
}