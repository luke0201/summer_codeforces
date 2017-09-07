#include <stdio.h>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

vector <vector <int> >vec;
const int MAX = 100001;
bool chk[MAX];
int dist[MAX];
double p[MAX];

void dfs(int v) {
	chk[v] = true;
	for (int i = 0; i < vec[v].size(); i++) {
		int u = vec[v][i];
		if (chk[u])continue;
		dist[u] = dist[v] + 1;
		p[u] = p[v] / (vec[v].size() - (v != 1));
		dfs(u);
	}
	chk[v] = false;
}

int main() {
	int n;
	scanf("%d", &n);
	vec.resize(n + 1);
	for (int i = 0, a, b; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	p[1] = 1;
	dfs(1);
	double res = 0;
	for (int i = 2; i <= n; i++) {
		if (vec[i].size() == 1)res += dist[i] * p[i];
	}
	printf("%.7lf\n", res);
}