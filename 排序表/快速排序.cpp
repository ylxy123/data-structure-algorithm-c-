#include<stdio.h>
#include"sort_list.h"

// 快速排序(改进版冒泡排序)
/*
快速排序基本思想：
		在待排序的n个元素中任取一个元素（通常为第一个）作为基准
	把该元素放入适当位置后，使得数据序列被划分为两部分。小于在左，
	大于在右。此称为一趟划分（归位）
		之后对划分的两部分分别重复上述过程，直到每部分内元素至多
	一个（递归方式进行）

		一趟快速排序划分partition(R, s, t)采用从两头向中间扫描的方法
	同时交换与基准元素逆序的元素。
		
		每趟快速排序划分仅将一个元素归位
	
*/
// 显示一趟划分的结果
void disppart(RecType R[], int s, int t)
{
	static int i = 1;
	int j;
	printf("第%d次划分：", i);
	for (j = 0; j < s; j++)
		printf("    ");
	for (j = s; j <= t; j++)
		printf("%3d", R[j].key);
	printf("\n");
	i++;
}

// 一趟划分
int partition(RecType R[], int s, int t)
{
	int i = s, j = t;
	RecType tmp = R[i];    // 以R[i]为基准
	while (i < j)   
	{
		while (j > i && R[j].key >= tmp.key)   // 从右向左扫描，找一个小于基准的R[j]
			j--;
		R[i] = R[j];    // 将小于基准的值放入R[i]
		while (j < i && R[i].key <= tmp.key)   // 从左向右扫描，找一个大于基准的R[i]
			i++;
		R[j] = R[i];    // 将大于基准的值放入R[j]
	}
	R[i] = tmp;    // 最后将基准放入R[i]
	disppart(R, s, t);
	return i;    // 返回最终基准下标
}

// 对R[s..t]快速排序
void QuickSort(RecType R[], int s, int t)    
{
	int i = s, j = t;
	if (s < t)    // 区间内至少有两个值
	{
		i = partition(R, s, t);    // 进行一次划分，返回下标
		QuickSort(R, s, i-1);    // 递归快速排序左区间
		QuickSort(R, i + 1, t);    // 递归快速排序右区间
	}
}

int main()
{
	RecType r[MAXL];
	KeyType k[] = { 6,8,7,9,0,1,3,2,4,5 };
	Createlist(r, k, 10);
	DispList(r, 10);
	QuickSort(r, 0, 9);
	DispList(r, 10);

	return 1;
}
