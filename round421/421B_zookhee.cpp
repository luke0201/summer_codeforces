#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<vector>
using namespace std;
struct sg
{
	sg(double _a, double _b) { a = _a; b = _b; }
	double a;
	double b;
};

vector<sg> dat;
double a, b, c, d = 360;
int main()
{
	int i, j;
	scanf("%lf %lf", &a, &b);
	double g = (180 * (a - 2)) / a / (a - 2);
	for (j = 1; j <= a - 2; j++)
	{
		dat.push_back(sg(g*j, j));
	}
	for (i = 0; i < dat.size(); i++)
	{
		if (abs(dat[i].a - b) < d)
		{
			d = abs(dat[i].a - b);
			c = i;
		}
	}
	printf("%d %d %d", 2, 1, (int)dat[c].b + 2);
}