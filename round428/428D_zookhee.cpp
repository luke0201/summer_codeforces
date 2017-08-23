#include<stdio.h>
const int M = 1000000;
int n, dat[200001],two[200001];
long long dab, gcd[1000001], c[1000001];
int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &dat[i]);
		c[dat[	i]]++;
	}
	two[0] = 1;
	two[1] = 2;
	for (i = 2; i <= n; i++)
	{
		two[i] = two[i - 1] * 2;
		two[i] %= 1000000007;
	}
	for (i = 2; i <= M; i++)
		for (j = i * 2; j <= M; j += i)
			c[i] += c[j];
	for (i = M; i >= 2; i--)
	{
		gcd[i] = c[i] * two[c[i]-1];
		gcd[i] %= 1000000007;
		for (j = i * 2; j <= M; j += i)
		{
			gcd[i] -= gcd[j];
			if (gcd[i] < 0) gcd[i] += 1000000007;
		}
		gcd[i] %= 1000000007;
	}
	for (i = 2; i <= M; i++)
	{
		dab += i*gcd[i];
		dab %= 1000000007;
	}
	printf("%lld", dab);
}