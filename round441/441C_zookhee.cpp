#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> dab;
int n,g=10,cnt;
int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = max(1, n - 101); i <= n; i++)
	{
		cnt = i;
		g = 10;
		while ((g/10)<=i)
		{
			cnt += i%g/(g/10);
			g *= 10;
		}
		if (cnt == n)
			dab.push_back(i);
	}
	printf("%d\n", dab.size());
	for (auto r : dab)
	{
		printf("%d\n", r);
	}
}