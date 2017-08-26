#include<stdio.h>
int a, b, c, d, e;
int left, right;
int main()
{
	int i, j;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	left = b*a + 2 * d;
	right = a*c + 2 * e;
	if (left < right)
		printf("First");
	else if (left > right)
		printf("Second");
	else
		printf("Friendship");
}