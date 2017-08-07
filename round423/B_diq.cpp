#include<cstdio>
#include<algorithm>
using namespace std;
char arr[101][101];
int main()
{
    int n,m;
    int minX=101,maxX=-1,minY=101,maxY=-1;
    int cnt=0;
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            {
                scanf(" %c", &arr[i][j]);
                if(arr[i][j] =='B')
                {
                    minX = min(minX,j);
                    maxX = max(maxX,j);
                    minY = min(minY,i);
                    maxY = max(maxY,i);
                    cnt++;
                }
            }
    int w = maxX-minX+1;
    int h = maxY-minY+1;
    if(cnt==0)
        printf("1");
    else if(max(w,h) > n || max(w,h) >m)
        printf("-1");
    else
        printf("%d",max(w,h)*max(w,h)-cnt);
    
    return 0;
}