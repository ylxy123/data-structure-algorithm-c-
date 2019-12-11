#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#define MAX 40000
using namespace std;
struct node
{
	char name[30];
}que[MAX];
/*
BKDRHash函数的解析链接：
http://blog.csdn.net/djinglan/article/details/8812934
*/
unsigned int BKDRHash(char* str)
{
	unsigned int seed = 13;//也可以乘以31、131、1313、13131、131313..
	unsigned int hash = 0;
	while (*str)
	{
		hash = hash * seed + (*str++);
	}

	return hash % 32767;//最好对一个大的素数取余
}
int main()
{
	int i = 0, n, j;
	char a[MAX][30];
	char temp[300];
	memset(a, 0, sizeof(a));

	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> que[i].name;
		strcpy(a[BKDRHash(que[i].name)], que[i].name);
	}
	cout << "请输入要查找的字符串:";
	while (~scanf("%s", temp))
	{
		if (strcmp(a[BKDRHash(temp)], temp) == 0)
			cout << "yes" << endl;
		else
		{
			cout << "no" << endl;
			strcpy(a[BKDRHash(temp)], temp);
			strcpy(que[i++].name, temp);
		}
	}
	for (j = 0; j <= i; j++)
	{
		cout << que[j].name << endl;//含有的所有字符串
	}
	return 0;
}