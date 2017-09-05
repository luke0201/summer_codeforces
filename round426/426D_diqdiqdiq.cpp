#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int,int> PA;
struct max_seg
{
	vector<int> seg;
	vector<int> lazy;
	max_seg(int n)
	{
		seg.resize(n+1);
		lazy.resize(n+1);
	}
	void lazy_pop(int idx, int s, int e)
	{
		if(lazy[idx] !=0)
		{
			seg[idx]+=lazy[idx];
			if(s!=e)
			{
				lazy[idx*2]+=lazy[idx];
				lazy[idx*2+1]+=lazy[idx];
			}
			lazy[idx]=0;
		}
	}
	void update(int idx, int s, int e, int l, int r, int val)
	{
		lazy_pop(idx,s,e);
		if(e<l || s>r)return;
		if(l<=s && e<=r)
		{
			seg[idx]+=val;
			if(s!=e)
			{
				lazy[idx*2]+=val;
				lazy[idx*2+1]+=val;
			}
			return;
		}
		int mid = (s+e)>>1;
		update(idx*2, s, mid, l, r, val);
		update(idx*2+1, mid+1, e, l, r, val);
		seg[idx] = max(seg[idx*2], seg[idx*2+1]);
		return;
	}
	void fill()
	{
		int size= seg.size();
		for(int i=0;i<size;i++)
			seg[i]=0,lazy[i]=0;
	}
};
int dp[51][350001];
int arr[350001];
int pos[350001];
int pre[350001];
int main(void)
{
	int n,k;
	scanf("%d %d", &n, &k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d", &arr[i]);
		pre[i] = pos[arr[i]];
		pos[arr[i]] = i;
	}
	int p;
	for(p=0;p<30;p++)
		if((1<<p) > n)
			break;
	max_seg seg(1<<(p+1));
	for(int i=1;i<=k;i++)
	{
		for(int j=i; j<=n;j++)
		{
			int p = pre[j];
			seg.update(1,0,n,p,j-1,1);
			seg.update(1,0,n,j-1,j-1,dp[i-1][j-1]);
			dp[i][j] = seg.seg[1];
		}
		seg.fill();
	}
	printf("%d", dp[k][n]);

	return 0;
}
