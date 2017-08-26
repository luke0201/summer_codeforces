#include<stdio.h>
double M = 1e-4;
int n, a, b, map[101][101],chk[101],deep[101];
void func(int v, double w)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		if (map[v][i] == 0 || chk[i] == 1) continue;
		chk[i] = 1;w += 2.0 / deep[v];
		if (w >= 2.0) w -= 2.0;
		if (w < 1.0)
		{
			printf("1 %d %d %d %.8lf\n", map[v][i], v, i, w);
		}
		else
		{
			printf("1 %d %d %d %.8lf\n", map[v][i], i, v, w - 1.0);
		}
		func(i, w + 1.0);
	}
}
int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n-1; i++)
	{
		scanf("%d %d", &a, &b);
		map[a][b] = i+1;
		map[b][a] = i+1;
		deep[a]++;
		deep[b]++;
	}
	chk[1] = 1;
	printf("%d\n", n - 1);
	func(1,M);
}