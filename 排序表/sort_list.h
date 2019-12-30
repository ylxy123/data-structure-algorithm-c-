#ifndef SORT_LIST_H
#define SORT_LIST_H

#include<stdio.h>
#define MAXL 100    // 最大长度

typedef int KeyType;
typedef char InfoType;
typedef struct
{
	KeyType key;
	InfoType data;
}RecType;

// 交换元素
void Swap(RecType& x, RecType& y);

// 创建顺序表
void Createlist(RecType R[], KeyType keys[], int n);

// 输出顺序表
void DispList(RecType R[], int n);

#endif
