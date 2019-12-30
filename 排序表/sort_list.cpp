#include"sort_list.h"

// 交换元素
void Swap(RecType& x, RecType& y)
{
	RecType tmp = x;
	x = y;
	y = tmp;
}

// 创建顺序表
void Createlist(RecType R[], KeyType keys[], int n)
{
	for (int i = 0; i < n; i++)
		R[i].key = keys[i];
}

// 输出顺序表
void DispList(RecType R[], int n)
{
	for (int i = 0; i < n; i++)
		printf("% d ", R[i].key);
	printf("\n");
}




