#include<stdio.h>
int n, m,len,chk[30],use,u[30];
char s[1000010];
int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	scanf("%s", s);
	for (len = 0; s[len] != '\0'; len++)
	{
		chk[s[len] - 'A'] = len;
	}
	for (i = 0; i < len; i++)
	{
		if (u[s[i] - 'A'] == 0)
		{
			if (use < m)
			{
				use++;
				u[s[i] - 'A'] = 1;	
			}
			else
			{
				for (j = 0; j <= 'Z' - 'A'; j++)
				{
					if (j == s[i] - 'A') continue;
					if (u[j] == 1)
					{
						u[j] = 2;
						break;
					}
				}
				u[s[i] - 'A'] = 1;
			}
		}
		else if (u[s[i] - 'A'] == 2)
		{
			break;
		}
		if (chk[s[i] - 'A'] == i)
		{
			if (u[s[i]-'A'] == 1)
			{
				u[s[i] - 'A'] = 0;
				use--;
			}
		}
	}
	if (i == len)
		printf("NO");
	else
		printf("YES");
}