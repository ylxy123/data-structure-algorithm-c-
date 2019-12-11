#include<stdio.h>
#include<malloc.h>
#define MaxSize 10

typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int front, rear;
}SqQueue;    

// 环形队初始化
void InitQueue(SqQueue*& q)
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
}

// 销毁队列
void DestoryQueue(SqQueue*& q)
{
	free(q);
}

// 判断队列是否为空
bool IsQueueEmpty(SqQueue* q)
{
	return (q->front == q->rear);
}

// 进队
bool Enter(SqQueue*& q, ElemType e)
{
	if ((q->rear + 1) % MaxSize == q->front)    // 若队满返回false
		return false;
	q->rear = (q->rear++) % MaxSize;      // rear增1
	q->data[q->rear] = e;
	return true;
}

// 出队
bool Exit(SqQueue*& q, ElemType& e)
{
	if (q->front == q->rear)
		return false;
	q->front = (q->front++) % MaxSize;
	e = q->data[q->front];
	return true;
}

// 返回元素个数
int LenQueue(SqQueue* q)
{
	int i = (q->rear - q->front + MaxSize) % MaxSize;
	printf("Length: %d", i);
	return i;
}

// 输出队中元素
void DispQueue(SqQueue* q)
{
	for (int i = q->front % MaxSize + 1; i <= q->rear % MaxSize; i++)
	{
		printf("%d ", q->data[i]);
	}
	printf("\n");
}

// 求解报数问题：设有n人站一排，从左往右报数'1,2',报到1的出列 ,报到2的站最右, 输出最终序列
void number(int n)
{
	printf("\n\n");
	SqQueue* q;
	ElemType e;
	InitQueue(q);
	for (int i = 1; i <= n; i++)
		Enter(q, i);
	while (!IsQueueEmpty(q))
	{
		Exit(q, e);
		printf("%d ", e);
		if (!IsQueueEmpty(q))
		{
			Exit(q, e);
			Enter(q, e);
		}
	}
	printf("\n");
	DestoryQueue(q);
}


int main()
{

	int n = 8;
	
	number(n);

	return 0;
}