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
#define base (1000000007)
typedef pair<int, int> PA;
long long dp[5000001];
int isprime[5000001];
void chkprime()
{
    for(int i=2;i*i<5000001;i++){
        if(isprime[i] ==i ){
            for(int j= i*i;j<5000001; j+=i)
                isprime[j]=min(isprime[j],i);
        }
    }
}
int main()
{
    long long t;
    int l,r;
    scanf(" %lld %d %d", &t, &l, &r);
    for(int i=1;i<5000001;i++)
        isprime[i]=i;
    chkprime();
    dp[1]=0;
    dp[2] =1;
    dp[3] =3;
    for(int i=4;i<5000001;i++)
    {
        dp[i]= (1LL*i*(i-1))/2;
        for(int x=i; x!=1; x/=isprime[x])
        {
            dp[i] = min(dp[i], (1LL* i* (isprime[x]-1))/2 + (1LL* dp[i/isprime[x]]));
        }
    }
     int ans = 0;
    int cnt = 1;
    for ( int j = l; j <= r; j++ ) {
        dp[j] %= base;
        ans = ( 1LL * ans + 1LL * cnt * dp[j] ) % base;
        cnt = ( 1LL * cnt * t ) % base;
    }
    printf ( "%d\n", ans );
    return 0;
}