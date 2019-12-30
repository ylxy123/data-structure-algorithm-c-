#ifndef BINTREE_H
#define BINTREE_H
#define MaxSize 100

typedef char ElemType;
typedef ElemType SqBinTree[MaxSize];   // 二叉树的顺序存储类型

typedef struct node
{
	ElemType data;
	struct node* lchild;
	struct node* rchild;
}BTNode;    // 二叉链表




#endif
