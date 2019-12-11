#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<iostream>
using namespace std;

typedef char ElemType;
typedef struct DNode
{
	ElemType data;    // 数据域
	struct DNode* prior;    // 前驱指针域
	struct DNode* next;		// 后继指针域
}DLinkNode;        // 双链表结点

// 初始化双链表(创建头结点)
void InitDList(DLinkNode*& L)
{
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->next = L->prior = NULL;
}

// 由数组a中n个元素头插法建立双链表
void CreateDListF(DLinkNode *&L,ElemType a[],int n)
{
	DLinkNode* s;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));    // 创建头结点
	L->prior = L->next = NULL;			// 头结点的前驱跟后继均为NULL
	for (int i = n-1; i >= 0; i--)
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));    // 创建数据结点s
		s->data = a[i];			// 元素ai赋值给s->data
		s->next = L->next;		  // 头插法插入数据结点s
		if (L->next != NULL)		// 若非空，修改L->data的前驱指针
			L->next->prior = s;		
		L->next = s;        
		s->prior = L;      // 插入元素后修改数据结点s的前驱指针
	}
}

//  遍历输出双链表
void DispDList(DLinkNode *L)
{
	DLinkNode*pre = L,* p = pre->next;    // 遍历指针p
	while (p != NULL)
	{
		printf(" %c ", p->data);
		pre = p;
		p = p->next;
	}
	printf("\n");
}

// 由数组a中n个元素尾插法建立双链表
void CreateDListL(DLinkNode *&L, ElemType a[], int n)
{
	DLinkNode* s, * r;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));    // 创建头结点
	r = L;      // r指针初始指向头结点，之后一直指向尾结点
	for (int i = 0; i < n; i++)
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));    // 创建数据结点s
		s->data = a[i];				// 赋值
		r->next = s;				// 尾插法插入数据结点s
		s->prior = r;				
		r = s;             // 插入完成后更新r指针
	}
	r->next = NULL;      // 尾结点的next指向NULL
}

// 在双链表中的第i个位置上插入值为e的结点
bool InsertElem(DLinkNode*& L, int i, ElemType e)
{
	int j = 0;
	DLinkNode* p = L, * s;

	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	s = (DLinkNode*)malloc(sizeof(DLinkNode));
	s->data = e;
	s->next = p->next;
	if (p->next != NULL)
		p->next->prior = s;
	p->next = s;
	s->prior = p;
	return true;
}

// 判断双链表是否为空
void ListIsEmpty(DLinkNode* L)
{
	if (L->next == NULL)
		printf(" Yes!\n");
	else
		printf(" No!\n");
}

// 求双链表的长度(结点个数)
void LenDList(DLinkNode* L)
{
	int i = 0;
	DLinkNode* p = L;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	printf(" Length: %d\n",i-1);
}

// 输出数组
void DispArray(ElemType a[],int n)
{
	for (int i = 0; i < n; i++)
		printf(" %c ", a[i]);
	printf("\n");
}

// 销毁双链表
void DestoryDList(DLinkNode*& L)
{
	DLinkNode* p = L->next, * pre = L;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}

// 查找双链表中第i个结点的元素值
bool FindElem(DLinkNode *L, int i)
{
	int j = 0;
	DLinkNode* p = L;
	if (i <= 0)
		return false;
	while (j < i  && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
		printf(" 第%d个元素值为：%c ", i,p->data);
	printf("\n");
	return true;
}

// 查找第一个与元素值e匹配的元素序号
bool FindLoc(DLinkNode *L,ElemType e)
{
	int j = 0;
	DLinkNode* p = L;
	while (p != NULL && p->data != e)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		printf(" 元素值为%c的元素在第%d个 \n", e, j);
		return true;
	}
}

// 修改第i个结点的元素值为e
bool ChangeElem(DLinkNode*& L, int i,ElemType e)
{
	int j = 0;
	DLinkNode* p = L;
	if (i <= 0)
		return false;
	while (j < i && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		p->data = e;
		return true;
	}
}

// 删除第i个元素
bool DelElem(DLinkNode *&L,int i)
{
	int j = 0;
	DLinkNode* p = L,*q;
	ElemType e;
	if (i <= 0)
		return false;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		q = p->next;
		if (q == NULL)
			return false;
		e = q->data;
		p->next = q->next;
		if (p->next != NULL)
			p->next->prior = p;
		free(q);
		printf(" 被删除的元素为 %c\n", e);
		return true;
	}
}



int main()
{
	clock_t start, end;
	double delta;
	start = clock();
	DLinkNode* L, * l;
	ElemType a[5] = { 'a','b','c','d','e'};
	printf("初始化双链表l");
	InitDList(l);
	DispDList(l);
	printf("\n 数组a:\n");
	DispArray(a, 5);
	printf("\n 尾插法建立双链表L\n");
	CreateDListL(L, a, 5);
	DispDList(L);
	printf("\n 双链表L是否为空？\n");
	ListIsEmpty(L);
	printf("\n 双链表l是否为空？\n");
	ListIsEmpty(l);
	printf("\n L的长度\n");
	LenDList(L);
	printf("\n 查找L中第3个元素值\n");
	FindElem(L, 3);
	printf("\n 查找元素值为'c'的元素位置\n");
	FindLoc(L, 'c');
	printf("\n 修改第5个元素为'm'\n");
	ChangeElem(L, 5, 'm');
	DispDList(L);
	printf("\n 在L第4个位置上插入f元素\n");
	InsertElem(L, 4, 'f');
	DispDList(L);
	printf("\n L的长度\n");
	LenDList(L);
	printf("\n 删除L第3个位置上的元素\n");
	DelElem(L, 3);
	DispDList(L);
	
	printf("\n 销毁双链表L，l\n");
	DestoryDList(L);
	DestoryDList(l);

	end = clock();
	delta = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "程序运行时间为: " << delta << "秒！" << endl;
	return 0;
}