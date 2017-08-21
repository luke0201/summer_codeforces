#include <cstdio>
#include <cstdlib>

using namespace std;

const int N = 100;
const double eps = 1e-4;

int r[N + 1][N + 1];
int n;

int deg[N + 1];
bool visited[N + 1];

void dfs(int u, double offset)
{
    for (int v = 1; v <= n; v++)
    {
        if (!r[u][v] || visited[v]) continue;
        visited[v] = true;

        offset += 2.0 / deg[u];
        if (offset >= 2.0)
        {
            offset -= 2.0;
        }

        if (offset < 1.0)
        {
            printf("1 %d %d %d %.8lf\n", r[u][v], u, v, offset);
        }
        else
        {
            printf("1 %d %d %d %.8lf\n", r[u][v], v, u, offset - 1.0);
        }

        dfs(v, offset + 1.0);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        r[u][v] = r[v][u] = i;

        deg[u]++;
        deg[v]++;
    }

    printf("%d\n", n - 1);

    visited[1] = true;
    dfs(1, eps);

    exit(EXIT_SUCCESS);
}
