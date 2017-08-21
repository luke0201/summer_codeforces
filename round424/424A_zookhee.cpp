#include<stdio.h>
int n, a, b, sw;
int main()
{
	int i;
	scanf("%d", &n); 
	scanf("%d", &b);
	for (i = 1; i<n; i++)
	{
		scanf("%d", &a);
		if (sw == 0)
		{
			if (a == b)
				sw = 1;
			if (a < b)
			{
				sw = 2;
			}
		}
		else if (sw == 1)
		{
			if (a < b)
			{
				sw = 2;
			}
			if (a > b)
			{
				printf("NO");
				break;
			}
		}
		else if (sw == 2)
		{
			if (a >= b)
			{
				printf("NO");
				break;
			}
		}
		b = a;
	}
	if (i == n)
	{
		printf("YES");
	}
}