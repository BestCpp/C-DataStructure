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

//��������
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
//����ȡ��
//�ٶ�����������һ����������
//���ҵ���λ�����±�
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

//hoare��
int PartSort1(int* a, int left, int right)
{
	assert(a);

	int mid = Get_Mid_Key(a, left, right);
	//������ѡȡleft��Ϊkey��
	//����Ҫ��֤leftλ�ò��������ֵ������Сֵ
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

//�ڿӷ�
int PartSort2(int* a, int left, int right)
{
	assert(a);
	int mid = Get_Mid_Key(a, left, right);
	Swap(&a[left], &a[mid]);
	int key = a[left];
	int hole = left;
	while (left < right)
	{
		//right�ҵ���keyС�ģ����
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;

		//left�ҵ���key��ģ����
		while (left < right && a[left] <= key)
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	//��key�ŵ�����
	a[hole] = key;
	//����key���±�
	return hole;
}

//ǰ��ָ�뷨
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
	//���curԽ�磬prev��ֵ��keyi��ֵ����
	Swap(&a[keyi], &a[prev]);
	//����key���±�
	return prev;
}

//��������
void QuickSort(int* a, int left, int right)
{
	assert(a);
	if (left >= right)
	{
		return;
	}

	//�������Ż�
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