#include<stdio.h>
int n, a, b,cnt;
int dat[100010], chk[100010];
int main()
{
	int i, j;
	scanf("%d %d %d", &n, &a, &b);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &dat[i]);
		chk[dat[i] % b]++;
	}
	for (i = 0; i < b; i++)
	{
		if (chk[i] >= a)
		{
			printf("Yes\n");
			cnt = 0;
			for (j = 0; j < n; j++)
			{
				if (dat[j] % b == i)
				{
					printf("%d ", dat[j]);
					cnt++;
					if (cnt == a) break;
				}
			}
			break;
		}
	}
	if (i == b)
		printf("No");
}