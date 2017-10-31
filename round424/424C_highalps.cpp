#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

#define ll long long

ll a[2002], b[2002];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		if (i) a[i] += a[i - 1];
	}
	for (int i = 0; i < k; i++) {
		scanf("%lld", &b[i]);
	}
	sort(a, a + n);
	sort(b, b + k);
	set <ll> S;
	int cnt = 0;
	for (int i = 0; i < n - k + 1; i++) {
		ll x = b[0] - a[i];
		int j = 1, c = 1;
		while (c < k && j < n) {
			if (x + a[j] == (ll)b[c]) {
				c++;
			}
			j++;
		}
		if (c == k) {
			S.insert(x);
		}
	}

	printf("%d\n", S.size());
}