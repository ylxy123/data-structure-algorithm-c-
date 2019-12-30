#include"linklist.h"
#include<stdio.h>
#include<malloc.h>
#define MaxSize 100

// 从数组a中新建一个长度为n的单链表——头插法
void CreateListF(LinkNode*& L, ElemType a[], int n)
{
	LinkNode* s;   // 声明数据结点类型
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;    // 创建头结点，将其后继置为空

	for (int i = 0; i < n; i++)  // 循环创建数据结点s
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];    // 创建数据结点s 
		s->next = L->next;     // 将该结点插入原头结点之后，首结点之前
		L->next = s;
	}
}

// 尾插法建立单链表
void CreateListR(LinkNode *&L, ElemType a[], int n)
{
	LinkNode* s, * r;  // 尾结点r初始指向头结点，随后始终指向尾结点
	L = (LinkNode*)malloc(sizeof(LinkNode));    // 创建头结点
	r = L;
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		r->next = s;   // 将数据结点s插入表尾，同时更新r指向s
		r = s;
	}
	r->next = NULL;
}

// 初始化单链表
void InitList(LinkNode*& L)
{
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
}

// 销毁单链表
void DestoryList(LinkNode*& L)
{
	LinkNode* pre = L, * p = L->next;    // 初始时pre指向头结点，p指向首结点
	while (p != NULL)    // 当p不为空时循环
	{
  		free(pre);    // 逐一释放
		pre = p;     // 向后移动指针
		p = pre->next;
	}
	free(pre);    // 退出循环后留下一个尾结点，将其释放
}

//  判断单链表是否为空
bool ListIsNULL(LinkNode* L)
{
	return (L->next == NULL);
}

// 通过遍历求单链表的长度
int ListLength(LinkNode* L)
{
	int n = 0;    // 头结点序号为0
	LinkNode* p = L;    // p指针指向头结点
	while (p != NULL)
	{
		n++;
		p = p->next;    // p后移
	}
	return (n);    // 循环结束，p指向尾结点，返回结点个数n
}

// 输出单链表
void DispList(LinkNode* L)
{
	LinkNode* p = L->next;    // p指针指向首结点
	while (p != NULL)      // p不为空循环
	{
		printf("%d ", p->data);    // 输出结点数据
		p = p->next;       // 指针指向后继
	}
	printf("\n");
}

// 求单链表中第i个位置的数据元素值
bool GetElem(LinkNode* L, int i, ElemType& e)
{
	LinkNode* p = L;    // 指针p指向头结点
	int j = 0;    // 记录遍历的结点数
	while (j < i && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		e = p->data;
		return true;
	}
}

