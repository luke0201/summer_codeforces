#include<stdio.h>
int n, m, c[30];
char s;
int main()
{
	int i;
	scanf("%d %d ", &n, &m);
	for (i = 0; i < n; i++)
	{
		scanf("%c", &s);
		c[s - 'a']++;
	}
	for (i = 0; i <= 'z' - 'a'; i++)
		if (c[i] >m) break;
	if (i == 'z' - 'a' + 1)
		printf("YES");
	else
		printf("NO");
}