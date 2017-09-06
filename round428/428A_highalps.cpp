#include <stdio.h>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
	int f = -1;
	int n, k, s = 0, t = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0, v; i < n; i++) {
		scanf("%d", &v);
		t += v;
		s += min(t, 8);
		t -= min(t, 8);
		if (s >= k && f == -1) {
			f = i + 1;
		}
	}
	printf("%d\n", f);

}