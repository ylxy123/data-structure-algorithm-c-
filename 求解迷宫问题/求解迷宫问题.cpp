#include<stdio.h>
#include<malloc.h>
#define MaxSize 64
#define M 8
#define N 8


int mg[M + 2][N + 2] =
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1},
};
typedef struct
{
	int i;    // 方块的行号
	int j;    // 方块的列号
	int di;    // 方块的下一个可走的方向
}Box;     // 方块类型

// 方位设置：上下左右依次为0,1,2,3

typedef struct
{
	Box data[MaxSize];
	int top;
}StType;  // 顺序栈

//  栈的初始化
void InitStack(StType*& s) 
{
	s = (StType*)malloc(sizeof(StType));
	s->top = -1;
}

// 销毁栈
void DestoryStack(StType*& s)
{
	free(s);
}

// 进栈
bool Push(StType*& s, Box e)
{
	if (s->top == MaxSize - 1)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

// 退栈
bool Pop(StType*& s, Box &e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}

// 取栈顶元素
bool GetTop(StType* s, Box &e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	return true;
}

// 栈是否为空
bool IsStackEmpty(StType* s)
{
	return (s->top == -1);
}

// 迷宫求解算法
bool FindPath(int xi, int yi, int xe, int ye)
{
	
	Box path[MaxSize], e;
	bool find;
	StType* st;
	InitStack(st);
	e.i = xi; e.j = yi; e.di = -1;
	Push(st, e);
	mg[xi][yi] = -1;
	int i,j,di,k,i1,j1;
	while (!IsStackEmpty(st))
	{
		GetTop(st, e);      // 取栈顶元素
		i = e.i; j = e.j; di = e.di;
		if (i == xe && j == ye)    // 如果栈顶方块为出口，输出路径
		{
			printf("该迷宫的一条路径为：\n");
			k = 0;
			while (!IsStackEmpty(st))   // 将栈中方块存入path[]
			{
				Pop(st, e);
				path[k] = e;
				k++;
			}
			while (k >= 1)      // 输出path[]
			{
				k--;
				printf("\t(%d,%d)%d", path[k].i, path[k].j, path[k].di);
				if ((k+2) % 5 == 0)
					printf("\n");
			}
			printf("\n");
			DestoryStack(st);
			return true;
		}
		find = false;
		while (di < 4 && !find)
		{
			di++;
			switch (di)
			{
				case 0:i1 = i - 1, j1 = j; break;
				case 1:i1 = i, j1 = j + 1; break;
				case 2:i1 = i + 1, j1 = j; break;
				case 3:i1 = i, j1 = j - 1; break;
			}
			if (mg[i1][j1] == 0)     // 找到了一个相邻可走的方块，设置find为true
				find = true;
		}
		if (find)
		{
			st->data[st->top].di = di;
			e.i = i; e.j = j; e.di = -1;
			Push(st, e);
			mg[i1][j1] = -1;
		}
		else
		{
			Pop(st, e);
			mg[e.i][e.j] = 0;
		}
	}
	DestoryStack(st);
	return false;
}


int main()
{
	if (!FindPath(1, 1, M, N))
		printf("该迷宫无解！");
	return 1;
}