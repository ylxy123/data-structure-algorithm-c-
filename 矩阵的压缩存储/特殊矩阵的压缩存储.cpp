#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
#define M 5
#define N 5
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;    // ����
	char tag;      // ��������
}MinMatrix;    // ѹ����������

// ѹ���������ͳ�ʼ��
void InitMinMatrix(MinMatrix *&a)
{
	a = (MinMatrix*)malloc(sizeof(MinMatrix));
	a->length = 0;
	a->tag = ' ';
}

// ����
void DestoryMinMatrix(MinMatrix*& a)
{
	free(a);
}

// �������
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

/*---------------------�Գƾ����ѹ���洢------------------------*/

// �Գƾ���
ElemType A[M][N] = {
	{1,2,3,4,5},
	{2,4,3,1,3},
	{3,3,3,2,4},
	{4,1,2,2,1},
	{5,3,4,1,5}
};
// �ж��Ƿ�Ϊ�Գƾ���
bool isSymMatrix(ElemType A[M][N])
{
	if (M != N)
		return false;    // ���Ƿ��󣬷���false
	int k;
	for (int i = 0; i < M; i++)
	{
		k = 0;
		for (int j = 0; j < N; j++)
		{
			if (A[i][j] != A[k][i])
				return false;    // ��aij != aji������false 
			k++;
		}
	}
	return true;    // ȫ�ȣ�����true
}

// �Գƾ���ѹ���㷨
bool SymMatrixMin(ElemType A[M][N], MinMatrix *&a)
{
	if (!isSymMatrix(A))
		return false;
	int k = 0;    // ���ȼ���
	for (int i = 0; i < M; i++)
	{
		for (int j = i; j < N; j++)
		{
			a->data[k] = A[i][j];
			k++;
		}
	}
	a->length = k;  
	a->tag = 'S';    // �Գƾ���ı�ǩ
	return true;
}

// ѹ������ԭ�Գƾ���
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

// ����һ���±귵�ظ�Ԫ��ֵ��ѹ��һά�����е��±�
int LocInArray(int i, int j, int& loc)
{
	if (i<0 || j<0 || i>M || j>N)    // �Ƿ�����0
		return 0;
	if (i >= j)
		loc = i * (i + 1) / 2 + j;
	else
		loc = j * (j + 1) / 2 + i;
	return loc;
}
/*-------------------�ϡ������Ǿ����ѹ���洢----------------------*/

// �����Ǿ���



int main()
{
	MinMatrix *a;
	int loc;
	ElemType b[M][N] = { 0 };
	InitMinMatrix(a);
	SymMatrixMin(A, a);
	printf("\n/*----------�Գƾ���A----------*/\n");
	DispMatrix(A);
	printf("\n/*-----�Գƾ���A��ѹ���洢-----*/\n");
	for (int i = 0; i < a->length; i++)
		printf("%d ", a->data[i]);
	printf("\n");
	printf("\n/*-------�Գƾ���A��ѹ��-------*/\n");
	if (UnzipSym(a, b))
		DispMatrix(b);
	printf("\n/*--------�±��Ӧ��ϵ---------*/\n");
	LocInArray(3, 4, loc);
	printf("i:%d  j:%d  loc:%d ", 3, 4, loc);
	printf("\n");
	DestoryMinMatrix(a);
	return 0;
}