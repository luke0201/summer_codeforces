#include<stdio.h>
#include<memory.h>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
vector<string> ss;
vector<int>dat[100010];
int n, m[100010],dlen,chk[2000100][2],len,c,g;
char s[1000100];
int main()
{
	int i, j;
	scanf("%d", &n);
	memset(chk, -1, sizeof chk);
	for (i = 0; i < n; i++)
	{
		scanf("%s", s); len = strlen(s);
		ss.push_back(string(s));
		scanf("%d", &m[i]);
		for (j = 0; j < m[i]; j++)
		{
			dat[i].push_back(0);
			scanf("%d", &dat[i][j]);
			if (dat[i][j] + len - 1 > dlen)
				dlen = dat[i][j] + len - 1;
			if (chk[dat[i][j]][1] < len) {
				chk[dat[i][j]][0] = i;
				chk[dat[i][j]][1] = len;
			}
		}

	}
	for (i = 1; i <= dlen; i++)
	{
		if (chk[i][0] == -1)
			printf("a");
		else
		{
			c = 0;
			printf("%c", ss[chk[i][0]].at(c));
			g = i; i++;
			for (;; i++)
			{
				if (i>dlen || chk[g][1]==i-g) break;
				if (chk[i][0] != -1)
				{
					if (i + chk[i][1] > g + chk[g][1])
						break;
				}
				printf("%c", ss[chk[g][0]].at(++c));
			}
			i--;
		}
	}
}