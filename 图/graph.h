#ifndef GRAPH_H
#define GRAPH_H
#define MAXV 5
#define INF 32767
typedef int InfoType;
/*----------------↓邻接矩阵↓------------------*/
typedef struct
{
	int No;    // 顶点编号
	InfoType info;    // 顶点的其他信息
}VertexType;   // 顶点的类型
typedef struct
{
	int edges[MAXV][MAXV];    // 邻接矩阵数组
	int n;    // 顶点数
	int e;    // 边数
	VertexType vexs[MAXV];    // 顶点信息
}MatGraph;    // 邻接矩阵类型

/*----------------↓邻接表↓------------------*/





#endif
