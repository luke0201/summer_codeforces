#include <stdio.h>

char a[1002], b[1002], c[1002];
int t[300];
int main() {
	scanf("%s %s %s", a, b, c);
	for (int i = 0; i < 26; i++) {
		t[a[i]] = b[i];
	}
	int diff = 'a' - 'A';
	for (int i = 0; c[i] != NULL; i++) {
		if ('A' <= c[i] && c[i] <= 'Z') {
			printf("%c", t[c[i] + diff] - diff);
		}
		else {
			if ('0' <= c[i] && c[i] <= '9')printf("%c", c[i]);
			else printf("%c", t[c[i]]);
		}
	}
}