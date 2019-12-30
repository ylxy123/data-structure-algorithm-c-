#include<stdio.h>
#include"sort_list.h"

// 冒泡排序基础算法
void BubbleSort(RecType R[], int n)
{
	int i, j,k = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			if (R[j].key < R[j - 1].key)
				Swap(R[j], R[j - 1]);
		}
		printf("第%d趟：",++k); DispList(R, n);
	}
}

// 改进版冒泡排序1(增加bool型变量判断是否结束冒泡)
void BubbleSort1(RecType R[], int n)
{
	int i, j, k = 0;
	bool exchange;
	for (i = 0; i < n - 1; i++)
	{
		exchange = false;
		for (j = n - 1; j > i; j--)
		{
			if (R[j].key < R[j - 1].key)
			{
				Swap(R[j], R[j - 1]);
				exchange = true;
			}
		}
		if (!exchange)
			return;
		printf("第%d趟：", ++k); DispList(R, n);
	}
}

// 改进版冒泡排序2(设置int变量判断是否退出)
void BubbleSort2(RecType R[], int n)
{
	int i, j, k = 0, exchange;
	for (int i = 1; i < n - 1; i++)
	{
		for (exchange = 0, j = 0; j < n - i; j++)
		{
			if (R[j].key > R[j + 1].key)
			{
				Swap(R[j], R[j + 1]);
				exchange = 1;
			}
		}
		if (exchange == 0) return;
		printf("第%d趟：", ++k); DispList(R, n);
	}
}

int main()
{
	RecType r[MAXL];
	KeyType k[] = { 7,8,9,6,5,0,1,2,3,4 };
	Createlist(r, k, 10);
	DispList(r, 10);
	BubbleSort2(r, 10);
	DispList(r, 10);
	return 0;
}
