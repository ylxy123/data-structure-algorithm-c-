#include<stdio.h>
#define MaxSize 100

typedef struct
{
	char data[MaxSize];    // 存放字符串
	int length;    // 存放串长
}SqString;    // 顺序串

// 生成串
void StrAssign(SqString& s, char cstr[])
{
	int i;
	for (i = 0; cstr[i] != '\0'; i++)
		s.data[i] = cstr[i];
	s.length = i;
}

// 串的复制
void StrCopy(SqString& s, SqString t)
{
	int i;
	for (i = 0; t.data[i] != '\0'; i++)
		s.data[i] = t.data[i];
	s.length = t.length;
}

// 判断串是否相等
bool IsStringEqual(SqString s, SqString t)
{
	int i; bool same = true;
	if (s.length != t.length)
		same = false;
	else
	{
		for (i = 0; i < s.length; i++)
		{
			if (s.data[i] != t.data[i])
			{
				same = false;
				break;
			}
		}
	}
	return same;
}

// 求串长
int StrLength(SqString s)
{
	printf("Length: %d ", s.length);
	return s.length;
}

// 串的连接
SqString Concat(SqString s, SqString t, SqString& str)
{
	int i = 0;
	for (i = 0; i < s.length; i++)
		str.data[i] = s.data[i];
	for (i = 0; i < t.length; i++)
		str.data[s.length + i] = t.data[i];
	str.length = s.length + t.length;
	return str;
}

// 输出串
void DispString(SqString s)
{
	if (s.length > 0)
	{
		printf("Length: %d\n", s.length);
		for (int i = 0; i < s.length; i++)
			printf("%c ", s.data[i]);
		printf("\n");
	}
}

// 求子串(从i开始之后连续j个)
SqString SubString(SqString s, int i, int j, SqString& str)
{
	int m, k = 0;
	str.length = 0;   // 置空str
	if (i > s.length || i < 0 || j < 0 || i + j > s.length + 1)
		return str;   // 参数非法返回空串
	for (m = i - 1; m < i + j - 1; m++)
	{
		str.data[k] = s.data[m];
		k++;
	}
	str.length = j;
	return str;
}

// 子串的插入(将顺序串s2插入s1的第i个位置上)
SqString InsertSubString(SqString s1, SqString s2, int i, SqString& str)
{
	int j;
	str.length = 0;
	if (i > s1.length + 1 || i <= 0)
		return str;
	for (j = 0; j < i - 1; j++)
		str.data[j] = s1.data[j];
	for (j = 0; j < s2.length; j++)
		str.data[i - 1 + j] = s2.data[j];
	for (j = i - 1; j < s1.length; j++)
		str.data[s2.length + j] = s1.data[j];
	str.length = s1.length + s2.length;
	return str;
}

// 子串的删除
SqString DelSubString(SqString s, int i, int j, SqString& str)
{
	int k;
	str.length = 0;
	if (i<0 || j<0 || i + j - 1 >s.length || i>s.length + 1)
		return str;
	for (k = 0; k < i - 1; k++)
		str.data[k] = s.data[k];
	for (k = i + j - 1; k < s.length; k++)
		str.data[k - j] = s.data[k];
	str.length = s.length - j;
	return str;
}

// 子串的替换(在s中将第i个开始的连续j个字符串用t替换)
SqString ExchangeStr(SqString s, int i, int j, SqString t, SqString& str)
{
	int k;
	str.length = 0;
	if (i<0 || j<0 || i + j - 1>s.length || i>s.length + 1)
		return str;
	for (k = 0; k < i - 1; k++)
		str.data[k] = s.data[k];
	for (k = 0; k < t.length; k++)
		str.data[i + k - 1] = t.data[k];
	for (k = i + j - 1; k < s.length; k++)
		str.data[t.length + k - j] = s.data[k];
	str.length = s.length - j + t.length;
	return str;
}


int main()
{
	SqString str1, str2,newstr;
	char name[MaxSize] = "ylxymory";
	StrAssign(str1, name);
	char a[MaxSize] = "1234";
	StrAssign(str2, a);
	ExchangeStr(str1, 2, 2, str2, newstr);
	DispString(newstr);
	
	return 0;
}