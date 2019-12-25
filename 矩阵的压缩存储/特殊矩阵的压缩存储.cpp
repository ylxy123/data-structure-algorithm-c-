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

// 返回长度
int LengthMin(MinMatrix* a)
{
	printf("\nLength: %d \n", a->length);
	return a->length;
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
	a->length = k--;  
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
int U[M][N] = {
	{1,2,3,4,5},
	{8,5,4,3,2},
	{8,8,3,4,1},
	{8,8,8,2,5},
	{8,8,8,8,8}
};

// 判断为上三角矩阵
bool isUpperTriMatrix(ElemType U[M][N])
{
	if (M != N)    // 若非方阵，返回false
		return false;
	for (int i = M-1; i > 0; i--)
	{
		for (int j = i-1; j >= 0; j--)
		{
			if (U[i][j] != U[1][0])    // 以U[1][0]为参照，不相等返回false
				return false;
		}
	}
	return true;
}

// 上三角矩阵的压缩存储
bool MinUpperTriMatrix(ElemType U[M][N], MinMatrix*& a)
{
	if (!isUpperTriMatrix(U))
		return false;
	int k = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = i; j < N; j++)
		{
			a->data[k] = U[i][j];
			k++;
		}
	}
	a->data[k] = U[1][0];
	k++;
	a->length = k;
	a->tag = 'U';
	return true;
}

// 上三角矩阵解压缩
bool UnzipUpperTMatrix(MinMatrix* u, ElemType d[M][N])
{
	if (u->tag != 'U' || u->length <= 0)
		return false;
	int c = u->data[u->length-1];
	int p = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = i; j < N; j++)
		{
			d[i][j] = u->data[p];
			p++;
		}
	}
	if (c != 0)
	{
		for (int m = M - 1; m > 0; m--)
		{
			for (int n = m - 1; n >= 0; n--)
			{
				d[m][n] = c;
			}
		}
	}
	return true;
}

int main()
{
	MinMatrix* a, * u;
	int loc1;
	ElemType b[M][N] = { 0 };
	InitMinMatrix(a);
	SymMatrixMin(A, a);
	printf("\n/*----------对称矩阵A----------*/\n");
	DispMatrix(A);
	printf("\n/*--------判断A是否对称--------*/\n");
	if (isSymMatrix(A))
		printf("A是对称矩阵\n");
	else
		printf("A不是对称矩阵\n");
	printf("\n/*-----对称矩阵A的压缩存储-----*/\n");
	for (int i = 0; i < a->length; i++)
		printf("%d ", a->data[i]);
	printf("\n");
	LengthMin(a);
	printf("\n/*-------对称矩阵A解压缩-------*/\n");
	if (UnzipSym(a, b))
		DispMatrix(b);
	printf("\n/*--------下标对应关系---------*/\n");
	LocInArray(3, 4, loc1);
	printf("i:%d  j:%d  loc:%d ", 3, 4, loc1);
	printf("\n");
	
	DestoryMinMatrix(a);

	printf("\n/*----------上三角矩阵U---------*/\n");
	ElemType d[M][N] = { 0 };
	DispMatrix(U);
	printf("\n/*-----判断U是否为上三角矩阵----*/\n");
	if (isUpperTriMatrix(U))
		printf("U是上三角矩阵\n");
	else
		printf("U不是上三角矩阵\n");
	printf("\n/*-----上三角矩阵U的压缩存储-----*/\n");
	InitMinMatrix(u);
	MinUpperTriMatrix(U, u);
	for (int i = 0; i < u->length; i++)
		printf("%d ", u->data[i]);
	printf("\n");
	LengthMin(u);
	printf("\n/*-------上三角矩阵U解压缩-------*/\n");
	if (UnzipUpperTMatrix(u, d))
		DispMatrix(d);

	
	DestoryMinMatrix(u);









	return 0;
}