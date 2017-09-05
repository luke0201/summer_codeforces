	#include<stdio.h>
#include<algorithm>
using namespace std;
int n,d[200010],dab[200010];
struct sg
	int a;
{
	int b;
}dat[200010];
bool mmm(const sg i, const sg j)
{
	return i.a < j.a;
}
bool mm(int i, int j)
{
	return i > j;
}
int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &d[i]);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &dat[i].a);
		dat[i].b = i;
	}
	sort(d, d + n, mm);
	sort(dat, dat + n, mmm);
	for (i = 0; i < n; i++)
	{
		dab[dat[i].b] = d[i];
	}
	for (i = 0; i < n; i++)
		printf("%d ", dab[i]);
}