#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define mp make_pair
#define f first
#define s second


const int MAX = 2 * 1e+5 + 1;
const int COST_MAX = 2 * 1e+9 + 2;
vector < pair <pair<int, int>, pair<int, int> > > vec;

int main() {
	int n, x;
	scanf("%d %d", &n, &x);
	for (int i = 0, l, r, c; i < n; i++) {
		scanf("%d %d %d", &l, &r, &c);
		vec.push_back(mp(mp(l, -1), mp(r, c)));
		vec.push_back(mp(mp(r, 1), mp(l, c)));
	}
	sort(vec.begin(), vec.end());

	int size = vec.size();
	ll ans = COST_MAX;
	vector <ll> dp(MAX, COST_MAX);
	for (int i = 0; i < size; i++) {
		if (vec[i].f.s == 1) { // r
			int len = vec[i].f.f - vec[i].s.f + 1;
			dp[len] = min(dp[len], (ll)vec[i].s.s);
		}
		else { // l
			int len = vec[i].s.f - vec[i].f.f + 1;
			if (len <= x) {
				ans = min(ans, dp[x - len] + vec[i].s.s);
			}
		}
	}
	printf("%I64d\n", ans >= COST_MAX ? -1 : ans);

}