#include<stdio.h>
#include<string.h>
char s[100010],dat[11],let;
int n, a, b, c,fw[5][11][11][100010],dab,le;
int func(char l)
{
	if (l == 'A') return 0;
	else if (l == 'T') return 1;
	else if (l == 'G') return 2;
	else if (l == 'C') return 3;
}
void update(int l,int var,int q,int w,int val)
{
	int g = var;
	while (g <= le)
	{
		fw[l][q][w][g] += val;
		g += (g&(-g));
	}
}
int main()
{
	int i, j,k;
	scanf("%s", s);
	scanf("%d", &n);
	le = strlen(s);
	for (i = 0; i < le; i++)
	{
		for (j = 1; j <= 10; j++)
		{
			update(func(s[i]),i+1, (i + 1) % j, j, 1);
		}
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (a == 1)
		{
			scanf("%d %c", &b, &let);
			for (j = 1; j <= 10; j++)
			{
				update(func(s[b-1]), b, b%j, j, -1);
				update(func(let),b,b%j,j, 1);
			}
			s[b - 1] = let;
		}
		else
		{
			scanf("%d %d %s", &b, &c, dat);
			int len = strlen(dat); dab = 0;
			for (j = 0; j < len; j++)
			{
				int g = c;
				while (g > 0)
				{
					dab += fw[func(dat[j])][(b + j) % len][len][g];
					g -= (g&(-g));
				}
				g = b - 1;
				while (g > 0)
				{
					dab -= fw[func(dat[j])][(b + j) % len][len][g];
					g -= (g&(-g));
				}
			}
			printf("%d\n", dab);
		}
	}
}