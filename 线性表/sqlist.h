#ifndef SQLIST_H
#define SQLIST_H
#define MaxSize 100

typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;    // ˳���

// ����a������n��Ԫ�ش������Ա�
void CreateSqlist(SqList*& L, ElemType a[], int n);   // L������Ͳ�������˵���ʱӦ������& 

// ��ʼ�����Ա�
void InitSqlist(SqList*& L);

// �������Ա�   
void DestorySqlist(SqList*& L);   // ��ͨ��malloc����ռ��Ӧ����free()�ͷ��ڴ�

// �ж����Ա��Ƿ�Ϊ��
bool ListEmpty(SqList*& L);

// ������Ա�
void DispSqlist(SqList* L);

// �������Ͳ���e����L�е�i��ֵ����i�Ƿ�������false�����򷵻�true
bool GetElem(SqList* L, int i, ElemType e);

// ��Ԫ��ֵ���ҵ�һ����e��ȵ�Ԫ�ص��߼���ţ��±�+1������Ԫ�ز����ڣ�����0
int LocElem(SqList* L, ElemType e);

// �����Ա��е�i��λ�ò�����Ԫ��e����i�Ƿ�������false
bool InsertElem(SqList* L, int i, ElemType e);

// ɾ�����Ա��i��λ�õ�Ԫ�أ���i�Ƿ�������false
bool DeleteElem(SqList*& L, int i);

// ɾ�����Ա�������ֵΪx��Ԫ�أ����㷨ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)
void DelElems1(SqList*& L, ElemType x);

// ͬ�ϵĵڶ����㷨
void DelElems2(SqList*& L, ElemType x);



#endif
