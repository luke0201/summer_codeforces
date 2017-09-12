#include<stdio.h>
int a, b, c, d, e, g,cnt;
int spd;
int main()
{
	int i, j;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	g = b; cnt = 1;
	spd = b+d;
	if (spd > c) spd = c;
	while (g < a)
	{
		g -= e;
		g += spd;
		spd += d;
		if (spd > c) spd = c;
		cnt++;
	}
	printf("%d", cnt);
}