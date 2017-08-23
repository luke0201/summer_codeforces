#include<stdio.h>
#include<algorithm>
using namespace std;
int n, k,a,b,c;
int main()
{
	int i, j;
	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		b += a;
		c += min(8, b);
		b -= min(8, b);
		if (c >= k)
		{
			printf("%d", i);
			break;
		}
	}
	if (i == n + 1)
		printf("-1");
}