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
char s[1001];
char t[1001];
int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    scanf(" %s %s", s,t);
    int minV=1001,minidx=0;
    for(int i=0;i<=m-n;i++)
        {
            int diff=0;
            for(int k=0;k<n;k++)
            {
                if(s[k] != t[i+k])
                    diff++;
            }
            if(diff < minV)
            {
                minV = diff, minidx =i;
            }
        }
    printf("%d\n", minV);
    for(int i=0;i<n;i++)
    {
        if(s[i] != t[minidx+i])
            printf("%d ",i+1);
    }
    return 0;
}