#include<stdio.h>
#include<malloc.h>
#define M 8
#define N 8
#define INF = 32767
#define MAXV 8 

typedef int InfoType;
typedef struct
{
	int no;    // 顶点编号
	InfoType info;     // 顶点的其他类型
}VertexType;    // 顶点的类型

typedef struct
{
	int edges[MAXV][MAXV];
	int n, e;      // 顶点数，边数
	VertexType vexs[MAXV];
}MatGraph;     // 邻接图矩阵信息



int Prim(int v)
{
	int graph[M][N] = {
	{},
	{4,0,5,5,9,100,100,100},
	{3,5,0,5,}
	};

}

int main()
{
	MatGraph* g;
	g->edges[MAXV][MAXV] = {
	{0,4,3,INF,}
	};