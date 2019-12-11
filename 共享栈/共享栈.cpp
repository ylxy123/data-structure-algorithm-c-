#include<stdio.h>
#include<malloc.h>
#define MaxSize 100


/*

栈空条件：
	top1 == -1;top2 == MaxSize
栈满条件：
	top1 == top2 - 1
元素x进栈：
	进栈1：top1++;data[top1] = x；进栈2：top2--;data[top2] = x
栈顶元素x出栈：
	出栈1：x = data[top1];top1--；出栈2：x = data[top2];top2++;

*/

typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top1, top2;
}DStack;    // 共享栈

// 初始化共享栈
void InitDStack(DStack*&s)
{
	s = (DStack*)malloc(sizeof(DStack));
	s->top1 = -1;
	s->top2 = MaxSize;
}

// 销毁共享栈 
void DestoryDStack(DStack*&s)
{
	free(s);
}

// 元素x入栈1
bool Push1(DStack*& s, ElemType x)
{
	if (s->top1 == s->top2 - 1)
		return false;
	s->top1++;
	s->data[s->top1] = x;
	return true;
}

// 元素x入栈2
bool Push2(DStack*& s, ElemType x)
{
	if (s->top1 == s->top2 - 1)
		return false;
	s->top2--;
	s->data[s->top2] = x;
	return true;
}

// 栈1栈顶元素x出栈
bool Pop1(DStack*& s, ElemType& x)
{
	if (s->top1 == -1)
		return false;
	x = s->data[s->top1];
	s->top1--;
	return true;
}

// 栈2栈顶元素出栈
bool Pop2(DStack*& s, ElemType& x)
{
	if (s->top2 == MaxSize)
		return false;
	x = s->data[s->top2];
	s->top2++;
	return true;
}

// 遍历输出栈1元素
void DispDStack1(DStack* s)
{
	for (int i = 0; i <= s->top1; i++)
	{
		printf("%c ", s->data[i]);
	}
	printf("\n");
}

// 遍历输出栈2元素
void DispDStack2(DStack* s)
{
	for (int i = MaxSize - 1; i >= s->top2; i--)
	{
		printf("%c ", s->data[i]);
	}
	printf("\n");
}

// 返回栈1长度
int LenDStack1(DStack* s)
{
	return (s->top1 + 1);
}

// 返回栈2长度
int LenDStack2(DStack* s)
{
	return (MaxSize - s->top2);
}


int main()
{
	DStack *s;
	InitDStack(s);
	Push1(s, 'a');
	Push1(s, 'b');
	Push1(s, 'c');
	Push2(s, 'z');
	Push2(s, 'y');
	Push2(s, 'x');
	DispDStack1(s);
	DispDStack2(s);
	printf("%d\n", LenDStack1(s));
	printf("%d\n", LenDStack2(s));
	DestoryDStack(s);
	
	return 0;
}
