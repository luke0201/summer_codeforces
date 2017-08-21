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
vector<int> prevt[101];
vector<int> tree[101];
double valueC[101][101];
map<PA,int> mp;
bool visited[101];

void preDfs(int cur)
{
    for(int next: prevt[cur])
    {
        if(!visited[next])
        {
            visited[next] = true;
            tree[cur].push_back(next);
            preDfs(next);
        }
    }
}
void dfs(int cur, double point, bool isroot)
{
    int size = tree[cur].size();
    if(!isroot)size++;
    double add = 2.0/size;
    for(int next: tree[cur])
    {
        point+=add;
        if(point>=2.0)
            point-=2.0;   
        if(point>=1.0)
            printf("1 %d %d %d %.9lf\n", mp[PA(cur,next)], next, cur, point-1.0);
        else
            printf("1 %d %d %d %.9lf\n", mp[PA(cur,next)], cur, next, point);
        dfs(next, point+1, false);
    }
}
int main()
{
    int n;
    scanf("%d", &n);

    for(int i=1,a,b;i<n;i++){
        scanf("%d %d", &a, &b);
        prevt[a].push_back(b);
        prevt[b].push_back(a);
        mp[PA(a,b)] = i;
        mp[PA(b,a)] = i;
    }
    visited[1]= true;
    preDfs(1);
    printf("%d\n", n-1);
    dfs(1,0,true);
    return 0;
}