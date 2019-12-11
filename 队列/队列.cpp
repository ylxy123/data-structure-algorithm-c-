#include<stdio.h>
#include<malloc.h>
#define MaxSize 20

typedef char ElemType;
typedef struct
{
	ElemType data[MaxSize];    // 队中元素
	int front;      // 队首指针
	int	rear;		// 队尾指针
}SqQueue;        // 顺序队

/* 
队空：
	q->front == q->rear
队满：
	q->rear == MaxSize - 1
进队：
	q->rear++;data[rear] = e;
出队:
	q->front++;e = data[front];
*/

// 初始化队
void InitQueue(SqQueue*& q)
{
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = -1;
}

// 销毁队
void DestoryQueue(SqQueue*& q)
{
	free(q);
}

// 队列是否为空
bool IsQueueEmpty(SqQueue* q)
{
	return (q->front == q->rear);
}

// 元素e进队
bool Enter(SqQueue*& q, ElemType e)
{
	if (q->rear == MaxSize - 1)
		return false;
	q->rear++;
	q->data[q->rear] = e;
	return true;
}

// 元素e出队
bool Exit(SqQueue*& q, ElemType& e)
{
	if (q->front == q->rear)
		return false;
	q->front++;
	e = q->data[q->front];
	return true;
}

// 输出队中元素
void DispQueue(SqQueue* q)
{
	for (int i = q->front + 1; i <= q->rear; i++)
	{
		printf("%c ", q->data[i]);
	}
	printf("\n");
}

// 返回队长度
int LenQueue(SqQueue* q)
{
	printf("Length: %d", q->rear - q->front);
	return (q->rear - q->front);
}

int main()
{
	SqQueue* q;
	ElemType e;
	InitQueue(q);
	Enter(q, 'a');
	DispQueue(q);
	Enter(q, 'b');
	DispQueue(q);
	Enter(q, 'c');
	DispQueue(q);
	Enter(q, 'd');
	DispQueue(q);
	Enter(q, 'e');
	DispQueue(q);
	Exit(q, e);
	DispQueue(q);
	LenQueue(q);
	DestoryQueue(q);
	return 0;
}