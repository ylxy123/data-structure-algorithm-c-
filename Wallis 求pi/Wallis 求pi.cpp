#include<stdio.h>

int main()
{
	double pi, sum=1.0000000, i = 1.0000000;
	
	for (i = 0; i < 100000000; i++)
	{
		sum *= (4.0000000 * (i+1) * (i + 1)) / (4.0000000 * (i + 1) * (i + 1) - 1.0000000);
	}
	printf("%.10f", 2 * sum);
	return 0;
}