#include<stdio.h>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<memory.h>
using namespace std;
struct sg
{
	sg(long long _a, long long _b, long long _c) { num = _a; day = _b; cost = _c; }
	long long num;
	long long day;
	long long cost;

};
bool mmm(const sg i, const sg j)
{
	if (i.day != j.day)
		return i.day < j.day;
	else
		return i.cost < j.cost;
}
bool mmm2(const sg i, const sg j)
{
	if (i.day != j.day)
		return i.day > j.day;
	else
		return i.cost < j.cost;
}
const long long M=LLONG_MAX / 2;
vector<sg> to, back;
long long n, m, k,q,w,e,r,chk[100001],hap[1000010][2],hap2[1000010][2];
long long dab=M,cnt;
int main()
{
	long long i, j;
	scanf("%lld %lld %lld", &n, &m, &k);
	for (i = 0; i < m; i++)
	{
		scanf("%lld %lld %lld %lld", &q, &w, &e, &r);
		if (e == 0)
			to.push_back(sg(w,q, r));
		else if(w==0)
			back.push_back(sg(e,q, r));
	}
	sort(to.begin(), to.end(), mmm);
	sort(back.begin(), back.end(), mmm2);
	long long v=0,vv=0;
	for (i = 0; i < to.size(); i++)
	{
		if (hap[to[i].day][1] == 0) {
			hap[to[i].day][1] = v;
			hap[to[i].day][0] = vv;
		}
		if (chk[to[i].num] == 0)
		{
			hap[to[i].day][1]++;
			chk[to[i].num] = to[i].cost;
			hap[to[i].day][0] += to[i].cost;
		}
		else
		{
			if (to[i].cost < chk[to[i].num])
			{
				hap[to[i].day][0] -= chk[to[i].num];
				chk[to[i].num] = to[i].cost;
				hap[to[i].day][0] += to[i].cost;
			}
		}
		v = hap[to[i].day][1];
		vv = hap[to[i].day][0];
	}
	for (i = 1; i <= 1000000; i++)
	{
		if (hap[i][0] == 0 && hap[i][1] == 0)
		{
			hap[i][0] = hap[i - 1][0];
			hap[i][1] = hap[i-1][1];
		}
	}
	memset(chk, 0, sizeof chk);
	v = 0; vv = 0;
	for (i = 0; i < back.size(); i++)
	{
		if (hap2[back[i].day][1] == 0) {
			hap2[back[i].day][1] = v;
			hap2[back[i].day][0] = vv;
		}
		if (chk[back[i].num] == 0)
		{
			hap2[back[i].day][1]++;
			chk[back[i].num] = back[i].cost;
			hap2[back[i].day][0] += back[i].cost;
		}
		else
		{
			if (back[i].cost < chk[back[i].num])
			{
				hap2[back[i].day][0] -= chk[back[i].num];
				chk[back[i].num] = back[i].cost;
				hap2[back[i].day][0] += back[i].cost;
			}
		}
		v = hap2[back[i].day][1];
		vv = hap2[back[i].day][0];
	}
	for (i = 1000000; i >=1; i--)
	{
		if (hap2[i][0] == 0 && hap2[i][1] == 0)
		{
			hap2[i][0] = hap2[i + 1][0];
			hap2[i][1] = hap2[i+1][1];
		}
	}
	int g;
	for (i = 1; i <= 1000000; i++)
	{
		g = i + k+1;
		if (g > 1000000) break;
		if (hap[i][1] != n || hap2[g][1] != n) continue;
		cnt = hap[i][0] + hap2[g][0];
		if (dab > cnt) dab = cnt;
	}
	if (dab == M)
		printf("-1");
	else
		printf("%lld", dab);
}