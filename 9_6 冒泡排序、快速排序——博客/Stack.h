#define _CRT_SECURE_NO_WARNINGS 1

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
//���Զ�̬���ٿռ��ջ
typedef int StackData;
typedef struct Stack
{
	StackData* a;
	int top;//��˳���� size һ��
	int capacity;
}Stack;

void StackInit(Stack* ps);//ջ��ʼ��
void StackPush(Stack* ps,StackData x);//��ջ
void StackPop(Stack* ps);//��ջ
StackData StackTop(Stack* ps);//��ȡջ��Ԫ��
bool StackEmpty(Stack* ps);//�ж�ջ�Ƿ�Ϊ��
int StackSize(Stack* ps);//����ջԪ�ظ���
void StackDestroy(Stack* ps);//ջ����


bool isValid(char* s);