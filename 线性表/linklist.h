#ifndef LINKLIST_H
#define LINKLIST_H
#define MaxSize 100

typedef int ElemType;
typedef struct LNode
{
	ElemType data;  // ������
	struct LNode* next;   // ָ����ָ����
}LinkNode;       // ��������

// ������a���½�һ������Ϊn�ĵ�������ͷ�巨
void CreateListF(LinkNode*& L, ElemType a[], int n);

// β�巨����������
void CreateListR(LinkNode*& L, ElemType a[], int n);

// ��ʼ��������
void InitList(LinkNode*& L);

// ���ٵ�����
void DestoryList(LinkNode*& L);

// �жϵ������Ƿ�Ϊ��
bool ListIsNULL(LinkNode* L);

// ͨ������������ĳ���
int ListLength(LinkNode* L);

// ���������
void DispList(LinkNode* L);

// �������е�i��λ�õ�����Ԫ��ֵ
bool GetElem(LinkNode* L, int i, ElemType& e);








#endif
