#ifndef GRAPH_H
#define GRAPH_H
#define MAXV 5
#define INF 32767
typedef int InfoType;
/*----------------���ڽӾ����------------------*/
typedef struct
{
	int No;    // ������
	InfoType info;    // �����������Ϣ
}VertexType;   // ���������
typedef struct
{
	int edges[MAXV][MAXV];    // �ڽӾ�������
	int n;    // ������
	int e;    // ����
	VertexType vexs[MAXV];    // ������Ϣ
}MatGraph;    // �ڽӾ�������

/*----------------���ڽӱ��------------------*/





#endif
