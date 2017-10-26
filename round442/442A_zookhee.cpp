#include<stdio.h>
#include<string.h>
char s[110];
char d[5][10] = { "Danil","Olya","Slava","Ann","Nikita" };
int cnt;
int main()
{
	int i,j,k;
	scanf("%s", s); int len = strlen(s);
	for (i = 0; i<len; i++)
	{
		for (j = 0; j < 5; j++)
		{
			int n = strlen(d[j]);
			if (i + n > len) continue;
			for (k = i; k < i + n; k++)
			{
				if (s[k] != d[j][k-i])
					break;
			}
			if (k == i + n) cnt++;
		}
	}
	if (cnt == 1)
		printf("YES");
	else
		printf("NO");
}