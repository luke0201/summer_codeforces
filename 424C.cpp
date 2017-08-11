#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
set<int> dab;
int n, m, dat[2010],datt[2010],cnt;
int main()
{
	int i, j,k;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &dat[i]);
		if (i != 0) dat[i] += dat[i - 1];
	}
	for (i = 0; i < m; i++)
		scanf("%d", &datt[i]);
	sort(dat, dat + n);
	sort(datt, datt + m);
	for (i = 0; i < n-m+1; i++)
	{
		k = 1; cnt = 1;
		for (j = 0; j < m-1; j++)
		{
			if (i + k > n) break;
			if (dat[i + k] - dat[i] == datt[j + 1] - datt[0])cnt++;
			else	j--;
			k++;
		}
		if (cnt == m)
			dab.insert(dat[i]);
	}
	printf("%d", dab.size());
}