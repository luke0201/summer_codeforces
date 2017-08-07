#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int arr[101];
vector<int> vec;
int main(void)
{
	int n;
	long long k;
	long long sum;
	scanf("%d %lld", &n, &k);
	sum=k;
	vec.push_back(1);
	for(int i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
		sum+=arr[i];
		vec.push_back(arr[i]);
		for(int j=2;j*j<=arr[i];j++)
		{
			if(arr[i]%j==0)
			{
				vec.push_back(j);
				vec.push_back(arr[i]/j);
			}
			else
			{
				vec.push_back(j);
				vec.push_back(arr[i]/j+1);
			}
		}
	}
	sort(vec.begin(),vec.end());
	vec.resize(unique(vec.begin(),vec.end())-vec.begin());
	int len = vec.size();
	long long ans = 0;
	for(int i=len-1;i>=0;i--)
	{
		long long llsum=0;
		for(int j=0;j<n;j++)
		{
			llsum+=(arr[j]/vec[i]);
			if(arr[j]%vec[i] !=0)
				llsum++;
		}
		long long d = sum/llsum;
		if(d>=vec[i])
		{		
			ans = max(ans,d);
		}
	}
	printf("%lld", ans);
	return 0;
}