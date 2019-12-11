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


// 直接插入排序
/*
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
*/

// 折半插入排序
void BinInsertSort(RecType R[], int n)
{

}