#include"linklist.h"
#include"sqlist.h"
#include<stdio.h>
#include<malloc.h>

int main()
{
	SqList* L;
	ElemType e;
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };

	printf("����˳���\n");
	CreateSqlist(L, a, 10);
	DispSqlist(L);
	printf("\n");

	printf("ɾ�����Ա�������ֵΪ1��Ԫ��\n");
	DelElems1(L, 1);
	DispSqlist(L);
	printf("\n");

	printf("�������Ա�\n");
	DestorySqlist(L);

	printf("\n");

	return 0;
}