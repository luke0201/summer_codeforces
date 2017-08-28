#include<stdio.h>
int a, b,g;
int dab=1;
int main()
{
	int i;
	scanf("%d %d", &a, &b);
	if (a < b)
		g = a;
	else
		g = b;
	for (i = 1; i <= g; i++)
		dab *= i;
	printf("%d", dab);
}