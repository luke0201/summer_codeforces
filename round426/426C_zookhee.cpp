#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n;
long long a, b, g, m,c,e;
double d;
int main()
{
	int i, j;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%lld %lld", &a, &b);
		c = a*b;
		d = cbrtl(c);
		e = d;
		if (a < b)
			swap(a, b);
		while (b != 0)
		{
			g = a%b;
			a = b;
			b = g;
		}
		if (e != d)
		{
			printf("No\n");
			continue;
		}
		else if (e == d)
		{
			if (a%e==0)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
}