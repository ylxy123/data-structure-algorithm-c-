#include<stdio.h>
#include<malloc.h>
#define MaxSize 100

typedef int ElemType;
typedef struct LNode
{
	ElemType data;  // 数据域
	struct LNode* next;   // 指针域指向后继
}LinkNode;       // 单链表结点

// 从数组a中新建一个长度为n的单链表——头插法
void CreateListF(LinkNode*& L, ElemType a[], int n)
{
	LinkNode* s;   // 声明数据结点类型
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;    // 创建头结点，将其后继置为空

	for (int i = 0; i < n; i++)  // 循环创建数据结点s
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];    // 创建数据结点s 
		s->next = L->next;     // 将该结点插入原头结点之后，首结点之前
		L->next = s;
	}
}

// 尾插法建立单链表
void CreateListR(LinkNode*& L, ElemType a[], int n)
{
	LinkNode* s, * r;  // 尾结点r初始指向头结点，随后始终指向尾结点
	L = (LinkNode*)malloc(sizeof(LinkNode));    // 创建头结点
	r = L;
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		r->next = s;   // 将数据结点s插入表尾，同时更新r指向s
		r = s;
	}
	r->next = NULL;
}

// 初始化单链表
void InitList(LinkNode*& L)
{
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
}

// 销毁单链表
void DestoryList(LinkNode*& L)
{
	LinkNode* pre = L, * p = L->next;    // 初始时pre指向头结点，p指向首结点
	while (p != NULL)    // 当p不为空时循环
	{
		free(pre);    // 逐一释放
		pre = p;     // 向后移动指针
		p = pre->next;
	}
	free(pre);    // 退出循环后留下一个尾结点，将其释放
}

//  判断单链表是否为空
bool ListIsNULL(LinkNode* L)
{
	return (L->next == NULL);
}

// 通过遍历求单链表的长度
int ListLength(LinkNode* L)
{
	int n = 0;    // 头结点序号为0
	LinkNode* p = L;    // p指针指向头结点
	while (p != NULL)
	{
		n++;
		p = p->next;    // p后移
	}
	return (n);    // 循环结束，p指向尾结点，返回结点个数n
}

// 输出单链表
void DispList(LinkNode* L)
{
	LinkNode* p = L->next;    // p指针指向首结点
	while (p != NULL)      // p不为空循环
	{
		printf("%d ", p->data);    // 输出结点数据
		p = p->next;       // 指针指向后继
	}
	printf("\n");
}

// 输出数组
void DispArray(ElemType a[],int n)
{

	for (int i = 0; i < n; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

// 求单链表中第i个位置的数据元素值
bool GetElem(LinkNode* L, int i, ElemType& e)
{
	LinkNode* p = L;    // 指针p指向头结点
	int j = 0;    // 记录遍历的结点数
	while (j < i && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
		return false;
	else
	{
		e = p->data;
		return true;
	}
}

// 按元素值查找逻辑序号
int LocateElem(LinkNode* L, ElemType e)
{
	int i = 1;
	LinkNode* p = L->next;
	while (p->data != e && p != NULL)
	{
		i++;
		p = p->next;
	}
	if (p == NULL)
		return 0;
	else
		return (i);
}

// 插入数据元素
bool InsertElem(LinkNode*& L, int i, ElemType e)
{
	int j = 0;
	LinkNode* p = L,*s;
	if (i <= 0)
		return false;
	while (j < i - 1 && p != NULL)    // 查找第i-1个结点，p指向它
	{
		p = p->next;
		j++;
	}
	if (p == NULL)
		return false;
	else
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}

// 先在单链表中找到第i个结点，由p指向它，若存在，且其后继(q所指)也存在，则删除q所指结点，返回true；否则返回false
bool DelElem(LinkNode* L, int i, ElemType &e)
{
	int j = 0;
	LinkNode* p = L, * q;    // p指向头结点
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)    // 若不存在，返回false
		return false;
	else
	{
		q = p->next;    // q指向第i个结点
		if (q == NULL)    // 若不存在，返回false
			return false;
		e = q->data;    // 记录被删除的结点的数据
		p->next = q->next;    
		free(q);
		return true;
	}
}

// 将带头结点的单链表L=(a1,b1,a2,b2,...,an,bn)拆分为两个带头结点的单链表L1和L2，其中，L1=(a1,a2,...,an);L2=(b1,b2,...,bn)
void SplitList(LinkNode *&L,LinkNode *&L1, LinkNode *&L2)
{
	LinkNode* p = L->next, * q, * r1;    // p指向第一个数据结点(p->a1)
	L1 = L;        // L1利用原来的头结点
	r1 = L1;	   // r1始终指向L的尾结点
	L2 = (LinkNode*)malloc(sizeof(LinkNode));    // 创建L2的头结点
	L2->next = NULL;
	while (p != NULL)
	{
		r1->next = p;    // 将p以尾插法插入L1
		r1 = p;     // r1后移，指向尾结点
		p = p->next;     // p指针后移
		q = p->next;     // 由于头插法会改变p的next，因此用q保存结点p的后继
		p->next = L2->next;    // 头插法将q插入L2
		L2->next = p;    
		p = q;     // p重新指向q(p->数据为ai+1的结点）
	}
	r1->next = NULL;
}

// 删除一个单链表中元素值最大的结点(结点唯一)
void DelMax(LinkNode*& L)
{
	LinkNode* pre = L, * p = pre->next, * maxp = p, * maxpre = pre;    // 初始p指向首结点，pre指向头结点，maxp指向p
	while (p != NULL)
	{
		if (maxp->data < p->data)
		{
			maxp = p;
			maxpre = pre;
		}
		pre = p;
		p = p->next;
	}
	maxpre->next = maxp->next;
	free(maxp);
}

// 对单链表进行排序(递增)——插入排序
void SortList(LinkNode*& L)
{
	LinkNode* p, * pre, * q;
	p = L->next->next;
	L->next->next = NULL;    // 断开L->next与L->next->next之间的关系
	while (p != NULL);
	{
		q = p->next;     // q指针保存p结点的后继
		pre = L;         // pre指向头结点
		while (pre->next != NULL && pre->next->data < p->data)
			pre = pre->next;    // 在新L中找到比p大的
		p->next = pre->next;    // 插入L
		pre->next = p;
		p = q;    // p指针后移，继续扫描单链表剩余的结点
	}
}

int main()
{
	ElemType a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	LinkNode* L,*L1,*L2;
	ElemType e;
	
	printf("数组a：\n");
	DispArray(a, 10);
	printf("\n");
	printf("根据数组a创建单链表L \n");
	CreateListR(L, a, 10);
	DispList(L);
	printf("\n");
	printf("获取L第3个元素值\n");
	GetElem(L, 3, e);
	printf("%d \n", e);
	printf("\n");
	printf("L中元素值为4的逻辑序号\n");
	printf("%d \n",LocateElem(L, 4));
	printf("\n");
	printf("在L中的第5个位置插入16\n");
	InsertElem(L, 5, 16);
	DispList(L);
	printf("\n");
	printf("删除最后一个结点\n");
	DelElem(L, 11,e);
	DispList(L);
	printf("\n");
	printf("拆分L为L1，L2\n");
	SplitList(L, L1, L2);
	printf("L1:");
	DispList(L1);
	printf("L2:");
	DispList(L2);
	printf("\n");
	printf("销毁单链表L, L1, L2\n");
	DestoryList(L);
	
	
	return 0;
}

