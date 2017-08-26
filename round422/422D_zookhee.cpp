#include<stdio.h>
#include<algorithm>
using namespace std;
const long long M = 1000000007;
int t, l, r, dat[5000010];
long long dab, c=1,dp[5000010];
long long func(long long a)
{
	long long &ret = dp[a];
	if (ret != -1) return ret;
	ret = ((a*(a - 1)) / 2) % M;
	if(dat[a]!=a)
	{
		long long g = ((dat[a] * (dat[a] - 1)) / 2) % M;
		ret = ((a / dat[a]) * g)%M+func(a/dat[a])%M;
		ret %= M;
	}
	return ret;
}
int main()
{
	int i, j;
	scanf("%d %d %d", &t, &l, &r);
	for (i = 1; i <= r; i++)
	{
		dat[i] = i;
		dp[i] = -1;
	}
	for (i = 2; i*i <= r; i++)
	{
		if (dat[i]!=i) continue;
		for (j = i * i; j <= r; j += i)
		{
			if (dat[j] == j) dat[j] = i;
		}
	}
	for (i = l; i <=r; i++)
	{
		dab += (c*func(i))%M;
		dab %= M;
		c *= t;
		c %= M;
	}
	dab %= M;
	printf("%lld", dab);
}