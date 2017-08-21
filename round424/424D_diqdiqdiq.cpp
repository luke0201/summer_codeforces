#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<string>
#include<cstdlib>
using namespace std;
int m[1001];
int key[2001];
int dp[1001][2001];
int main()
{
	int n,k,p;
	scanf("%d %d %d", &n, &k, &p);
	for(int i=0;i<n;i++)
		scanf("%d", &m[i]);
	for(int i=0;i<k;i++)
		scanf("%d", &key[i]);
	sort(m,m+n);
	sort(key,key+k);
	memset(dp,0x7f,sizeof(dp));
	for(int i=0;i<n;i++)
		for(int j=i;j<k;j++)
		{
			if(i==0)
			{
				if(j==0)
					dp[i][j] = abs(m[i]-key[j]) + abs(key[j] - p);
				else
				dp[i][j] = min(dp[i][j-1],abs(m[i]-key[j]) + abs(key[j] - p));
			}
			else
				dp[i][j] =max(dp[i-1][j-1], min(dp[i][j-1],abs(m[i]-key[j]) + abs(key[j] - p)));
		}
	printf("%d", dp[n-1][k-1]);
	
	return 0;
}