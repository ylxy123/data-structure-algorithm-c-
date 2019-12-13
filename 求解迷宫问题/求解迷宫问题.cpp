#include<stdio.h>
#define MaxSize 100
#define M 4
#define N 4

// 迷宫图
int mg[M + 2][N + 2] =
{
	{1,1,1,1,1,1},
	{1,0,0,0,1,1},
	{1,0,1,0,0,1},
	{1,0,0,0,1,1},
	{1,1,0,0,0,1},
	{1,1,1,1,1,1}
};

struct
{
	int i;    // 方块的行号
	int j;    // 方块的列号
	int di;    // 方块的下一个可走的方向
}St[MaxSize], Path[MaxSize];     // 方块类型

int top = -1;    // 栈顶指针
int count = 1;    // 路径数计数
int minlen = MaxSize;    // 最短路径长度

// 方位设置：上下左右依次为0,1,2,3

// 输出一条路径
void Disp_one_path()
{
	int k;
	printf("% 5d: ", count++);
	for (k = 0; k <= top; k++)
		printf("(%d, %d) ", St[k].i, St[k].j);
	printf("\n");
	if (top + 1 < minlen)
	{
		for (k = 0; k <= top; k++)
			Path[k] = St[k];
		minlen = top + 1;
	}
}

// 输出第一天最短路径
void Disp_min_path()
{
	printf("最短路径如下：\n");
	printf("长度: %d\n", minlen);
	printf("路径: ");
	for (int k = 0; k < minlen; k++)
		printf("(%d ,%d)", Path[k].i,Path[k].j);
	printf("\n");
}

// 迷宫求解算法
void FindPath(int xi, int yi, int xe, int ye)
{
	int i, j, i1, j1, di;
	bool find;
	top++;
	St[top].i = xi;
	St[top].j = yi;
	St[top].di = -1;
	mg[xi][yi] = -1;
	while (top > -1)
	{
		i = St[top].i; j = St[top].j;
		di = St[top].di;
		if (i == xe && j == ye)
		{
			Disp_one_path();
			mg[i][j] = 0;
			top--;
			i = St[top].i; j = St[top].j;
			di = St[top].di;
		}
		find = false;
		while (di < 4 && !find)
		{
			di++;
			switch (di)
			{
			case 0:i1 = i - 1; j1 = j; break;
			case 1:i1 = i; j1 = j + 1; break;
			case 2:i1 = i + 1; j1 = j; break;
			case 3:i1 = i; j1 = j - 1; break;
			}
			if (mg[i][j] == 0) find = true;
		}
		if (find)
		{
			St[top].di = di;
			top++; St[top].i = i1; St[top].j = j1;
			St[top].di = -1;
			mg[i1][j1] = -1;
		}
		else
		{
			mg[i][j] = 0;
			top--;
		}
	}
	Disp_min_path();
}


int main()
{
	printf("该迷宫所有路径如下：\n");
	FindPath(1, 1, M, N);
	return 1;
}