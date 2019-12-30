#include"linklist.h"
#include<stdio.h>
#include<malloc.h>
#define MaxSize 100

// ������a���½�һ������Ϊn�ĵ�������ͷ�巨
void CreateListF(LinkNode*& L, ElemType a[], int n)
{
	LinkNode* s;   // �������ݽ������
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;    // ����ͷ��㣬��������Ϊ��

	for (int i = 0; i < n; i++)  // ѭ���������ݽ��s
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];    // �������ݽ��s 
		s->next = L->next;     // ���ý�����ԭͷ���֮���׽��֮ǰ
		L->next = s;
	}
}

// β�巨����������
void CreateListR(LinkNode *&L, ElemType a[], int n)
{
	LinkNode* s, * r;  // β���r��ʼָ��ͷ��㣬���ʼ��ָ��β���
	L = (LinkNode*)malloc(sizeof(LinkNode));    // ����ͷ���
	r = L;
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		r->next = s;   // �����ݽ��s�����β��ͬʱ����rָ��s
		r = s;
	}
	r->next = NULL;
}

// ��ʼ��������
void InitList(LinkNode*& L)
{
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
}

// ���ٵ�����
void DestoryList(LinkNode*& L)
{
	LinkNode* pre = L, * p = L->next;    // ��ʼʱpreָ��ͷ��㣬pָ���׽��
	while (p != NULL)    // ��p��Ϊ��ʱѭ��
	{
  		free(pre);    // ��һ�ͷ�
		pre = p;     // ����ƶ�ָ��
		p = pre->next;
	}
	free(pre);    // �˳�ѭ��������һ��β��㣬�����ͷ�
}

//  �жϵ������Ƿ�Ϊ��
bool ListIsNULL(LinkNode* L)
{
	return (L->next == NULL);
}

// ͨ������������ĳ���
int ListLength(LinkNode* L)
{
	int n = 0;    // ͷ������Ϊ0
	LinkNode* p = L;    // pָ��ָ��ͷ���
	while (p != NULL)
	{
		n++;
		p = p->next;    // p����
	}
	return (n);    // ѭ��������pָ��β��㣬���ؽ�����n
}

// ���������
void DispList(LinkNode* L)
{
	LinkNode* p = L->next;    // pָ��ָ���׽��
	while (p != NULL)      // p��Ϊ��ѭ��
	{
		printf("%d ", p->data);    // ����������
		p = p->next;       // ָ��ָ����
	}
	printf("\n");
}

// �������е�i��λ�õ�����Ԫ��ֵ
bool GetElem(LinkNode* L, int i, ElemType& e)
{
	LinkNode* p = L;    // ָ��pָ��ͷ���
	int j = 0;    // ��¼�����Ľ����
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

