#include<stdio.h>
int n, dat[300010],chk[300010],g,cnt,cnt2;
int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &dat[i]);
	g = n;
	printf("1 ");
	for (i = 0; i < n-1; i++)
	{
		chk[dat[i]] = 1;
		if (dat[i] == g)
		{
			while (chk[g] != 0)
			{
				g--;
				cnt2++;
			}
		}
		cnt++;
		printf("%d ", cnt - cnt2 + 1);
	}
	printf("1");
}