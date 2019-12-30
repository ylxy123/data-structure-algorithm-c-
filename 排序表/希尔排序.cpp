#include<stdio.h>
#include"sort_list.h"

// ϣ�������㷨
void ShellSort(RecType R[], int n)
{
	int j,d = n/2,k = 1;
	RecType tmp;
	while (d > 0)
	{
		for (int i = d; i < n; i++)  // �Ը���ֱ�Ӳ�������
		{
			tmp = R[i];
			j = i - d;
			while (j >= 0 && tmp.key < R[j].key)
			{
				R[j + d] = R[j];
				j -= d;
			}
			R[j + d] = tmp;
		}
		printf("��%d��--dΪ%d:  ", k++,d);
		DispList(R, n);
		d = d / 2;
	}
}

int main()
{
	RecType r[MAXL];
	KeyType k[] = { 9,8,7,6,5,4,3,2,1,0 };
	int n = 10;
	
	Createlist(r, k, n);
	DispList(r, n);
	ShellSort(r, n);
	DispList(r, n);

	return 0;
}