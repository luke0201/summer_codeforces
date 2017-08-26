#include<stdio.h>
int n, a, b, c, d, dab;
int main()
{
	int i, j;
	scanf("%d %d %d", &n, &a, &b);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &c);
		if (c == 1)
		{
			if (a > 0)
				a--;
			else
			{
				if (b > 0)
				{
					b--;
					d++;
				}
				else
				{
					if (d > 0)
					{
						d--;
					}
					else
						dab++;
				}
			}
		}
		if (c == 2)
		{
			if (b > 0)
				b--;
			else
				dab += 2;
		}
	}
	printf("%d", dab);
}