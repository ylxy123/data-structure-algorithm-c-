#include<stdio.h>
#include<iostream>
#define MAXL 100
#define MaxElem 20
using namespace std;
typedef int KeyType;    // 关键字
typedef char InfoType;    // 其他数据类型
typedef struct
{
	KeyType key;    // 关键字类型
	InfoType data;
}RecType;    // 查找元素的类型

// 创建顺序表
void CreateList(RecType R[], KeyType keys[], int n)
{
	for (int i = 0; i < n; i++)
		R[i].key = keys[i];
}

// 输出顺序表
void DispList(RecType R[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", R[i].key);
	printf("\n");
}

// 顺序查找（仅有一个匹配）
int SqSearch(RecType R[], int n, KeyType k)
{
	int i = 0;
	R[n].key = k;
	while (R[i].key != k)
		i++;
	if (i == n)
		return 0;
	else
		return i + 1;
}

// 顺序查找（多个匹配）
bool SqSearchElems(RecType R[], int n, KeyType k)
{
    printf("\n待查找元素：%d",k);
	int elems[MaxElem] = { 0 };
	int i = 0,j=0;
	while (i<=n)
	{
		if (R[i].key == k)
		{
			elems[j] = i;
			j++;
		}
		i++;
	}
	if (elems[0] == 0)
		return false;
	else
	{
		printf("\n匹配元素个数：%d\n元素下标：", j);
		for (int m = 0; elems[m] != 0; m++)
			printf("%d ", elems[m]);
		printf("\n");
		return
			true;
	}
}

// 折半查找
int BinarySearch(RecType R[], int n, KeyType k)
{
	int low = 0, high = n-1, mid;
	
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (R[mid].key == k)
			return mid + 1;
		else if (R[mid].key < k)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return 0;    // 查找失败返回0
}

int main()
{
	RecType r[MAXL];
	int n = 10;
	int keys[10] = { 1,4,7,14,25,36,67,98,99,106 };
	CreateList(r, keys, n);
	DispList(r, n);
	SqSearchElems(r, n, 14);
	printf("%d ",BinarySearch(r, n, 36));
	return 0;


}
