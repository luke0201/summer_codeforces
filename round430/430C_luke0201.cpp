#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

const int N = 200000;

typedef vector<int> int_v;
typedef map<int, int> int_to_int;

int_v r[N + 1];
int value[N + 1];
int n;

int_to_int cnts;
int max_gcd[N + 1];
bool visited[N + 1];

int gcd(int, int);
void dfs(int, int);
void dfs2(int, int);

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &value[i]);
    }
    for (int i = 1; i <= n - 1; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        r[u].push_back(v);
        r[v].push_back(u);
    }

    for (int i = 1; i * i <= value[1]; ++i)
    {
        if (value[1] % i == 0)
        {
            cnts[i] = 0;
            if (i * i < value[1])
            {
                cnts[value[1] / i] = 0;
            }
        }
    }

    dfs(1, 1);

    fill(visited + 1, visited + n + 1, false);
    visited[1] = true;
    for (auto& v : r[1])
    {
        dfs2(v, 0);
    }

    for (int i = 1; i <= n; ++i)
    {
        printf("%d ", max_gcd[i]);
    }
    printf("\n");

    exit(EXIT_SUCCESS);
}

int gcd(int a, int b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

void dfs(int u, int lv)
{
    if (visited[u])
    {
        return;
    }
    visited[u] = true;

    for (auto& item : cnts)
    {
        int key = item.first;
        cnts[key] += (value[u] % key == 0);
        if (cnts[key] >= lv - 1)
        {
            max_gcd[u] = max(max_gcd[u], key);
        }
    }

    for (auto& v : r[u])
    {
        dfs(v, lv + 1);
    }

    for (auto& item : cnts)
    {
        int key = item.first;
        cnts[key] -= (value[u] % key == 0);
    }
}

void dfs2(int u, int gcd0)
{
    if (visited[u])
    {
        return;
    }
    visited[u] = true;
    gcd0 = gcd(gcd0, value[u]);
    max_gcd[u] = max(max_gcd[u], gcd0);

    for (auto& v : r[u])
    {
        dfs2(v, gcd0);
    }
}
