#include<vector>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define INF (1987654321)
struct ed{
	int u,v, cost,idx;
	ed(){}
	ed(int uu, int vv, int cc,int idx):u(uu), v(vv), cost(cc),idx(idx){}
	bool operator<(const ed& a)const{
		return cost < a.cost;
	}
};
struct edge{
	int next,cost;
	edge(){}
	edge(int a, int c):next(a),cost(c){}
};
struct node{
	int height;
	int par[23];
	int chainNum;
	int heavyNode;
	int segNum;
	int cost[23];
	int childcnt;
};
typedef pair<int,int> PA;
int n,m;
node info[200001];
int chainHead[200001];
vector<edge> adj[200001];
bool visited[200001];

void dfs(int cur,int height)
{
	int cnt=1;
	int maxV =0;
	int maxnode=0;
	for(auto& a: adj[cur])
	{
		if(!visited[a.next])
		{
			visited[a.next] = true;
			info[a.next].height= height+1;
			info[a.next].par[0] = cur;
			info[a.next].cost[0] = a.cost;
			dfs(a.next,height+1);
			if(info[a.next].childcnt > maxV)
			{
				maxV = info[a.next].childcnt;
				maxnode= a.next;
			}
			cnt+= info[a.next].childcnt;
		}
	}
	info[cur].heavyNode = maxnode;
	info[cur].childcnt=cnt;
	return;

}
void processLca(int n)
{
	for(int i=1;i<23;i++)
		for(int j=1;j<=n;j++)
		{
			info[j].par[i] = info[info[j].par[i-1]].par[i-1];
			info[j].cost[i] = max(info[info[j].par[i-1]].cost[i-1],info[j].cost[i-1]);
		}
}
vector<int> seg;
vector<int> lazy;
void lazy_update(int idx, int s, int e)
{
	if(lazy[idx] ==INF)return;
	if(lazy[idx] < seg[idx])
	{
		seg[idx] = lazy[idx];
		lazy[idx] =INF;
		if(s!=e)
		{
			lazy[idx*2] = min(lazy[idx*2], seg[idx]);
			lazy[idx*2+1] = min(lazy[idx*2+1],seg[idx]);
		}
	}
	return;
}
void seg_update(int idx, int s, int e, int l, int r, int val)
{
	lazy_update(idx,s,e);
	if(e<l || s>r)return;
	if(l<=s && e<=r)
	{
		seg[idx] = min(seg[idx],val);
		if(s!=e)
		{
			lazy[idx*2] = min(lazy[idx*2], val);
			lazy[idx*2+1] = min(lazy[idx*2+1],val);
		}
		return;
	}
	int mid = (s+e)/2;
	seg_update(idx*2, s, mid, l, r, val);
	seg_update(idx*2+1,mid+1,e,l,r,val);
	return;
}
int seg_min(int idx, int s, int e, int l, int r)
{
	lazy_update(idx,s,e);
	if(e<l || s>r)return INF;
	if(l<=s && e <=r)return seg[idx];
	int mid = (s+e)>>1;
	int a = seg_min(idx*2,s,mid,l,r);
	int b = seg_min(idx*2+1,mid+1,e,l,r);
	return min(a,b);
}
int chainCnt=1;
int segcnt=1;
int NodeNum[200001];
void HLD(int cur)
{
	NodeNum[segcnt] = cur;
	info[cur].segNum = segcnt++;
	info[cur].chainNum = chainCnt;
	if(info[cur].heavyNode !=0)
	{
		visited[info[cur].heavyNode] = true;
		HLD(info[cur].heavyNode);
	}
	for(auto& a : adj[cur])
	{
		if(!visited[a.next])
		{
			visited[a.next] = true;
			chainCnt++;
			chainHead[chainCnt] = a.next;
			HLD(a.next);
		}
	}
	return;
}
int getLca(int a, int b)
{
	int ha = info[a].height;
	int hb = info[b].height;
	if(ha!=hb)
	{
		int cha;
		if(ha > hb)
		{
			swap(hb,ha);
			swap(a,b);
		}
		cha = hb-ha;
		for(int i=22;i>=0;i--)
		{
			if(cha&(1<<i))
			{
				b = info[b].par[i];
			}
		}
	}
	if(a == b)
		return a;
	else
	{
		for(int i=22;i>=0;i--)
		{
			if(info[a].par[i] != info[b].par[i])
				a = info[a].par[i], b= info[b].par[i];
		}
	}
	return info[a].par[0];
	
}
int getMax(int lca, int b)
{
	int hlc = info[lca].height;
	int hb = info[b].height;
	int cha = hb-hlc;
	int maxV =0;
	for(int i=23;i>=0;i--)
	{
		if(cha&(1<<i))
		{
			maxV = max(maxV, info[b].cost[i]);
			b= info[b].par[i];
		}
	}
	return maxV;
}
void update(int lca, int b,int v)
{
	while(info[lca].chainNum != info[b].chainNum)
	{
		seg_update(1,1,n,info[chainHead[info[b].chainNum]].segNum, info[b].segNum,v);
		b = info[chainHead[info[b].chainNum]].par[0];
	}
	if(b== lca)return;
	seg_update(1,1,n, info[lca].segNum+1, info[b].segNum,v);
}
int getMin(int a)
{
	return seg_min(1,1,n,info[a].segNum,info[a].segNum);
}
ed edL[200001];
int par[200001];
int rr[200001];
bool inMst[200001];
int find(int a)
{
	if(par[a] ==a)return a;
	return par[a] = find(par[a]);
}
void merge(int a, int b)
{
	int pa =find(a);
	int pb =find(b);

	if(rr[pa] > rr[pb])
		swap(pa,pb);
	par[pa] = pb;
	if(rr[pa] == rr[pb])
		rr[pb]++;
}
void MakeKruscal()
{
	for(int i=0;i<m;i++)
	{
		if(find(edL[i].u) == find(edL[i].v))
			inMst[edL[i].idx]=false;
		else
		{
			inMst[edL[i].idx] = true;
			merge(edL[i].u, edL[i].v);
			adj[edL[i].u].push_back(edge(edL[i].v, edL[i].cost));
			adj[edL[i].v].push_back(edge(edL[i].u, edL[i].cost));
		}
	}
}
int ans[200001];
int main(void)
{
	scanf("%d %d", &n, &m);
	for(int i=0,a,b,c;i<m;i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		edL[i] = ed(a,b,c,i);
	}
	sort(edL,edL+m);
	for(int i=1;i<=n;i++ )
		par[i]=i;
	MakeKruscal();

	visited[1] = true;
	info[1].height = 1;

	dfs(1,1);
	processLca(n);
	memset(visited,false,sizeof(visited));
	visited[1] = true;
	chainHead[chainCnt]=1;
	HLD(1);
	seg.resize(533333,INF);
	lazy.resize(533333,INF);
	for(int i=0;i<m;i++)
	{
		if(!inMst[edL[i].idx])
		{
			int lc = getLca(edL[i].u, edL[i].v);
			ans[edL[i].idx] = max(getMax(lc,edL[i].u), getMax(lc, edL[i].v));
			update(lc,edL[i].u,edL[i].cost);
			update(lc,edL[i].v, edL[i].cost);
		}
	}
	for(int i=0;i<m;i++)
	{
		if(inMst[edL[i].idx])
		{	
			if(info[edL[i].u].par[0] == edL[i].v)
				ans[edL[i].idx] = getMin(edL[i].u);
			else
				ans[edL[i].idx] = getMin(edL[i].v);
		}
	}
	for(int i=0;i<m;i++)
	{
		if(ans[i]==INF)
			printf("-1 ");
		else
			printf("%d ",ans[i]-1);
	}
	return 0;
}