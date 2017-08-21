#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int n,m;

int arr[2001];
int b[2001];
set<int> ss;
int main()
{
	scanf("%d %d", &n, &m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d", &arr[i]);
		arr[i]+=arr[i-1];
	}
	for(int i=1;i<=m;i++)
		scanf("%d", &b[i]);
	sort(arr+1, arr+1+n);
	sort(b+1,b+1+m);
	
	for(int i=1;i<=n-m+1;i++)
	{
		int cnt=1;
		int k=1;
		for(int j=1;j<m;j++,k++)
		{
			if(i+k>n)break;
			if(arr[i+k]- arr[i] == b[j+1]-b[1])
				cnt++;
			else
				j--;
		}
		if(cnt ==m)
			ss.insert(arr[i]);
	}
	printf("%d", (int)ss.size());
	return 0;
}