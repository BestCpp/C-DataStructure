#define _CRT_SECURE_NO_WARNINGS 1

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
//可以动态开辟空间的栈
typedef int StackData;
typedef struct Stack
{
	StackData* a;
	int top;//与顺序表的 size 一致
	int capacity;
}Stack;

void StackInit(Stack* ps);//栈初始化
void StackPush(Stack* ps,StackData x);//入栈
void StackPop(Stack* ps);//出栈
StackData StackTop(Stack* ps);//获取栈顶元素
bool StackEmpty(Stack* ps);//判断栈是否为空
int StackSize(Stack* ps);//计算栈元素个数
void StackDestroy(Stack* ps);//栈销毁


bool isValid(char* s);