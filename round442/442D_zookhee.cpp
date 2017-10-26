#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
struct sg
{
	sg(int _a, int _b, int _c) { a = _a; b = _b; c = _c; }
	int a;
	int b;
	int c;
};
queue<sg> q;
int n, m,k,sx,sy,ex,ey,dis[1010][1010],dab=1000010,nextx,nexty;
int chk[1010][1010], dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 },curx,cury,cost;
char s[1010][1010];
int func(int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < m)
		return 1;
	else return 0;
}
int main()
{
	int i, j;
	scanf("%d %d %d", &n, &m, &k);
	for (i = 0; i < n; i++)
		scanf("%s", s[i]);
	scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
	sx--; sy--; ex--; ey--;
	q.push(sg(sx, sy, 0));
	fill(dis[0], dis[1001], 1000010);
	dis[sx][sy] = 0;
	while (!q.empty())
	{
		curx = q.front().a;
		cury = q.front().b;
		cost = dis[curx][cury];
		q.pop();
		if (chk[curx][cury]) continue;
		chk[curx][cury] = 1;
		if (curx == ex && cury == ey)
		{
			if (dab > cost)
				dab = cost;
		}
		for (i = 0; i <4; i++)
		{
			for (j = 1; j <= k; j++)
			{
				nextx = curx + dx[i] * j;
				nexty = cury + dy[i] * j;
				if (!func(nextx, nexty)) break;
				if (s[nextx][nexty] == '#') break;
				if (cost + 1 > dis[nextx][nexty]) break;
				if (!chk[nextx][nexty])
				{
					dis[nextx][nexty] = cost + 1;
					q.push(sg(nextx, nexty, cost + 1));
				}
			}
		}
	}
	if (dab == 1000010)
		printf("-1");
	else
		printf("%d", dab);
}