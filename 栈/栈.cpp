#include<stdio.h>
#include<malloc.h>
#define MaxSize 100

typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];    // 存放栈中元素
	int top;        // 栈顶指针，存放栈顶元素在data数组中的下标
}SqStack;    // 顺序栈

	/*
判断栈是否为空
	s->top == -1
栈满的条件
	s->top == MaxSize - 1
元素e进栈操作
	先top++，然后将元素e放在栈顶指针处
元素e出栈操作
	先将栈顶元素取出放入e中，然后top--
	*/

// 栈的初始化
void InitStack(SqStack*& s)
{
	s = (SqStack*)malloc(sizeof(SqStack));    // 分配一个存储顺序栈的空间，存放首地址
	s->top = -1;         // 栈顶指针置为-1
}

// 销毁栈
void DestoryStack(SqStack*& s)
{
	free(s);
}

// 判断栈是否为空
bool IsSatckEmpty(SqStack *s)
{
	if (s->top == -1)
	{
		printf("Yes!\n");
		return (s->top == -1);
	}
	else
	{
		printf("No!\n");
		return false;
	}
		
}

// 元素e进栈
bool Push(SqStack*& s, ElemType e)
{
	if (s->top == MaxSize - 1)    // StackOverFlow 栈溢出
		return false;
	s->top++;         // 栈顶指针自增1
	s->data[s->top] = e;      // 元素插入栈顶
	return true;
}

// 元素e出栈
bool Pop(SqStack*& s,ElemType &e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}

// 返回栈顶元素
bool TopElem(SqStack*& s, ElemType& e)
{
	if (s->top == -1)
	{
		printf("StackOverFlow!");
		return false;
	}
	e = s->data[s->top];
	return true;
}

// 展示栈中元素
void DispStack(SqStack *s)
{
	for (int i = 0; i <= s->top; i++)
	{
		printf("%c ", s->data[i]);
	}
	printf("\n");
}

// 返回栈长度
int LenStack(SqStack*& s)
{
	int i=0;
	if (s->top == MaxSize-1)
	{
		i = MaxSize;
		printf("栈满√\n");
		return i;
	}
	else if (s->top == -1)
	{ 
		printf("栈为空\n");
		return -1;
	}
	else
	{ 
		i = s->top + 1;
		printf("栈的长度为%d\n", i);
		return i;
	}
}

// 设计一个算法判断一个字符串是否为对称串
bool IsStrSymmetric(ElemType str[])
{
	SqStack* st;
	ElemType e;
	InitStack(st);
	for (int i = 0; str[i] != '\0'; i++)
		Push(st, str[i]);
	for (int i = 0; str[i] != '\0'; i++)
	{
		Pop(st, e);
		if (str[i] != e)
		{
			DestoryStack(st);
			printf("该字符串并不对称\n");
			return false;
		}
	}
	DestoryStack(st);
	printf("该字符串对称√\n");
	return true;
}

int main()
{
	//ElemType e;
	SqStack* s,*st;
	ElemType str[10] = "abcddcba";

	ElemType str2[7] = "apple";
	InitStack(s);
	Push(s, 'a');
	Push(s, 'b');
	Push(s, 'c');
	DispStack(s);
	LenStack(s);
	DestoryStack(s);
	
	printf("判断abccba是否为对称串？\n");
	IsStrSymmetric(str);
	printf("判断apple是否为对称串？\n");
	IsStrSymmetric(str2);
	InitStack(st);
	IsSatckEmpty(st);
	LenStack(st);
	Push(st, 'q');
	IsSatckEmpty(st);
	LenStack(st);
	DestoryStack(st);
	
	



	return 0;
}