#include<stdio.h>
int n,g,st,ed,daba,dabb;
int main()
{
	int i,j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		j = n - i;
		if (i >= j) break;
		st = i;
		ed = j;
		while (ed != 0)
		{
			g = st%ed;
			st = ed;
			ed = g;
		}
		if (st == 1) {
			daba = i;
			dabb = j;
		}
	}
	printf("%d %d", daba, dabb);
}