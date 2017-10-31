#include <stdio.h>

int a[101];
int main() {
	int n, c = 0;
	bool f = false;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d", a + i);
	for (int i = 1; i < n; i++) {
		if (a[i] > a[i - 1]) {
			c |= (1 << 0);
			if (c & 6)f = true;
		}
		else if (a[i] == a[i - 1]) {
			c |= (1 << 1);
			if (c & 4)f = true;
		}
		else {
			c |= (1 << 2);
		}
	}
	if (f)printf("NO\n");
	else printf("YES\n");
}