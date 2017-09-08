#include<stdio.h>
int n, m;
int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	if (n == m || m==0)
		printf("0 ");
	else
		printf("1 ");
	if ((n%3==0 && m >= n / 3) || (n%3!=0 && m>n/3))
	{
		printf("%d", n - m);
	}
	else
	{
		printf("%d",m*2);
	}
}