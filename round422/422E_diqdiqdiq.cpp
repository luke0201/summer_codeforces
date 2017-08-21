#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#define mod (1234567891)
#define mod2 (1000000007)
using namespace std;

int n,m,x;
char s[100001];
char t[100001];

unsigned long long hash_s[100002][2];
unsigned long long hash_t[100002][2];
int dp[100001][31];
unsigned long long mult[100001][2];
int getLcp(int ss, int ts)
{
	int l =0;
	int h =min(n-ss, m-ts);

	while(l<=h)
	{
		int mid = (l+h)/2;
		if(((hash_s[ss][0] - (hash_s[ss+mid][0]*mult[mid][0])%mod+mod)%mod == (hash_t[ts][0]-(hash_t[ts+mid][0]*mult[mid][0])%mod + mod)%mod )&& 
				( hash_s[ss][1] - (hash_s[ss+mid][1]*mult[mid][1])%mod2 + mod2)%mod2 == (hash_t[ts][1] - (hash_t[ts+mid][1]*mult[mid][1])%mod2 + mod2) %mod2)
		{
			l = mid+1;
		}
		else
			h = mid-1;
	}
	return h;
}
int main(void)
{
	scanf("%d %s %d %s %d", &n, s, &m, t, &x);
	for(int i = n-1;i>=0;i--)
	{
		hash_s[i][0] += ((hash_s[i+1][0]*31)+s[i]-'a')%mod;
		hash_s[i][1] += ((hash_s[i+1][1]*31)+s[i]-'a')%mod2;
	}
	for(int i = m-1;i>=0;i--)
	{
		hash_t[i][0] += ((hash_t[i+1][0]*31)+t[i]-'a')%mod;
		hash_t[i][1] += ((hash_t[i+1][1]*31)+t[i]-'a')%mod2;
	}
	mult[0][0] = 1;
	mult[0][1] = 1;
	for(int i=1;i<=100000;i++)
	{
		mult[i][0] = (mult[i-1][0]*31) %mod;
		mult[i][1] = (mult[i-1][1]*31) %mod2;
	}
	int cnt=0;
	memset(dp,-1,sizeof(dp));
	int maxV=0;
	dp[0][0]=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<x;j++)
		{
			if(dp[i][j]<0)continue;
			dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
			int lcp = getLcp(i, dp[i][j]);
			if(lcp>0)
				dp[i+lcp][j+1] = max(dp[i+lcp][j+1], dp[i][j]+lcp);
			maxV = max(maxV,dp[i+lcp][j+1]);
		}
	if(maxV == m)
		printf("YES");
	else
		printf("NO");
	return 0;
	
}