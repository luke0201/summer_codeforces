#include<stdio.h>
#include<string.h>
char s1[30], s2[30], t[1001],dab[1001];
int n, m, k,var[30];
int main()
{
	int i, j;
	scanf("%s %s %s", s1, s2, t);
	n = strlen(s1);
	for (i = 0; i < n; i++)
	{
		var[s1[i] - 'a'] = i;
	}
	k = strlen(t);
	for (i = 0; i < k; i++)
	{
		if (t[i] >= 'A' && t[i] <= 'Z')
		{
			dab[i] = s2[var[t[i] - 'A']] + 'A' - 'a';
		}
		else if (t[i] >= 'a' && t[i] <= 'z')
		{
			dab[i] = s2[var[t[i] - 'a']];
		}
		else
		{
			dab[i] = t[i];
		}
	}
	printf("%s", dab);
}