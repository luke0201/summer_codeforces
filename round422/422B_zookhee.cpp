#include<stdio.h>
int n, m,cnt, dab, c[1001], d[1001];
char s[1001], s2[1001];
int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	scanf("%s %s", s, s2);
	for (i = 0; i < m-n+1; i++)
	{
		cnt = 0;
		for (j = 0; j < n; j++)
		{
			if (s2[j + i] == s[j])
			{
				cnt++;
				d[j+1] = 1;
			}
		}
		if (dab < cnt)
		{
			dab = cnt;
			for (j = 1; j <= n; j++)
			{
				c[j] = d[j];
			}
		}
		for (j = 1; j <= n; j++)
		{
			d[j] = 0;
		}
	}
	printf("%d\n", n-dab);
	for (i = 1; i <= n; i++)
		if (!c[i]) printf("%d ", i);
}