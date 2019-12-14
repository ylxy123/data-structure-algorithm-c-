#include<stdio.h>
#define M 6
#define N 7
#define MAXV 10

typedef char ElemType;
typedef struct
{
	int i;   // 行
	int j;   // 列
	ElemType data;   // 元素值 
}TriNode;   // 三元组
typedef struct
{
	int rows;   // 矩阵行数
	int cols;   // 矩阵列数
	int nums;   // 总元素个数
	TriNode data[MAXV];   
}TSMatrix;  // 三元组顺序表

// 从稀疏矩阵中创建三元组顺序表
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

// 输出三元组
void DispTSMatrix(TSMatrix t)
{
	for (int m = 0; m < 3 * M; m++)
		printf("-");
	printf("\n  ↓三元组↓\n");
	for (int i = 0; i < t.nums; i++)
		printf("(% 3d, % 3d, % 3d)\n", t.data[i].i, t.data[i].j, t.data[i].data);
}

// 输出矩阵
void DispMatrix(ElemType m[M][N])
{
	printf("\n");
	for (int m = 0; m < 4 * M; m++)
		printf("-");
	printf("\n       ↓矩阵↓\n");
	for (int j = 0; j < M; j++)
	{
		printf("\n{");
		for (int k = 0; k < N; k++)
			printf(" %d ", m[j][k]);
		printf("}\n");
	}
}

// 从三元组中恢复稀疏矩阵(二维数组形式)
void RecoverMatrix(TSMatrix t,ElemType m[M][N]) 
{
	for (int i = 0; i < t.nums; i++)
	{
		m[t.data[i].i][t.data[i].j] = t.data[i].data;
	}
	DispMatrix(m);
}

// 稀疏矩阵乘向量
void Matrix_M_Array(TSMatrix t, ElemType m[N])
{
	int i;
	ElemType answer[M] = { 0 };    // 结果数组
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
	// 输出结果数组
	printf("\n\n");
	for (int m = 0; m < 4 * M; m++)
		printf("-");
	printf("\n   ↓Answer↓\n");    
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
	printf("\n   ↓待乘向量↓\n");
	for (int k = 0; k < N; k++)
		printf("%d ", m[k]);
	printf("\n");
	Matrix_M_Array(t, m);
	
	return 0;
}