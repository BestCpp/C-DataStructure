#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"
//初始化栈
void StackInit(Stack* ps)
{
	assert(ps);
	//栈的初始容量置空
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}
//入栈
void StackPush(Stack* ps,StackData x)
{
	assert(ps);
	//入栈只有一种方式，所以不需要将扩容独立封装
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
//出栈
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}
//获取栈顶元素
StackData StackTop(Stack* ps)
{
	assert(ps);
	return ps -> a[ps->top - 1];
}
//判断栈是否为空
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;//等于 0 则返回true，即栈为空
}
//计算栈中元素个数
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
//栈销毁
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

