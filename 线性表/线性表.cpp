#define MaxSize 50
#include<malloc.h>
#include<stdio.h>

typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;

// 根据a数组中n个元素创建线性表
void CreateSqlist(SqList *&L, ElemType a[], int n)   // L是输出型参数，因此调用时应当加上& 
{
	int k = 0;
	L = (SqList * )malloc(sizeof(SqList));
	for (int i = 0; i < n; i++)
	{
		L->data[k] = a[i];
		k++;
	}
	L->length = k;
}

// 初始化线性表
void InitSqlist(SqList *&L)
{
	L = (SqList * )malloc(sizeof(SqList));
	L->length = 0;
}

// 销毁线性表   
void DestorySqlist(SqList *&L)   // 当通过malloc分配空间后，应调用free()释放内存
{
	free(L);
}

// 判断线性表是否为空
bool ListEmpty(SqList *&L) 
{
	return(L->length == 0);
}

// 输出线性表
void DispSqlist(SqList* L)
{
	for (int i = 0; i < L->length; i++)
	{
		printf("%c ", L->data[i]);
	}
}

// 用引用型参数e返回L中第i个值，若i非法，返回false；否则返回true
bool GetElem(SqList* L, int i, ElemType e)
{
	if (i <= 0 || i - 1 > L->length)
		return false;
	e = L->data[i];
	return true;
}

// 按元素值查找第一个与e相等的元素的逻辑序号（下标+1），若元素不存在，返回0
int LocElem(SqList* L, ElemType e)
{
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] == e)
			return i+1;
		else
			return 0;
	}
}

// 在线性表中第i个位置插入新元素e，若i非法，返回false
bool InsertElem(SqList* L, int i, ElemType e)
{
	if (i <= 0 || i - 1 > L->length)
		return false;
	i--;      // 将逻辑序号i转化为物理序号（下标）
	for (int p = L->length; p > i; p--)
	{
		L->data[p] = L->data[p - 1];
	}
	L->data[i] = e;
	L->length++;
	return true;
}

// 删除线性表第i个位置的元素，若i非法，返回false
bool DeleteElem(SqList* &L, int i)
{
	if (i <= 0 || i - 1 > L->length)
		return false;
	for (int j = i; j < L->length; j++)
	{
		L->data[j - 1] = L->data[j];
	}
	L->length--;
}

// 删除线性表中所有值为x的元素，该算法时间复杂度为O(n)，空间复杂度为O(1)
void DelElems1(SqList*& L, ElemType x)
{
	int k = 0;
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] != x)
		{
			L->data[k] = L->data[i];
			k++;
		}
	}
	L->length = k;
}

// 同上的第二种算法
void DelElems2(SqList *&L, ElemType x)
{
	int k = 0;
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] == x)
			k++;
		else
			L->data[i - k] = L->data[i];
	}
	L->length -= k;
}

// 交换元素
void Swap(char**a, char**b)
{
	char *tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}



int main()
{
	SqList *L;
	ElemType e;
	int a[10] = { 1,2,3,4,5,6,7,8,9,10};
	
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
