#include<stdio.h>
#include<malloc.h>
#define INF 32767
#define MAXV 10
/*-------------------------------------------*/
typedef char InfoType;
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

/*--------------------------------------------*/

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
	G = (AdjGraph * )malloc(sizeof(AdjGraph));
	for (int i = 0; i < n;i++)
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
			printf("% 2d[%d]", p->adjvex,p->weight);
			p = p->nextarc;
		}
		printf("^\n");
	}
}

// 销毁邻接表
void DestoryAdj(AdjGraph* &G)
{
	ArcNode* pre,*p;
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



int main()
{
	MatGraph g;
	AdjGraph* G;
	int graph[MAXV][MAXV] = {
	{0,5,INF,7,INF,INF},
	{INF,0,4,INF,INF,INF},
	{8,INF,0,INF,INF,9},
	{INF,INF,5,0,INF,6},
	{INF,INF,INF,5,0,INF},
	{3,INF,INF,INF,1,0} };
	int n = 6,e = 10;
	CreateMat(g,graph, n, e);
	printf("/*----图的邻接矩阵----*/\n");
	DispMat(g);
	CreateAdj(G, graph, n, e);
	printf("/*----图的邻接表----*/\n");
	DispAdj(G);
	DestoryAdj(G);

	return 0;
}