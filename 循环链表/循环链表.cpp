#include<stdio.h>
#include<malloc.h>

typedef char ElemType;
typedef struct CNode
{
	ElemType data;
	struct CNode* prior;
	struct CNode* next;
}CLinkNode;

// 头插法创建循环链表
void CreateCListF(CLinkNode*& L, ElemType a[], int n)
{
	int i;
	CLinkNode* s;
	L = (CLinkNode*)malloc(sizeof(CLinkNode));
	L->next = L->prior = NULL;
	for (i = 0; i < n; i++);
	{
		s = (CLinkNode*)malloc(sizeof(CLinkNode));
		s->data = a[i];
		s->next = L->next;
		if (L->next != NULL)
			L->next->prior = s;
		L->next = s;
		s->prior = L;
	}
	s = L->next;
	while (s->next != NULL)
		s = s->next;
	s->next = L;
	L->prior = s;
}

// 尾插法创建循环双链表
void CreateCListL(CLinkNode *&L, ElemType a[], int n)
{
	CLinkNode* s, * r;
	L = (CLinkNode*)malloc(sizeof(CLinkNode));
	r = L;
	L->next = L->prior = NULL;
	for (int i = 0; i < n; i++)
	{
		s = (CLinkNode*)malloc(sizeof(CLinkNode));
		s->data = a[i];
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = L;
	L->prior = r;
}

// 输出循环链表
void DispCList(CLinkNode* L)
{
	CLinkNode* p = L->next;
	while (p != L)
	{
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");
}

// 销毁循环链表
void DestoryCList(CLinkNode*& L)
{
	CLinkNode* pre = L,*p = pre->next;
	while (p != L)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}




int main()
{
	ElemType a[10] = { 'a','a','c','b','c','d','e','f','g','g' };
	CLinkNode* L;
	CreateCListL(L, a, 10);
	DispCList(L);
	DestoryCList(L);

	return 0;
}