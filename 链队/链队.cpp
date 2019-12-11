#include<stdio.h>
#include<malloc.h>

typedef char ElemType;
typedef struct qnode
{
	ElemType data;
	struct qnode* next;
}DataNode;     // 链队的类型

typedef struct
{
	DataNode* front;    // 指向队首结点
	DataNode* rear;     // 指向队尾结点
}LinkQuNode;    // 链队头结点

/*
队空
	q->rear == NULL || q->front == NULL
*/

// 初始化链队
void InitQueue(LinkQuNode*& q)
{
	q = (LinkQuNode*)malloc(sizeof(LinkQuNode));
	q->front = q->rear = NULL;
}

//  销毁链队
void DestoryQueue(LinkQuNode*& q)
{
	DataNode* pre = q->front, * p;
	if (pre != NULL)
	{
		p = pre->next;
		while (p != NULL)
		{
			free(pre);
			pre = p;
			p = p->next;
		}
		free(pre);
	}
	free(q);
}

// 判断队列是否为空
bool IsQueueEmpty(LinkQuNode* q)
{
	return (q->front == NULL || q->rear == NULL);
}

// 进队
void Enter(LinkQuNode*& q, ElemType e)
{
	DataNode* s;
	s = (DataNode*)malloc(sizeof(DataNode));
	s->data = e;
	s->next = NULL;
	if (q->front == NULL)
		q->front = q->rear = s;
	else
	{
		q->rear->next = s;
		q->rear = s;
	}
}

// 出队列
bool ExitQueue(LinkQuNode*& q, ElemType& e)
{
	DataNode* p = q->front;
	if (p == NULL)
		return false;
	e = p->data;
	if (p->next == NULL)
		q->front = q->rear = NULL;
	else
		q->front = p->next;
	free(p);
	return true;
}

// 输出队中元素
void DispElem(LinkQuNode *q)
{
	DataNode* p = q->front;
	if (q->front != NULL)
	{
		printf("队首元素->%c \n", q->front->data);
		printf("队尾元素->%c \n", q->rear->data);
	}
	while (p != NULL)
	{
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");
}

// 采用一个不带头结点只有一个尾结点指针rear的循环单链表存储队列，设计初始化，进队，出队算法
typedef struct node
{
	ElemType data;
	struct node* rear;   // 队尾指针
}LinkNode;    // 单链表类型

// 初始化
void InitLinkQueue(LinkNode*& q)
{
	q = NULL;
}

// 进队
void EnterLQ(LinkNode*& q, ElemType e)
{
	
}

int main()
{
	LinkQuNode* q;
	InitQueue(q);
	Enter(q, 'a');
	DispElem(q);
	Enter(q, 'b');
	DispElem(q);
	Enter(q, 'c');
	DispElem(q);
	Enter(q, 'd');
	DispElem(q);
	Enter(q, 'e');
	DispElem(q);

	DestoryQueue(q);

	return 0;
}