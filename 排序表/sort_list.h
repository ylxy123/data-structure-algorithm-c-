#ifndef SORT_LIST_H
#define SORT_LIST_H

#include<stdio.h>
#define MAXL 100    // ��󳤶�

typedef int KeyType;
typedef char InfoType;
typedef struct
{
	KeyType key;
	InfoType data;
}RecType;

// ����Ԫ��
void Swap(RecType& x, RecType& y);

// ����˳���
void Createlist(RecType R[], KeyType keys[], int n);

// ���˳���
void DispList(RecType R[], int n);

#endif
