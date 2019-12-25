#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
#define M 5
#define N 5
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;    // 长度
	char tag;      // 矩阵类型
}MinMatrix;    // 压缩矩阵类型

// 压缩矩阵类型初始化
void InitMinMatrix(MinMatrix *&a)
{
	a = (MinMatrix*)malloc(sizeof(MinMatrix));
	a->length = 0;
	a->tag = ' ';
}

// 销毁
void DestoryMinMatrix(MinMatrix*& a)
{
	free(a);
}

// 输出矩阵
void DispMatrix(ElemType A[M][N])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}

/*---------------------对称矩阵的压缩存储------------------------*/

// 对称矩阵
ElemType A[M][N] = {
	{1,2,3,4,5},
	{2,4,3,1,3},
	{3,3,3,2,4},
	{4,1,2,2,1},
	{5,3,4,1,5}
};
// 判断是否为对称矩阵
bool isSymMatrix(ElemType A[M][N])
{
	if (M != N)
		return false;    // 若非方阵，返回false
	int k;
	for (int i = 0; i < M; i++)
	{
		k = 0;
		for (int j = 0; j < N; j++)
		{
			if (A[i][j] != A[k][i])
				return false;    // 若aij != aji，返回false 
			k++;
		}
	}
	return true;    // 全等，返回true
}

// 对称矩阵压缩算法
bool SymMatrixMin(ElemType A[M][N], MinMatrix *&a)
{
	if (!isSymMatrix(A))
		return false;
	int k = 0;    // 长度计数
	for (int i = 0; i < M; i++)
	{
		for (int j = i; j < N; j++)
		{
			a->data[k] = A[i][j];
			k++;
		}
	}
	a->length = k;  
	a->tag = 'S';    // 对称矩阵的标签
	return true;
}

// 压缩矩阵还原对称矩阵
bool UnzipSym(MinMatrix* a, ElemType b[M][N])
{
	if (a->tag != 'S' || a->length <= 0)
		return false;
	int k,p = 0;
	for (int i = 0; i < M; i++)
	{
		k = i;
		for (int j = i; j < N; j++)
		{
			b[i][j] = b[k][i] = a->data[p];
			p++; k++;
		}
	}
	return true;
}

// 根据一组下标返回该元素值在压缩一维数组中的下标
int LocInArray(int i, int j, int& loc)
{
	if (i<0 || j<0 || i>M || j>N)    // 非法返回0
		return 0;
	if (i >= j)
		loc = i * (i + 1) / 2 + j;
	else
		loc = j * (j + 1) / 2 + i;
	return loc;
}
/*-------------------上、下三角矩阵的压缩存储----------------------*/

// 上三角矩阵



int main()
{
	MinMatrix *a;
	int loc;
	ElemType b[M][N] = { 0 };
	InitMinMatrix(a);
	SymMatrixMin(A, a);
	printf("\n/*----------对称矩阵A----------*/\n");
	DispMatrix(A);
	printf("\n/*-----对称矩阵A的压缩存储-----*/\n");
	for (int i = 0; i < a->length; i++)
		printf("%d ", a->data[i]);
	printf("\n");
	printf("\n/*-------对称矩阵A解压缩-------*/\n");
	if (UnzipSym(a, b))
		DispMatrix(b);
	printf("\n/*--------下标对应关系---------*/\n");
	LocInArray(3, 4, loc);
	printf("i:%d  j:%d  loc:%d ", 3, 4, loc);
	printf("\n");
	DestoryMinMatrix(a);
	return 0;
}