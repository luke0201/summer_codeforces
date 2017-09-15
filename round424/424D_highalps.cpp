#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll long long

int a[1001], b[2002];
int main() {
	int n, k, p;
	scanf("%d %d %d", &n, &k, &p);
	for (int i = 0; i < n; i++)scanf("%d", &a[i]);
	for (int i = 0; i < k; i++)scanf("%d", &b[i]);
	sort(a, a + n);
	sort(b, b + k);
	ll ans = 1e11 + 1;
	for (int w = 0; w <= k - n; w++) {
		ll m = -1;
		for (int i = 0; i < n; i++) {
			m = max(m, (ll)abs(a[i] - b[i + w]) + (ll)abs(b[i + w] - p));
		}
		ans = min(ans, m);
	}
	printf("%lld\n", ans);
}