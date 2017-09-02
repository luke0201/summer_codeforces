#include <stdio.h>


int main() {
	int a, b, res = 1;
	scanf("%d %d", &a, &b);
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
	while (a) {
		res *= a;
		a--;
	}

	printf("%d\n", res);
}