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
int main()
{
    int a,b;
    scanf("%d %d", &a, &b);
    int c = min(a,b);
    long long ans=1;
    for(int i=2;i<=c;i++)
        ans*=i;
    printf("%lld", ans);
    return 0;

}