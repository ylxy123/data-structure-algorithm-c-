#include<stdio.h>
#include"sort_list.h"

// ð����������㷨
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
		printf("��%d�ˣ�",++k); DispList(R, n);
	}
}

// �Ľ���ð������1(����bool�ͱ����ж��Ƿ����ð��)
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
		printf("��%d�ˣ�", ++k); DispList(R, n);
	}
}

// �Ľ���ð������2(����int�����ж��Ƿ��˳�)
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
		printf("��%d�ˣ�", ++k); DispList(R, n);
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
