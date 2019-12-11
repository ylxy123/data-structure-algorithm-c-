#include<stdio.h>
#include<malloc.h>
#define M 6
#define N 6
#define INF 32767






void Dijkstra(int startIndex,int path[],int cost[])
{
	int graph[M][N] = {

	{0,5,INF,7,INF,INF},
	{INF,0,4,INF,INF,INF},
	{8,INF,0,INF,INF,9},
	{INF,INF,5,0,INF,6},
	{INF,INF,INF,5,0,INF},
	{3,INF,INF,INF,1,0}

	};
	int lenth = M;
	int v[M] = { 0 };
	// 初始化
	for (int i = 0; i < M; i++)
	{
		if (i == startIndex)
			v[startIndex] = 1;
		else
		{
			cost[i] = graph[startIndex][i];
			if (cost[i] < INF)
				path[i] = startIndex;
			else
				path[i] = -1;
		}
	}
	for (int i = 1; i < M; i++)
	{
		int minCost = INF;
		int curNode = -1;
		for (int j = 0; j < M; j++)
		{
			if (v[j] == 0 && cost[j] < minCost)
			{
				minCost = cost[j];
				curNode = j;
			}
		}
		if (curNode == -1)
			break;
		v[curNode] = 1;
		for (int j = 0; j < M; j++)
		{
			if (v[j] == 0 && graph[curNode][j] + cost[curNode] < cost[j])
			{
				cost[j] = graph[curNode][j] + cost[curNode];
				path[j] = curNode;
			}
		}
	}
	printf("path[] = ");
	for (int n = 0; n < M; n++)
	{
		printf("%d ", path[n]);
	}
	printf("\n");
}

int main()
{
	
	int path[M] = { 0 };
	int cost[M] = { 0 };
	Dijkstra(0, path, cost);

}