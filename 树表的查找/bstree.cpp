#include<stdio.h>
#include<malloc.h>
#include"bstree.h"


// �����������Ľ�����
bool InsertBSTree(BSTNode*& bt, KeyType k)
{
	if (bt == NULL)    // ��btΪ�գ������ؼ���Ϊk�Ľ�㲢��Ϊ�����
	{
		bt = (BSTNode*)malloc(sizeof(BSTNode));
		bt->key = k;
		bt->lchild = bt->rchild = NULL;
		return true;    // ������ɷ���true
	}
	else if (k == bt->key)
		return false;
	else if (k < bt->key)
		return InsertBSTree(bt->lchild, k);
	else
		return InsertBSTree(bt->rchild, k);
}

// �����������Ĵ���
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

// �����������Ĳ���(�ݹ�)
BSTNode* SearchBSTree(BSTNode* bt, KeyType k)
{
	if (bt == NULL || bt->key == k)  // ���ص�����
		return bt;
	if (k < bt->key)
		return SearchBSTree(bt->lchild, k);    // ��С�ڣ�����������
	else
		return SearchBSTree(bt->rchild, k);    // ����������������
}

// ��������������(�ǵݹ�)
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