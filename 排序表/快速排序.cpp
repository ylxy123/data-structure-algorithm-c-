#include<stdio.h>
#include"sort_list.h"

// ��������(�Ľ���ð������)
/*
�����������˼�룺
		�ڴ������n��Ԫ������ȡһ��Ԫ�أ�ͨ��Ϊ��һ������Ϊ��׼
	�Ѹ�Ԫ�ط����ʵ�λ�ú�ʹ���������б�����Ϊ�����֡�С������
	�������ҡ��˳�Ϊһ�˻��֣���λ��
		֮��Ի��ֵ������ֱַ��ظ��������̣�ֱ��ÿ������Ԫ������
	һ�����ݹ鷽ʽ���У�

		һ�˿������򻮷�partition(R, s, t)���ô���ͷ���м�ɨ��ķ���
	ͬʱ�������׼Ԫ�������Ԫ�ء�
		
		ÿ�˿������򻮷ֽ���һ��Ԫ�ع�λ
	
*/
// ��ʾһ�˻��ֵĽ��
void disppart(RecType R[], int s, int t)
{
	static int i = 1;
	int j;
	printf("��%d�λ��֣�", i);
	for (j = 0; j < s; j++)
		printf("    ");
	for (j = s; j <= t; j++)
		printf("%3d", R[j].key);
	printf("\n");
	i++;
}

// һ�˻���
int partition(RecType R[], int s, int t)
{
	int i = s, j = t;
	RecType tmp = R[i];    // ��R[i]Ϊ��׼
	while (i < j)   
	{
		while (j > i && R[j].key >= tmp.key)   // ��������ɨ�裬��һ��С�ڻ�׼��R[j]
			j--;
		R[i] = R[j];    // ��С�ڻ�׼��ֵ����R[i]
		while (j < i && R[i].key <= tmp.key)   // ��������ɨ�裬��һ�����ڻ�׼��R[i]
			i++;
		R[j] = R[i];    // �����ڻ�׼��ֵ����R[j]
	}
	R[i] = tmp;    // ��󽫻�׼����R[i]
	disppart(R, s, t);
	return i;    // �������ջ�׼�±�
}

// ��R[s..t]��������
void QuickSort(RecType R[], int s, int t)    
{
	int i = s, j = t;
	if (s < t)    // ����������������ֵ
	{
		i = partition(R, s, t);    // ����һ�λ��֣������±�
		QuickSort(R, s, i-1);    // �ݹ��������������
		QuickSort(R, i + 1, t);    // �ݹ��������������
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
