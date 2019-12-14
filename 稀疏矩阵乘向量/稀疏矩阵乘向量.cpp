#include<stdio.h>
#define M 6
#define N 7
#define MAXV 10

typedef char ElemType;
typedef struct
{
	int i;   // ��
	int j;   // ��
	ElemType data;   // Ԫ��ֵ 
}TriNode;   // ��Ԫ��
typedef struct
{
	int rows;   // ��������
	int cols;   // ��������
	int nums;   // ��Ԫ�ظ���
	TriNode data[MAXV];   
}TSMatrix;  // ��Ԫ��˳���

// ��ϡ������д�����Ԫ��˳���
void CreateTSMatrix(TSMatrix& t, ElemType m[M][N])
{
	t.rows = t.nums = t.cols = 0;
	int i, j;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (m[i][j] != 0)
			{
				t.data[t.nums].i = i;
				t.data[t.nums].j = j;
				t.data[t.nums].data = m[i][j];
				t.nums++;
			}
		}
	}
}

// �����Ԫ��
void DispTSMatrix(TSMatrix t)
{
	for (int m = 0; m < 3 * M; m++)
		printf("-");
	printf("\n  ����Ԫ���\n");
	for (int i = 0; i < t.nums; i++)
		printf("(% 3d, % 3d, % 3d)\n", t.data[i].i, t.data[i].j, t.data[i].data);
}

// �������
void DispMatrix(ElemType m[M][N])
{
	printf("\n");
	for (int m = 0; m < 4 * M; m++)
		printf("-");
	printf("\n       �������\n");
	for (int j = 0; j < M; j++)
	{
		printf("\n{");
		for (int k = 0; k < N; k++)
			printf(" %d ", m[j][k]);
		printf("}\n");
	}
}

// ����Ԫ���лָ�ϡ�����(��ά������ʽ)
void RecoverMatrix(TSMatrix t,ElemType m[M][N]) 
{
	for (int i = 0; i < t.nums; i++)
	{
		m[t.data[i].i][t.data[i].j] = t.data[i].data;
	}
	DispMatrix(m);
}

// ϡ����������
void Matrix_M_Array(TSMatrix t, ElemType m[N])
{
	int i;
	ElemType answer[M] = { 0 };    // �������
	int s;    
	for (i = 0; i < M; i++)
	{
		s = 0;
		for (int j = i; j < t.nums; j++)
		{
			if (i == t.data[j].i)
				s += t.data[j].data * m[i];
		}
		answer[i] = s;
	}
	// ����������
	printf("\n\n");
	for (int m = 0; m < 4 * M; m++)
		printf("-");
	printf("\n   ��Answer��\n");    
	for (int k = 0; k < M; k++)    
		printf("%d ", answer[k]);
	printf("\n");
}

int main()
{
	ElemType A[M][N] = {
		{0,0,1,0,0,0,0},
		{0,2,0,0,0,0,0},
		{3,0,0,0,0,0,0},
		{0,0,0,5,0,0,0},
		{0,0,0,0,6,0,0},
		{0,0,0,0,0,7,4}
	};
	ElemType a[M][N] = { 0 };
	ElemType m[N];
	for (int k = 0; k < N; k++)
		m[k] = k + 1;
	TSMatrix t;
	CreateTSMatrix(t, A);
	DispTSMatrix(t);
	RecoverMatrix(t, a);
	printf("\n\n");
	for (int m = 0; m < 4 * M; m++)
		printf("-");
	printf("\n   ������������\n");
	for (int k = 0; k < N; k++)
		printf("%d ", m[k]);
	printf("\n");
	Matrix_M_Array(t, m);
	
	return 0;
}