#include<stdio.h>
#include<algorithm>
using namespace std;
int n, a, b, c;
int main()
{
	int i, j;
	scanf("%d %d %d %d", &n, &a, &b, &c);
	if (n == 1)
		printf("0");
	else if (n == 2)
	{
		printf("%d", min(a, b));
	}
	else if (n >= 3)
	{
		printf("%d", min(a, b) + min(a, min(b, c))*(n-2));
	}
}