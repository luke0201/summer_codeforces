#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, t, x, st, ed, g, dy[32][100010], dab = 0;
long long h1[100010], h2[100010], hs1[100010], hs2[100010];
long long tt[100010], tt2[100010];
char s[100010], s2[100010];
int main()
{
	int i, j, k;
	scanf("%d", &n);
	scanf("%s", s + 1);
	scanf("%d", &m);
	scanf("%s", s2 + 1);
	scanf("%d", &x);
	tt[0] = 1; tt2[0] = 1;
	for (i = 1; i <= n; i++)
	{
		tt[i] = tt[i - 1] * 31;
		tt[i] %= 1000000007;
		tt2[i] = tt2[i - 1] * 31;
		tt2[i] %= 1234567891;
	}
	for (i = n; i >= 1; i--)
	{
		h1[i] += h1[i + 1] * 31;
		h1[i] %= 1000000007;
		h1[i] += s[i] - 'a' + 1;
		h1[i] %= 1000000007;
		hs1[i] += hs1[i + 1] * 31;
		hs1[i] %= 1234567891;
		hs1[i] += s[i] - 'a' + 1;
		hs1[i] %= 1234567891;
	}
	for (i = m; i >= 1; i--)
	{
		h2[i] += h2[i + 1] * 31;
		h2[i] %= 1000000007;
		h2[i] += s2[i] - 'a' + 1;
		h2[i] %= 1000000007;
		hs2[i] += hs2[i + 1] * 31;
		hs2[i] %= 1234567891;
		hs2[i] += s2[i] - 'a' + 1;
		hs2[i] %= 1234567891;
	}
	for (i = 0; i <= x; i++)
	{
		for (j = 0; j <= n; j++)
		{
			dy[i][j + 1] = max(dy[i][j], dy[i][j + 1]);
			st = 1;
			ed = n - j;
			ed = min(ed, m - dy[i][j]);
			while (st <= ed)
			{
				g = (st + ed) / 2;
				long long q, w, e, r;
				t = tt[g];
				q = h1[j + 1] - (h1[j + g + 1] * t) % 1000000007;
				w = h2[dy[i][j] + 1] - (h2[dy[i][j] + g + 1] * t) % 1000000007;
				if (q < 0) q += 1000000007;
				if (w < 0) w += 1000000007;
				t = tt2[g];
				e = hs1[j + 1] - (hs1[j + g + 1] * t) % 1234567891;
				r = hs2[dy[i][j] + 1] - (hs2[dy[i][j] + g + 1] * t) % 1234567891;
				if (e < 0) e += 1234567891;
				if (r < 0) r += 1234567891;
				if ((q == w && e == r))
				{
					st = g + 1;
				}
				else
				{
					ed = g - 1;
				}
			}
			dy[i + 1][j + st - 1] = max(dy[i + 1][j + st - 1], dy[i][j] + st - 1);
			if (dy[i][j] == m) dab = 1;
		}
	}
	if (dab == 1)
		printf("YES");
	else
		printf("NO");
}