#include<stdio.h>
int n, m, c,t,x1,x2,y1,y2,x,y,s,hap,cnt;
int fw[101][101][11],g;
void update(int x, int y, int val)
{
	g = y;
	while (g <= 100)
	{
		fw[x][g][val] ++;
		g += (g&(-g));
	}
}

int main()
{
	int i, j,k;
	scanf("%d %d %d", &n, &m, &c);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d", &x,&y,&s);
		update(x, y, s);
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d %d %d %d %d", &t, &x1, &y1, &x2, &y2);
		hap = 0; cnt = 0;
		for (j = x1; j <= x2; j++)
		{
			for (k = 0; k <= 10; k++)
			{
				g = y2;
				hap = 0;
				while (g > 0)
				{
					hap += fw[j][g][k];
					g -= (g&(-g));
				}
				g = y1 - 1;
				while (g > 0)
				{
					hap -= fw[j][g][k];
					g -= (g&(-g));
				}
				cnt += hap*((t + k) % (c + 1));
			}
		}
		printf("%d\n", cnt);
	}

}