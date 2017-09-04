#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> vec[102];
vector <bool> chk(102, false);
int edge[102][102];

void dfs(int v, double g) {
	chk[v] = true;
	int size = vec[v].size();
	for (int i = 0; i < size; i++) {
		int u = vec[v][i];
		if (chk[u])continue;
		g += 2 / (double)size;
		if (g >= 2)g -= 2;
		if (g < 1) {
			printf("1 %d %d %d %.7lf\n", edge[v][u], v, u, g);
		}
		else {
			printf("1 %d %d %d %.7lf\n", edge[v][u], u, v, g - 1);
		}
		dfs(u, g + 1);
	}
	chk[v] = false;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0, a, b; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
		edge[a][b] = edge[b][a] = i + 1;
	}
	printf("%d\n", n - 1);
	dfs(1, 0.0);

}