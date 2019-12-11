#include<stdio.h>
#include<malloc.h>
#define INF 32767
#define MAXV 10
#define MAX 10

typedef char InfoType;
typedef struct ANode
{
	int adjvex;    // 该边的邻接点编号
	struct ANode* nextarc;     // 后继指针
	int weight;    // 该边的权值
}ArcNode;    // 边结点类型

typedef struct
{
	InfoType info;     // 顶点的其他信息
	ArcNode* firstarc;    // 边首结点
}VNode;     // 头结点类型

typedef struct
{
	int no;    // 顶点编号
	InfoType info;     // 顶点其他信息
}VertexType;    // 顶点类型
typedef struct
{
	int edge[MAXV][MAXV];    // 邻接矩阵
	int n;    // 顶点个数
	int e;    // 边数
}MatGraph;     // 完整的图邻接矩阵类型

typedef struct
{
	VNode adjlist[MAXV];    // 邻接表的头结点数组
	int n;      // 顶点个数
	int e;      // 边数
}AdjGraph;  // 完整的图邻接表类型

//-------------------邻接矩阵的基本运算算法----------------------//

// 创建图的邻接矩阵
void CreateMat(MatGraph& g, int A[MAXV][MAXV], int n, int e)
{
	g.n = n; g.e = e;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			g.edge[i][j] = A[i][j];
		}
	}
}

// 输出邻接矩阵
void DispMat(MatGraph g)
{
	printf("graph=\n");
	for (int i = 0; i < g.n; i++)
	{
		for (int j = 0; j < g.n; j++)
		{
			if (g.edge[i][j] != INF)
				printf("%4d", g.edge[i][j]);
			else
				printf("% 4s", "∞");
		}
		printf("\n");
	}
}

//-------------------邻接表的基本运算算法----------------------//

//创建邻接表
void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV], int n, int e)
{
	ArcNode* p;
	G = (AdjGraph*)malloc(sizeof(AdjGraph));
	for (int i = 0; i < n; i++)
		G->adjlist[i].firstarc = NULL;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A[i][j] != 0 && A[i][j] != INF)
			{
				p = (ArcNode*)malloc(sizeof(ArcNode));
				p->weight = A[i][j];
				p->adjvex = j;
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
		}
	}
	G->n = n; G->e = e;
}

// 输出邻接表
void DispAdj(AdjGraph* G)
{
	ArcNode* p;
	for (int i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].firstarc;
		printf("%4d → ", i);
		while (p != NULL)
		{
			printf("% 2d[%d]", p->adjvex, p->weight);
			p = p->nextarc;
		}
		printf("^\n");
	}
}

// 销毁邻接表
void DestoryAdj(AdjGraph*& G)
{
	ArcNode* pre, * p;
	for (int i = 0; i < G->n; i++)
	{
		pre = G->adjlist[i].firstarc;
		if (pre != NULL)
		{
			p = pre->nextarc;
			while (p != NULL)
			{
				free(pre);
				pre = p;
				p = p->nextarc;
			}
			free(p);
		}
	}
	free(G);
}

// 深度优先遍历邻接表
int visited[MAX] = { 0 };    // 全局已访问数组
void DFSAdj(AdjGraph* G, int v)
{
	ArcNode* p;
	visited[v] = 1;    // 置已访问标记
	printf("%d ", v);     // 输出已访问编号
	p = G->adjlist[v].firstarc;    // p指向第一个邻接点
	while (p != NULL)
	{
		if (visited[p->adjvex] == 0)    // 若未被访问
			DFSAdj(G, p->adjvex);
		p = p->nextarc;
	}
}

// 深度优先遍历邻接矩阵
void DFSMat(MatGraph g,int v)
{
	int i = v;
	visited[v] = 1;
	printf("%d ",v);
	for (int j = 0; j < g.n; j++)
	{
		if (visited[j] == 0 && g.edge[i][j] != 0 && g.edge[i][j] != INF)
			DFSMat(g, j);
	}
}

int main()
{
	AdjGraph* G;
	int graph[MAXV] [MAXV] = {
	{0,8,INF,5,INF},
	{INF,0,3,INF,INF},
	{INF,INF,0,INF,6},
	{INF,INF,9,0,INF},
	{INF,INF,INF,INF,0} };
	int n = 5,e = 5;
	CreateAdj(G, graph, n, e);
	DispAdj(G);
	printf("\n\n");
	DFSAdj(G, 0);
	DestoryAdj(G);

	MatGraph g;
	CreateMat(g, graph, n, e);
	printf("\n\n");
	DispMat(g);
	DFSMat(g,0);

	return 0;
}