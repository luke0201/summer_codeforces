#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, dat[1000],two,four,one;
bool mmm(int i, int j)
{
	return i > j;
}
int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
		scanf("%d", &dat[i]);
	two = n*2;
	four = n;
	sort(dat, dat + m, mmm);
	for (i = 0; i < m; i++)
	{
		while (dat[i] >= 4)
		{
			if (four != 0)
			{
				dat[i] -= 4;
				four--;
			}
			else
				break;
		}
	}
	for (i = 0; i < m; i++)
	{
		while (dat[i] >= 2)
		{
			if (two != 0)
			{
				dat[i] -= 2;
				two--;
			}
			else
			{
				if (four != 0)
				{
					dat[i] -= 2;
					four--;
					one++;
				}
				else
					break;
			}
		}
	}
	for (i = 0; i < m; i++)
	{
		while (dat[i] >= 1)
		{
			if (one != 0)
			{
				dat[i]--;
				one--;
			}
			else
			{
				if (two != 0)
				{
					dat[i]--;
					two--;
				}
				else
				{
					if (four != 0)
					{
						dat[i]--;
						four--;
						one++;
					}
					else
						break;
				}
			}
		}
	}
	for (i = 0; i < m; i++)
		if (dat[i] != 0)
			break;
	if (i == m)
		printf("YES");
	else
		printf("NO");
}