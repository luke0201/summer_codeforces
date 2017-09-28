#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100000;

typedef vector<int> int_v;

int_v r[N + 1];
int type[N + 1];

void set_type(int);

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        r[u].push_back(v);
        r[v].push_back(u);
    }

    type[1] = 1;
    set_type(1);

    int right_cnt = count(type + 1, type + n + 1, 2);
    long long ans = 0LL;
    for (int i = 1; i <= n; ++i)
    {
        if (type[i] == 1)
        {
            ans += right_cnt - r[i].size();
        }
    }

    printf("%lld\n", ans);

    exit(EXIT_SUCCESS);
}

void set_type(int u)
{
    for (auto& v : r[u])
    {
        if (type[v]) continue;
        type[v] = 3 - type[u];
        set_type(v);
    }
}
