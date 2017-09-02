#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

char a[1002], b[1002];
int main() {
	int n, m, res = -1;
	scanf("%d %d", &n, &m);
	scanf("%s", a);
	scanf("%s", b);
	vector <int> ans;
	for (int x = 0; x < m - n + 1; x++) {
		int cnt = 0;
		vector <int> t;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i + x]) {
				cnt++;
				t.push_back(i + 1);
			}
		}
		if (res == -1 || cnt < res) {
			res = cnt;
			ans = t;
		}
	}
	printf("%d\n", res);
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
}