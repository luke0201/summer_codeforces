#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;
#define MAXN (100010)
struct BIT{
	vector<int> tree;
	int size;
	BIT(){tree.assign(MAXN+1,0);size=MAXN;}

	int Qsum(int idx)
	{
		int s=0;
		while(idx>0)
		{
			s+=tree[idx];
			idx-=(idx&-idx);
		}
		return s;
	}
	void Update(int idx, int d)
	{
		while(idx<=MAXN)
		{
			tree[idx]+=d;
			idx+=(idx&-idx);
		}
	}
};
char arr[100001];
BIT b[4][11][11];
int n;
int ch(char a)
{
	if(a=='A')return 0;
	else if(a=='T')return 1;
	else if(a=='G')return 2;
	else return 3;
}
int q,w,e;
char str[11];
int main()
{
	scanf("%s %d", arr, &n);
	int len = strlen(arr);
	for(int i=0;i<len;i++)
	{
		int id= ch(arr[i]);
		for(int j=1;j<=10;j++)
		{
			b[id][(i+1)%j][j].Update(i+1,1);
		}
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d", &q);
		if(q==1)
		{
			scanf(" %d %s", &w, str);
			for(int i=1;i<=10;i++)
			{
				b[ch(arr[w-1])][w%i][i].Update(w,-1);
				b[ch(str[0])][w%i][i].Update(w,1);
			}
			arr[w-1] = str[0];
		}
		else
		{
			scanf(" %d %d %s", &w, &e, str);
			int len2= strlen(str);
			int s=0;
			for(int j=0; j<len2;j++)
			{
				s+=b[ch(str[j])][(w+j)%len2][len2].Qsum(e) - b[ch(str[j])][(w+j) % len2][len2].Qsum(w-1); 
			}
			printf("%d\n",s);
		}
	}
	
	return 0;
}