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

// �����������Ľ�����
bool InsertBSTree(BSTNode*& bt, KeyType k);

// �����������Ĵ���
BSTNode* CreateBSTree(KeyType K[], int n);

// �����������Ĳ���(�ݹ�)
BSTNode* SearchBSTree(BSTNode* bt, KeyType k);

// ��������������(�ǵݹ�)
BSTNode* SearchBSTree(BSTNode* bt, KeyType k);

#endif
