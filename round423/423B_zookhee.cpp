#include<stdio.h>
int n, m,a,cnt,c,dat[101][101],dab;
char s[101][101];
int main()
{
	int i, j,k,l;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%s", s[i]);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			if (s[i][j] == 'B') {
				cnt++; dat[i][j]++;
			}
			if (j!=0) dat[i][j] += dat[i][j - 1];
		}
	if (n < m) a = n; 
	else a = m;
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < n-i; j++)
		{
			for (k = 0; k < m - i; k++)
			{
				c = 0;
				for (l = j; l <= j + i; l++)
				{
					c += dat[l][k + i];
					if (k!=0) c -= dat[l][k - 1];
				}
				if (c == cnt)
				{
					printf("%d", (i + 1)*(i + 1) - c);
					return 0;
				}
			}
		}
	}
	printf("-1");
}