#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, g,a,b;
int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	printf("%d\n", ((n - 1) / m) * 2 + min(2, (n - 1) % m));
	g = (n - 1) / m;
	for (i = 2; i <= m+1; i++)
	{
		printf("1 %d\n", i);
		a = i;
		for (j = 0; j < g,a+m<=n; j++)
		{
			printf("%d %d\n", a, a + m);
			a += m;
		}
	}
}