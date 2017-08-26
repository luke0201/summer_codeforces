#include<stdio.h>
char s, s2;
int n,a,b,g1,g2;
int main()
{
	int i, j;
	scanf("%c %c", &s, &s2);
	scanf("%d", &n);
	if (s == 'v') a = 1;
	else if (s == '<') a = 2;
	else if (s == '^') a = 3;
	else if (s == '>') a = 4;
	if (s2 == 'v') b = 1;
	else if (s2 == '<') b = 2;
	else if (s2 == '^') b = 3;
	else if (s2 == '>') b = 4;
	if (b > a)
	{
		g1 = b - a;
		g2 = (4 - b) + a;
		if (g1 % 4 == n % 4 && g2 % 4 == n % 4)
			printf("undefined");
		else if (g1 % 4 == n % 4)
			printf("cw");
		else
			printf("ccw");
	}
	else
	{
		g1 = a - b;
		g2 = (4 - a) + b;
		if (g1 % 4 == n % 4 && g2 % 4 == n % 4)
			printf("undefined");
		else if (g1 % 4 == n % 4)
			printf("ccw");
		else
			printf("cw");
	}
}