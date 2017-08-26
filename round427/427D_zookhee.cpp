#include<stdio.h>
#include<string.h>
char s[5010];
int dp[5010][5010],n,dab[5010];
int main()
{
	int i, j;
	scanf("%s", s);
	n = strlen(s);
	for (i = 0; i < n; i++)
		dp[i][i] = 1;
	for (i = 1; i < n; i++) {
		for (j = 0; j < n; j++)
		{
			if (i == 1)
			{
				if (s[j] == s[j + i])
					dp[j][j + i] = 2;
				continue;
			}
			if (s[j] == s[j + i] && dp[j + 1][j + i - 1]!=0)
			{
				dp[j][j + i] = dp[j][j + ((i+1) / 2-1)] + 1;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			dab[dp[i][j]]++;
	}
	for (i = n - 1; i >= 0; i--)
		dab[i] += dab[i + 1];
	for (i = 1; i <= n; i++)
		printf("%d ", dab[i]);

}