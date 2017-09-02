#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long 

const int MAX = 100003;
const ll MOD1 = 1234567891;
const ll MOD2 = 1000000007;
const ll B = 31;

char a[MAX], b[MAX];
ll hashA[2][MAX], hashB[2][MAX], mul[2][MAX];
int dp[31][MAX];

inline ll INT_MOD(ll v, ll mod) {
	return (v + mod) % mod;
}

inline ll CALC_HASH(ll hash[], ll mul[], ll mod, int l, int r) {
	return INT_MOD(hash[l] - INT_MOD(hash[r + 1] * mul[r - l + 1], mod), mod);
}

int main() {
	int n, m, x;
	scanf("%d %s", &n, a + 1);
	scanf("%d %s", &m, b + 1);
	scanf("%d", &x);

	mul[0][0] = mul[1][0] = 1;
	for (int i = 1; i <= n; i++) {
		mul[0][i] = INT_MOD(mul[0][i - 1] * B, MOD1);
		mul[1][i] = INT_MOD(mul[1][i - 1] * B, MOD2);
	}

	for (int i = n; i >= 1; i--) {
		hashA[0][i] = INT_MOD(hashA[0][i + 1] * B + a[i] - 'a' + 1, MOD1);
		hashA[1][i] = INT_MOD(hashA[1][i + 1] * B + a[i] - 'a' + 1, MOD2);
	}
	for (int i = m; i >= 1; i--) {
		hashB[0][i] = INT_MOD(hashB[0][i + 1] * B + b[i] - 'a' + 1, MOD1);
		hashB[1][i] = INT_MOD(hashB[1][i + 1] * B + b[i] - 'a' + 1, MOD2);
	}

	bool f = false;
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= n; j++) {
			if (dp[i][j] == m)f = true;
			dp[i][j + 1] = max(dp[i][j], dp[i][j + 1]);
			int l = 1, r = min(n - j, m - dp[i][j]);
			while (l <= r) {
				int mid = (l + r) / 2;
				ll a = CALC_HASH(hashA[0], mul[0], MOD1, j + 1, j + mid);
				ll b = CALC_HASH(hashB[0], mul[0], MOD1, dp[i][j] + 1, dp[i][j] + mid);
				ll c = CALC_HASH(hashA[1], mul[1], MOD2, j + 1, j + mid);
				ll d = CALC_HASH(hashB[1], mul[1], MOD2, dp[i][j] + 1, dp[i][j] + mid);

				if (a == b && c == d) { // equal
					l = mid + 1;
				}
				else {
					r = mid - 1;
				}
			}
			dp[i + 1][j + r] = max(dp[i + 1][j + r], dp[i][j] + r);
		}
	}


	if (f)printf("YES\n");
	else printf("NO\n");

}