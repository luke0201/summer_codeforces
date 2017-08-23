#include<stdio.h>
#include<vector>
using namespace std;
vector<int> d[100010];
int n, a, b,dis[100010];
double p[100010],dab;
void func(int v)
{
	int i;
	for (i = 0; i < d[v].size(); i++)
	{
		if (d[v][i] == 1 || dis[d[v][i]]!=0) continue;
		dis[d[v][i]] = dis[v] + 1;
		int g = (v != 1);
		p[d[v][i]] = p[v] / (d[v].size()-g);
		func(d[v][i]);
	}
}
int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &a, &b);
		d[a].push_back(b);
		d[b].push_back(a);
	}
	p[1] = 1;
	func(1);
	for (i = 2; i <= n; i++)
	{
		if(d[i].size()==1)dab += p[i] * dis[i];
	}
	printf("%lf", dab);
}