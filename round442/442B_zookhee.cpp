#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
char s[5010];
int n,dab,sw,cnt,dy[5010][4];
int main()
{
	int i, j;
	scanf("%s", s);
	fill(dy[0], dy[5005], -100);
	n = strlen(s);
	if(s[0]=='a')dy[0][0] = 1;
	else dy[0][1] = 1;
	for (i = 1; i < n; i++)
	{
		if (s[i] == 'a')
			dy[i][0] = 1;
		else
			dy[i][1] = 1;
		for (j = 0; j < i; j++)
		{
			if (s[i] == 'a')
			{
				if (s[j] == 'a')
				{
					dy[i][0] = max(dy[i][0], dy[j][0] + 1);
					dy[i][2] = max(dy[i][2], dy[j][2] + 1);
				}
				else if (s[j] == 'b')
				{
					dy[i][2] = max(dy[i][2], dy[j][1] + 1);
				}
			}
			else
			{
				if (s[j] == 'a')
				{
					dy[i][1] = max(dy[i][1], dy[j][0] + 1);
				}
				else
				{
					dy[i][1] = max(dy[i][1], dy[j][1] + 1);
				}
			}
		}
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < 3; j++)
			if (dab < dy[i][j]) dab = dy[i][j];
	printf("%d", dab);
}