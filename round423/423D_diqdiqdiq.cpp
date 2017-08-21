#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

int main()
{
    int n,k;
    scanf("%d %d", &n, &k);
    printf("%d\n", (n-1)/k*2 + min(2,(n-1)%k));
    int cnt = (n-1)%k;
    for(int i=2;i<=k+1;i++)
        {
            printf("1 %d\n",i);
            int h=(n-1)/k -1;
            if(cnt>0)
            {
                h++;
                cnt--;
            }
                int pp=i;
                for(int p =0;p<h;p++,pp+=k)
                    printf("%d %d\n",pp,pp+k);
        }
    
    return 0;
}