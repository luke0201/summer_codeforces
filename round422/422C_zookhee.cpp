#include<stdio.h>
#include<algorithm>
#include<limits.h>
#include<vector>
using namespace std;
int n, m, st, ed,q,w,e,g,el,dab= 2010000000;
struct sg
{
	sg() {}
	sg(int _a, int _b, int _c) { a = _a; b = _b; c = _c; }
	int a;
	int b;
	int c;
}d[200010];
vector<sg> dat[200010];
bool mmm(const sg i, const sg j)
{
	return i.a < j.a;
}
int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d", &q, &w, &e);
		d[i] = sg(q, w, e);
		dat[w - q + 1].push_back(sg(q, w, e));
	}
	for (i = 1; i <= m; i++)
	{
		sort(dat[i].begin(), dat[i].end(), mmm);
		for (j = dat[i].size() - 2; j >= 0; j--)
		{
			dat[i][j].c = min(dat[i][j].c, dat[i][j + 1].c);
		}
	}
	for (i = 0; i < n; i++)
	{
		el = m - (d[i].b-d[i].a+1);
		if (el <= 0) continue;
		if (dat[el].size() == 0) continue;
		st = 0;
		ed = dat[el].size()-1;
		while (st <= ed)
		{
			g = (st + ed) / 2;
			if (dat[el][g].a > d[i].b)
				ed = g - 1;
			else
				st = g + 1;
		}
		if (st >= dat[el].size()) continue;
		if (dab > d[i].c + dat[el][st].c)
		{
			dab = d[i].c + dat[el][st].c;
		}

	}
	printf("%d", dab==2010000000 ? -1 : dab);
}