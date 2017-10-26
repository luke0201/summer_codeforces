#include<stdio.h>
int n;
int main()
{
	int i, j;
	scanf("%d", &n);
	printf("%d\n", n + n / 2);
	for (i = 2; i <= n; i += 2)	printf("%d ", i);
	for (i = 1; i <= n; i += 2)	printf("%d ", i);
	for(i=2;i<=n;i+=2)	printf("%d ", i);
}