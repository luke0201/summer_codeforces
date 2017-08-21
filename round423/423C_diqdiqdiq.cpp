#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
typedef pair<int,int> PA;
typedef pair<pair<int,int>, int > PPA;
priority_queue<PPA> que[2000001];
string arr[100001];
int main()
{
    int n,k,x;
    int maxlen=0;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
         cin>>arr[i];
         int sz = arr[i].size()-1;
         scanf("%d", &k);
         for(int q=0;q<k;q++)
            {
                scanf("%d", &x);
                que[x-1].push(PPA(PA(sz,x),i));
            }
        maxlen = max(maxlen, x-1 +sz);
    }
    int idx=0;
    PPA prev(PA(-1,-2),-1);
    PPA cur(PA(-1,-2),-1);
    for(int i=0;i<=maxlen;i++)
    {
        if(!que[i].empty())
            {
                cur = que[i].top();
                if(cur.first.first +cur.first.second < prev.first.first+ prev.first.second)
                cur = prev;
                else
                {
                    prev = cur;
                    idx=0;
                }
            }
        if(cur.first.first==-1||idx>cur.first.first)printf("a");
        else
            printf("%c",arr[cur.second][idx++]);
    }
    
    return 0;
}