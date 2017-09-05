#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<long long> d;
long long n,m,sum, dat[101],cnt,g,dab;
int main()
{
	long long i, j;
	scanf("%lld %lld", &n,&m);
	for (i = 0; i < n; i++)
	{
		scanf("%lld", &dat[i]); sum += dat[i];
		for (j = 1; j*j <= dat[i]; j++)
		{
			d.push_back(j);
			d.push_back(dat[i] / j + (dat[i] % j != 0));
		}
	}
	d.push_back(1e12);
	m += sum;
	sort(d.begin(), d.end());
	unique(d.begin(), d.end());
	for (i = 0; i < d.size(); i++)
	{
		if (d[i] > d[i + 1]) break;
		cnt = 0;
		for (j = 0; j < n; j++)
		{
			cnt += dat[j] / d[i] + (dat[j] % d[i] != 0);
		}
		g = m / cnt;
		if (d[i] <= g)
			dab = max(dab, g);
	}
	printf("%lld", dab);
}