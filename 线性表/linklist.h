#ifndef LINKLIST_H
#define LINKLIST_H
#define MaxSize 100

typedef int ElemType;
typedef struct LNode
{
	ElemType data;  // 数据域
	struct LNode* next;   // 指针域指向后继
}LinkNode;       // 单链表结点

// 从数组a中新建一个长度为n的单链表——头插法
void CreateListF(LinkNode*& L, ElemType a[], int n);

// 尾插法建立单链表
void CreateListR(LinkNode*& L, ElemType a[], int n);

// 初始化单链表
void InitList(LinkNode*& L);

// 销毁单链表
void DestoryList(LinkNode*& L);

// 判断单链表是否为空
bool ListIsNULL(LinkNode* L);

// 通过遍历求单链表的长度
int ListLength(LinkNode* L);

// 输出单链表
void DispList(LinkNode* L);

// 求单链表中第i个位置的数据元素值
bool GetElem(LinkNode* L, int i, ElemType& e);








#endif
