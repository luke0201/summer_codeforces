#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> d[200010],e;
int n, dat[200010], a, b,chk[200010],bea[200010];
int bea2[200010];
int mod(int a, int b)
{
	if (b == 0)
		return a;
	return mod(b, a%b);
}
void dfs(int v)
{
	chk[v] = 1;
	for (auto u : d[v])
	{
		if (chk[u] == 0)
		{
			bea[u] = mod(bea[v], dat[u]);
			dfs(u);
		}
	}
}
void dfs2(int v, int gab)
{
	int i, j,g;
	chk[v] = 1;
	for(i=0;i<e.size();i++)
	{
		g = e[i];
		bea2[i] += (dat[v] % g == 0);
		if (bea2[i] >= gab)
			bea[v] = max(bea[v], g);
	}
	for (auto g : d[v])
	{
		if (chk[g] == 0)
			dfs2(g, gab + 1);
	}
	for (i = 0; i < e.size(); i++)
	{
		g = e[i];
		bea2[i] -= (dat[v] % g == 0);
	}
}
int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &dat[i]);
	}
	for (i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &a, &b);
		d[a].push_back(b);
		d[b].push_back(a);
	}
	int temp = dat[1];
	dat[1] = 0;
	dfs(1);
	dat[1] = temp;
	memset(chk, 0, sizeof chk);
	for (i = 1; i*i <= dat[1]; i++)
	{
		if (dat[1] % i == 0)
		{
			e.push_back(i);
			if (i*i != dat[1]) e.push_back(dat[1] / i);
		}
	}
	sort(e.begin(), e.end());
	dfs2(1, 0);
	for (i = 1; i <= n; i++)
		printf("%d ", bea[i]);
}		