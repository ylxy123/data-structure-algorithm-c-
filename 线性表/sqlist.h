#ifndef SQLIST_H
#define SQLIST_H
#define MaxSize 100

typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;    // 顺序表

// 根据a数组中n个元素创建线性表
void CreateSqlist(SqList*& L, ElemType a[], int n);   // L是输出型参数，因此调用时应当加上& 

// 初始化线性表
void InitSqlist(SqList*& L);

// 销毁线性表   
void DestorySqlist(SqList*& L);   // 当通过malloc分配空间后，应调用free()释放内存

// 判断线性表是否为空
bool ListEmpty(SqList*& L);

// 输出线性表
void DispSqlist(SqList* L);

// 用引用型参数e返回L中第i个值，若i非法，返回false；否则返回true
bool GetElem(SqList* L, int i, ElemType e);

// 按元素值查找第一个与e相等的元素的逻辑序号（下标+1），若元素不存在，返回0
int LocElem(SqList* L, ElemType e);

// 在线性表中第i个位置插入新元素e，若i非法，返回false
bool InsertElem(SqList* L, int i, ElemType e);

// 删除线性表第i个位置的元素，若i非法，返回false
bool DeleteElem(SqList*& L, int i);

// 删除线性表中所有值为x的元素，该算法时间复杂度为O(n)，空间复杂度为O(1)
void DelElems1(SqList*& L, ElemType x);

// 同上的第二种算法
void DelElems2(SqList*& L, ElemType x);



#endif
