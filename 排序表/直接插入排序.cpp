#include<stdio.h>
#include"sort_list.h"

// 直接插入排序算法
void InsertSort(RecType R[], int n)
{
	int i, j; RecType tmp;
	for (i = 1; i < n; i++)
	{
		printf(" i = % d,插入 % d,插入结果：", i, R[i].key);
		if (R[i].key < R[i - 1].key)
		{
			tmp = R[i];
			j = i - 1;
			do
			{
				R[j + 1] = R[j];
				j--;
			} while (j >= 0 && R[j].key > tmp.key);
			R[j + 1] = tmp;
		}
		DispList(R, n);
	}
}
int main()
{
	int n = 5;
	KeyType a[] = { 5,4,3,2,1 };
	RecType R[MAXL];
	Createlist(R, a, n);
	printf("排序前：");
	DispList(R, n);
	InsertSort(R, n);
	printf("排序后：");
	DispList(R, n);

	return 1;
}
