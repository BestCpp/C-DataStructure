#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"
//��ʼ��ջ
void StackInit(Stack* ps)
{
	assert(ps);
	//ջ�ĳ�ʼ�����ÿ�
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}
//��ջ
void StackPush(Stack* ps,StackData x)
{
	assert(ps);
	//��ջֻ��һ�ַ�ʽ�����Բ���Ҫ�����ݶ�����װ
	if (ps->top == ps->capacity)
	{
		int NewCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		StackData* tmp = (StackData*)realloc(ps->a, NewCapacity*sizeof(StackData));
		assert(tmp);
		ps->a = tmp;
		ps->capacity = NewCapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
//��ջ
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}
//��ȡջ��Ԫ��
StackData StackTop(Stack* ps)
{
	assert(ps);
	return ps -> a[ps->top - 1];
}
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;//���� 0 �򷵻�true����ջΪ��
}
//����ջ��Ԫ�ظ���
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
//ջ����
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

