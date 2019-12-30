#ifndef BSTREE_H
#define BSTREE_H

typedef int KeyType;
typedef char InfoType;
typedef struct node
{
	KeyType key;
	InfoType info;
	struct node* lchild, * rchild;
}BSTNode;

// 二叉排序树的结点插入
bool InsertBSTree(BSTNode*& bt, KeyType k);

// 二叉排序树的创建
BSTNode* CreateBSTree(KeyType K[], int n);

// 二叉排序树的查找(递归)
BSTNode* SearchBSTree(BSTNode* bt, KeyType k);

// 二叉排序树查找(非递归)
BSTNode* SearchBSTree(BSTNode* bt, KeyType k);

#endif
