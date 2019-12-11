#include<iostream>
#include<stdlib.h>
#include<malloc.h>
#include<stack>
#include<queue>
using namespace std;

typedef char ElemType;

// 二叉树的链表储存结构，一个数据域，两个指针域（左右孩子）
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

// 二叉树建立，按前序遍历的方式建立二叉树
void CreateBiTree(BiTree* T)
{
	ElemType ch;
	cin >> ch;
	if (ch == '#') *T = NULL;  // 保证为叶结点
	else
	{
		*T = (BiTree)malloc(sizeof(BiTree));  // 内存分配
		(*T)->data = ch;  // 生成结点
		CreateBiTree(&(*T)->lchild);  // 构造左子树
		CreateBiTree(&(*T)->rchild); // 构造右子树
	}
}

// 输出结点字符
void DispCh(ElemType ch)
{
	cout << ch << " ";
}

// 递归方式前序遍历二叉树
void PreOrderTraverse(BiTree T)
{
	if (T == NULL) return;
	DispCh(T->data);

	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

// 递归方式中序遍历二叉树
void InOrderTraverse(BiTree T)
{
	if (T == NULL) return;
	InOrderTraverse(T->lchild);
	DispCh(T->data);
	InOrderTraverse(T->rchild);
}

// 递归方式后序遍历二叉树
void PostOrderTraverse(BiTree T)
{
	if (T == NULL) return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	DispCh(T->data);
}

// 非递归方式遍历二叉树
// 1）层次遍历二叉树
/*void LevelOrderTraverse(BiTree T);
{
	
}*/

// 2）用入栈出栈方式前序遍历
/* 思路：将T入栈，遍历左子树；遍历完左子树返回时，
栈顶元素应为T，出栈，再先序遍历T的右子树。*/
void PreOrder(BiTree T)
{
	stack<BiTree> stack;
	BiTree p = T;   // p为遍历指针
	while (p || !stack.empty())
	{
		if (p != NULL)
		{
			stack.push(p);
			DispCh(p->data);
			p = p->lchild;
		}
		else
		{
			p = stack.top();
			stack.pop();
			p = p->rchild;
		}
	}
}






int main()
{
	BiTree T = NULL;
	cout << "请以前序遍历的方式输入扩展二叉树："; //类似输入AB#D##C##
	CreateBiTree(&T);// 建立二叉树
	cout << "递归前序遍历输出为：" << endl;
	PreOrderTraverse(T);
	cout << endl;

	cout << "递归中序遍历输出为：" << endl;
	InOrderTraverse(T);
	cout << endl;

	cout << "递归后序遍历输出为：" << endl;
	PostOrderTraverse(T);
	cout << endl;
	
	

	return 0;
}

