#include<stdio.h>
#include<malloc.h>

/*线索化二叉树的算法思想：
1）   先构造好二叉链表，标志位均为0；
2）   选择恰当的遍历方法（前，中，后序）遍历该二叉链表
	  遍历过程中记录前一个访问的结点；
3）   判断当前访问结点的左指针域是否为空，若为空，则
	  修改指针域指向前一个访问的结点，同时修改标志位为1；
4）   判断前一个访问结点的右指针域是否为空，若为空，则
	  修改指针域指向当前访问的结点，同时修改标志位为1
5）   重复直到遍历完所有结点。

*若rtag=true，则指针域right直接指向其后继
 若rtag=true, 则当前结点的后继应是其右子树的左链尾的结点*/

typedef char ElemType;
typedef enum
{
	Link,
	Thread
}Pointer;
typedef struct TriTreeNode
{
	TriTreeNode(const char data) :_data(data);
};
