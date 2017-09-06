#include<stdio.h>
long long l, r, x, y, k;
int main()
{
	long long i, j;
	scanf("%lld %lld %lld %lld %lld", &l, &r, &x, &y, &k);
	for (j = x; j <= y; j++)
	{
		if (j*k >= l && j*k <= r)
		{
			printf("YES");
			return 0;
		}
	}
	printf("NO");

}