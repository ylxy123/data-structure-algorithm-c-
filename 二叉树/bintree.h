#ifndef BINTREE_H
#define BINTREE_H
#define MaxSize 100

typedef char ElemType;
typedef ElemType SqBinTree[MaxSize];   // ��������˳��洢����

typedef struct node
{
	ElemType data;
	struct node* lchild;
	struct node* rchild;
}BTNode;    // ��������




#endif
