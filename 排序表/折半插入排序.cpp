#include<stdio.h>
#include"sort_list.h"

// ’€∞Î≤Â»Î≈≈–Ú   O(n^2)
void BinInsertSort(RecType R[], int n)
{
	int low, high, mid, i, j;
	RecType tmp;
	for (i = 1; i < n; i++)
	{
		if (R[i].key < R[i - 1].key)  
		{
			tmp = R[i];
			low = 0; high = i - 1;
			
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (R[mid].key > tmp.key)    // ‘⁄◊Û∞Î±ﬂ
					high = mid - 1;
				else
					low = mid + 1;
			}
			for (j = i - 1; j >= high + 1; j--)    // ≤Â»Î ˝æ›
				R[j + 1] = R[j];
			R[high + 1] = tmp;
		}
	}
}

int main()
{
	RecType r[MAXL];
	KeyType a[] = { 9,8,7,6,5,4,3,2,1,0 };
	Createlist(r, a, 10);
	BinInsertSort(r, 10);
	DispList(r, 10);
	return 0;
}