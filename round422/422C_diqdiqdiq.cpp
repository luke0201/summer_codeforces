#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<memory.h>
#include<queue>
#include<map>
#include<cstdlib>
#include<set>
#include<stack>
#include<iostream>
#include<climits>
using namespace std;
typedef pair<int, int> PA;
struct info{
    int l,r,c;
    info(){}
    info(int a, int b, int c):l(a),r(b),c(c){}
    bool operator<(const info& a)const
    {
        return l< a.l;
    }
};
info arr[200001];
vector<PA> v[200001];
int main()
{
    int n,x;
    scanf("%d %d", &n, &x);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d", &arr[i].l, &arr[i].r, &arr[i].c);
    }
    int ans = INT32_MAX;
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        int dur = arr[i].r-arr[i].l+1;
        v[dur].push_back(PA(arr[i].l,arr[i].c));
    }
    for(int i=0;i<200001;i++)
    {
        int size = v[i].size();
        for(int k = size-2;k>=0;k--)
        {
            v[i][k].second =min(v[i][k].second, v[i][k+1].second); 
        }
    }
    for(int i=0;i<n;i++)
    {
        int dur = arr[i].r-arr[i].l+1;
        if(dur>=x)continue;
        int remain = x-dur;
        int low=0;
        int high = v[remain].size()-1;
        int findV = arr[i].r+1;
        while(low<=high)
        {
            int mid = (low+ high)/2;
            if(v[remain][mid].first >= findV)
                high= mid-1;
            else
                low = mid+1; 
        }
        if(low < v[remain].size() && v[remain][low].first >=findV)
            ans = min(ans,arr[i].c + v[remain][low].second);
    }
    if(ans == INT32_MAX)
        printf("-1");
    else
    printf("%d", ans);
    return 0;
}