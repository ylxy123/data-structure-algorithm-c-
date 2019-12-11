#include<stdio.h>
#include<malloc.h>

typedef char ElemType;
typedef struct Node
{
	ElemType data;
	struct Node* next;
}LinkStack;      // 链栈

// 规定所有栈的操作均在头结点完成

// 初始化链栈
void InitLStack(LinkStack*& s)
{
	s = (LinkStack*)malloc(sizeof(LinkStack));
	s->next = NULL;
}

// 销毁链栈
void DestoryLStack(LinkStack*& s)
{
	LinkStack* pre = s,*p = pre->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}

// 判断栈是否为空
bool IsStackEmpty(LinkStack* s)
{
	return (s->next == NULL);
}

// 元素e进栈
void Push(LinkStack*& s, ElemType e)
{
	LinkStack *q;
	q = (LinkStack*)malloc(sizeof(LinkStack));
	q->data = e;
	q->next = s->next;
	s->next = q;
}

// 栈顶元素e出栈
bool Pop(LinkStack*& s, ElemType& e)
{
	LinkStack* q = s->next;
	if (s->next == NULL)
		return false;
	e = q->data;
	s->next = q->next;
	free(q);
	return true;
}

// 遍历栈中所有元素
void DispLStack(LinkStack* s)
{
	LinkStack* p = s->next;
	while (p != NULL)
	{
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");
}

// 返回栈的长度
int LenLStack(LinkStack* s)
{
	int i = 0;
	LinkStack*p = s->next;
	if (p == NULL)
		return 0;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	printf("%d ", i);
	return i;
}

// 取栈顶元素
bool GetElem(LinkStack* s, ElemType& e)
{
	if (s->next == NULL)
		return false;
	e = s->next->data;
	return true;
}

// 设计一个算法，扫描字符串中的括号是否配对，若配对返回true，若不配对返回false
/*  设计思路：
  设置一个链栈st，扫描exp，遇到左括号进栈，若继续遇到右括号，若栈中有元素，返回true；否则返回false
*/
bool Match(char exp[], int n)
{
	int i = 0;
	ElemType e;
	LinkStack* st;
	InitLStack(st);
	bool match = true;
	while (i < n && match)
	{
		if (exp[i] == '(')
			Push(st, exp[i]);
		else if (exp[i] == ')')
		{
			if (st->next != NULL)
			{
				if (st->next->data != '(')
					match = false;
				else
					Pop(st, e);
			}
			else
				match = false;
		}
		i++;
	}
	if (!IsStackEmpty(st))
		match = false;
	DestoryLStack(st);
	return match;
}




int main()
{
	ElemType e;
	LinkStack* s;
	char a[15] = "asda(sd)asdasd";
	printf("\n 初始化链栈s \n");
	InitLStack(s);
	printf("\n 元素'y'进栈 \n");
	Push(s, 'y');
	DispLStack(s);
	printf("\n 元素'x'进栈 \n");
	Push(s, 'l');
	DispLStack(s);
	printf("\n 元素'l'进栈 \n");
	Push(s, 'x');
	DispLStack(s);
	printf("\n 元素'y'进栈 \n");
	Push(s, 'y');
	DispLStack(s);
	printf("\n 元素'^'进栈 \n");
	Push(s, '^');
	DispLStack(s);
	printf("\n 栈顶元素出栈 \n");
	Pop(s, e);
	DispLStack(s);
	printf("\n 栈元素个数 \n");
	LenLStack(s);
	printf("\n 输出栈中元素 \n");
	DispLStack(s);

	printf("\n 销毁栈 \n");
	DestoryLStack(s);

	printf("\n判断\"asda(sd)asdasd\"中圆括号是否匹配？\n");
	if(Match(a, 15))
		printf("匹配!\n");
	else
	
		printf("不匹配！\n");


	

	return 0;
}