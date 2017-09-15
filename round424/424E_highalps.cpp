#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

#define ll long long

int tree[100001], n;
vector <int> vec[100001];

void update(int idx) {
	while (idx <= n) {
		tree[idx]++;
		idx += (idx & -idx);
	}
}

int sum(int idx) {
	int s = 0;
	while (idx) {
		s += tree[idx];
		idx -= (idx & -idx);
	}
	return s;
}

int main() {
	ll res = 0;
	scanf("%d", &n);
	set <int> S;
	for (int i = 1, v; i <= n; i++) {
		scanf("%d", &v);
		vec[v].push_back(i);
		S.insert(v);
	}

	int pos = 1, idx = 0;
	bool flag = false;
	for (auto v : S) {
		flag = false;
		idx = 0;
		int size = vec[v].size();
		while (vec[v][idx] != -1) {
			if (!flag) {
				for (int i = 0; i < size; i++) {
					if (pos <= vec[v][i]) {
						idx = i;
						break;
					}
				}
			}
			int index = vec[v][idx];
			flag = true;
			if (index < pos) {
				res = res + (n - pos + 1) - (sum(n) - sum(pos - 1));
				res = res + (index - 1 + 1) - sum(index);
			}
			else res = res + (index - pos + 1) - (sum(index) - sum(pos - 1));
			update(index);
			pos = (index + 1) % (n + 1);
			if (!pos)pos++;
			vec[v][idx] = -1;
			idx = (idx + 1) % size;
		}
	}
	printf("%lld\n", res);
}