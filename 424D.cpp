#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<limits.h>
using namespace std;
long long n, m, p, dat[1001], d[2001],dp[1001][2001];
int main()
{
	int i, j;
	scanf("%lld %lld %lld", &n, &m, &p);
	for (i = 1; i <= n; i++)
		scanf("%lld", &dat[i]);
	for (i = 1; i <= m; i++)
		scanf("%lld", &d[i]);
	sort(dat + 1, dat + n + 1);
	sort(d + 1, d + m + 1);
	for (i = 1; i <= n; i++)
		for (j = 0; j <= m; j++)
			dp[i][j] = LLONG_MAX;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			dp[i][j] = min(dp[i][j], max(dp[i - 1][j - 1], abs(dat[i] - d[j]) + abs(p - d[j])));
			dp[i][j] = min(dp[i][j], dp[i][j - 1]);
		}
	}
	printf("%lld", dp[n][m]);
}