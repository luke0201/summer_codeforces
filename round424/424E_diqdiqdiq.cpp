#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct bit{

	vector<int> tree;
	int size;
	bit(){
		tree.resize(100001);
		size = 100000;
	}
	int qsum(int idx)
	{
		int sum=0;
		while(idx>0)
		{
			sum+=tree[idx];
			idx -=(idx&-idx);
		}
		return sum;
	}
	void qupdate(int idx, int val)
	{
		while(idx<=size)
		{
			tree[idx] +=val;
			idx+=(idx&-idx);
		}
	}
};
vector<int> idx[100001];

int main(void)
{
	int n;
	bit b;
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		int t;
		b.qupdate(i,1);
		scanf("%d", &t);
		idx[t].push_back(i);
	}
	long long sum=0;
	int pre =0;
	for(int i=1;i<100001;i++)
	{
		if(idx[i].size()==0)continue;
		sort(idx[i].begin(), idx[i].end());
		int pos = lower_bound(idx[i].begin(), idx[i].end(), pre)-idx[i].begin();
		for(int j = pos; j<idx[i].size();j++)
		{
			sum+=b.qsum(idx[i][j]) - b.qsum(pre);
			b.qupdate(idx[i][j],-1);
			pre = idx[i][j];
		}
		if(pos != 0)
		{
			sum+= b.qsum(n)-b.qsum(pre);
			pre = 0;
		}
		for(int j=0; j<pos;j++)
		{
			sum+=b.qsum(idx[i][j]) - b.qsum(pre);
			b.qupdate(idx[i][j],-1);
			pre = idx[i][j];
		}
	}
	printf("%lld", sum);
	return 0;

}