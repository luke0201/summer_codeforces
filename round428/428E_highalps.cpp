#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int adj[42][42];
int dp[1 << 21];
int c1[42], c2[42], c3[43];

int count_bit(int b) {
	int c = 0;
	for (int i = b; i; i -= (i&-i))c++;
	return c;
}

int main() {
	int k, v, n1, n2, n, max_count = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &adj[i][j]);
		}
		adj[i][i] = 1;
	}
	n1 = n / 2;
	n2 = n - n1;
	for (int i = 0; i < n2; i++)dp[1 << i] = 1;
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n1; j++) {
			c1[i] |= (adj[i][j] << j);
		}
	}
	for (int i = n1; i < n; i++) {
		for (int j = n1; j < n; j++) {
			c2[i - n1] |= (adj[i][j] << (j - n1));
		}
	}
	for (int i = 0; i < n1; i++) {
		for (int j = n1; j < n; j++) {
			c3[i] |= (adj[i][j] << (j - n1));
		}
	}

	for (int i = 1; i < (1 << n2); i++) {
		int rb = (1 << 23) - 1;
		for (int j = 0; (1 << j) <= i; j++) {
			if (i&(1 << j)) {
				rb &= c2[j];
			}
		}
		if ((rb & i) == i) {
			int res = count_bit(i);
			dp[i] = res;
			max_count = max(max_count, res);
		}
		else {
			for (int j = 0; j < n2; j++) {
				dp[i] = max(dp[i], dp[i& ~(1 << j)]);
			}
		}
	}

	for (int i = 1; i < (1 << n1); i++) {
		int rb = (1 << 23) - 1;
		for (int j = 0; (1 << j) <= i; j++) {
			if (i&(1 << j)) {
				rb &= c1[j];
			}
		}
		if ((rb&i) == i) {
			int lb = (1 << 23) - 1;
			for (int j = 0; (1 << j) <= i; j++) {
				if (i & (1 << j)) {
					lb &= c3[j];
				}
			}
			int res = count_bit(i) + dp[lb];
			max_count = max(max_count, res);
		}
	}

	printf("%.7lf\n", k*k*(max_count - 1) / (2.0 * max_count));
}