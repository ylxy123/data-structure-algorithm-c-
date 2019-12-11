#include<stdio.h>
#include<malloc.h>
#include<stack>
#include<queue>
#include<stdlib.h>
#define MaxSize 100

typedef char ElemType;

typedef struct node
{
	ElemType data;				//数据元素
	struct node *lchild;		//指向左孩子
	struct node *rchild;		//指向右孩子
} BTNode;

void CreateBTNode(BTNode*& b, char* str)		//由str串创建二叉链
{
	BTNode* St[MaxSize], * p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;				//建立的二叉树初始时为  
	ch = str[j];
	while (ch != '\0')	//str未扫描完时循环 
	{
		switch (ch)
		{
		case '(':top++; St[top] = p; k = 1; break;		//为左节点
		case ')':top--; break;
		case ',':k = 2; break;                      	//为右节点
		default:p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch; p->lchild = p->rchild = NULL;
			if (b == NULL)                    //p指向二叉树的根节点
				b = p;
			else  							//已建立二叉树根节点
			{
				switch (k)
				{
				case 1:St[top]->lchild = p; break;
				case 2:St[top]->rchild = p; break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}

void DispBTNode(BTNode* b)	//以括号表示法输出二叉树
{
	if (b != NULL)
	{
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL)
		{
			printf("(");
			DispBTNode(b->lchild);
			if (b->rchild != NULL) printf(",");
			DispBTNode(b->rchild);
			printf(")");
		}
	}
}

void DestroyBTNode(BTNode*& b)
{
	if (b != NULL)
	{
		DestroyBTNode(b->lchild);
		DestroyBTNode(b->rchild);
		free(b);
	}
}

/* ↓作业一↓ */
void PostOrderTraverse(BTNode* b)  // 后序遍历的递归算法
{
	if (b != NULL)
	{
		PostOrderTraverse(b->lchild);   //递归访问左子树
		PostOrderTraverse(b->rchild);   // 递归访问右孩子
		printf("%c", b->data);   // 最后访问根结点
	}
}

void PostOrder(BTNode* b)
{
	BTNode* St[MaxSize], *p;
	int top = -1;
	if (b != NULL)
	{

		while (top > -1)				//栈不为空时循环
		{   
			if (p->lchild != NULL)	//左孩子入栈
			{
				top++;
				St[top] = p->rchild;
			}
			if (p->rchild != NULL)	//右孩子入栈
			{
				top++;
				St[top] = p->lchild;
			}
			top++;						//根节点入栈
			St[top] = b;
			p = St[top];				//退栈并访问该节点
			top--;
			printf("%c ", p->data);
		}

	}
}

int main()
{
	BTNode* b;
	CreateBTNode(b, "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))");
	printf("二叉树b:"); DispBTNode(b); printf("\n");
	printf("  非递归算法:"); PostOrder(b); printf("\n");
	printf("    递归算法:"); PostOrderTraverse(b);

	system("pause");
	return 0;
}