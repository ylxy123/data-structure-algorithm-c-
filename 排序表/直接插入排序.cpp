#include<stdio.h>
#include"sort_list.h"

// ֱ�Ӳ��������㷨
void InsertSort(RecType R[], int n)
{
	int i, j; RecType tmp;
	for (i = 1; i < n; i++)
	{
		printf(" i = % d,���� % d,��������", i, R[i].key);
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
	printf("����ǰ��");
	DispList(R, n);
	InsertSort(R, n);
	printf("�����");
	DispList(R, n);

	return 1;
}
