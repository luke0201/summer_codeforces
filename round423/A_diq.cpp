#include<cstdio>
using namespace std;
int main()
{
    int n,a,b;
    int ans=0;
    int seat21=0;
    scanf("%d %d %d", &n, &a, &b);
    for(int i=0,t;i<n;i++)
    {
        scanf("%d", &t);
        if(t==1)
        {
            if(a>0)a--;
            else if(b>0){
                b--;
                seat21++;
            }
            else if(seat21>0){
                seat21--;
            }
            else
            {
                ans++;
            }
        }
        else
        {
            if(b>0)
                b--;
            else
            ans+=2;
        }
    }
    printf("%d", ans);
    return 0;
}