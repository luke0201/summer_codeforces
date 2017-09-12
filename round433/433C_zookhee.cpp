#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
struct sg
{
	sg(int _a, int _b) { a = _a; b = _b; }
	int a;
	int b;
};
struct compare
{
	bool operator() (const sg i, const sg j)
	{
		return i.a < j.a;
	}
};
priority_queue<sg,vector<sg>,compare> q;
int n, m, dat[300010],g,d[300010];
long long dab;
int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &dat[i]);
	}
	for (i = 0; i < m; i++)
	{
		q.push(sg(dat[i],i));
	}
	g = m;
	for (i = 0; i < n; i++,g++)
	{
		if (i +m <n)
			q.push(sg(dat[i+m],i+m));
		sg gab = q.top();
		q.pop();
		dab += 1LL* (long long)(g - gab.b) * (long long)(gab.a);
		d[gab.b] = g+1;
	}
	printf("%lld\n", dab);
	for (i = 0; i < n; i++)
		printf("%d ", d[i]);
}