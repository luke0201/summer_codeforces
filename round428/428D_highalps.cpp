#include <stdio.h>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

const int MAX = 1000000;
const ll MOD = (1e9) + 7;
int cnt[MAX + 1];
ll gcd[MAX + 1], B[MAX + 1];

int main() {
	int n, max = -1;
	scanf("%d", &n);
	for (int i = 0, v; i < n; i++) {
		scanf("%d", &v);
		cnt[v]++;
		max = v > max ? v : max;
	}
	B[0] = 1;
	for (int i = 1; i <= MAX; i++) {
		B[i] = (B[i - 1] * 2) % MOD;
	}

	for (int i = max; i >= 2; i--) {
		int c = 0;
		ll d = 0;
		for (int j = i; j <= max; j += i) {
			c += cnt[j];
			d = (d + gcd[j]);
		}
		gcd[i] = (c*B[c - 1] - d) % MOD;
	}

	ll res = 0;
	for (int i = 2; i <= max; i++) {
		res = (res + i*gcd[i]) % MOD;
	}
	printf("%I64d\n", res);

}