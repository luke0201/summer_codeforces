#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n, p = -1,dat[100010], sum, cnt;
char s[100010];
int main()
{
	int i, j;
	scanf("%d", &n);
	scanf("%s",s);
	p = strlen(s)-1;
	for (i = 0; i <= p; i++)
	{
		dat[i] = s[i] - '0';
		sum += dat[i];
	}
	sort(dat, dat + p + 1);
	if (sum >= n)
		printf("0");
	else
	{
		for (i = 0; i <= p; i++)
		{
			if (sum >= n) break;
			sum += (9 - dat[i]); cnt++;
		}
		printf("%d", cnt);
	}
}