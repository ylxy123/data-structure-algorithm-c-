#include"linklist.h"
#include"sqlist.h"
#include<stdio.h>
#include<malloc.h>

int main()
{
	SqList* L;
	ElemType e;
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };

	printf("创建顺序表\n");
	CreateSqlist(L, a, 10);
	DispSqlist(L);
	printf("\n");

	printf("删除线性表中所有值为1的元素\n");
	DelElems1(L, 1);
	DispSqlist(L);
	printf("\n");

	printf("销毁线性表\n");
	DestorySqlist(L);

	printf("\n");

	return 0;
}