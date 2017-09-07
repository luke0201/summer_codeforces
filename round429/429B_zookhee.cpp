#include<stdio.h>
int n,a, dat[1000],cnt;
int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (a % 2 == 1) cnt++;
	}
	if (cnt > 0)
		printf("First");
	else
		printf("Second");
}