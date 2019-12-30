#include<stdio.h>
#include<malloc.h>
#include"bstree.h"


// 二叉排序树的结点插入
bool InsertBSTree(BSTNode*& bt, KeyType k)
{
	if (bt == NULL)    // 若bt为空，创建关键字为k的结点并作为根结点
	{
		bt = (BSTNode*)malloc(sizeof(BSTNode));
		bt->key = k;
		bt->lchild = bt->rchild = NULL;
		return true;    // 插入完成返回true
	}
	else if (k == bt->key)
		return false;
	else if (k < bt->key)
		return InsertBSTree(bt->lchild, k);
	else
		return InsertBSTree(bt->rchild, k);
}

// 二叉排序树的创建
BSTNode* CreateBSTree(KeyType K[], int n)
{
	BSTNode* bt = NULL;
	int i = 0;
	while (bt != NULL)
	{
		InsertBSTree(bt, K[i]);
		i++;
	}
	return bt;
}

// 二叉排序树的查找(递归)
BSTNode* SearchBSTree(BSTNode* bt, KeyType k)
{
	if (bt == NULL || bt->key == k)  // 返回的条件
		return bt;
	if (k < bt->key)
		return SearchBSTree(bt->lchild, k);    // 若小于，在左子树找
	else
		return SearchBSTree(bt->rchild, k);    // 大于则在右子树找
}

// 二叉排序树查找(非递归)
BSTNode* SearchBSTree(BSTNode *bt, KeyType k)
{
	BSTNode* p = bt;
	while (p != NULL && p->key != k)
	{
		if (p->key > k)
			p = p->lchild;
		else
			p = p->rchild;
	}
	return bt;
}