#include <cstdio>
#include <cstdlib>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

const int N = 200000;
const long long INF = N * 1000000000LL;

struct edge_t
{
    int v;
    long long w;

    edge_t() = default;
    edge_t(int v, long long w) : v(v), w(w)
    {
    }
};

typedef vector<edge_t> edge_v;
typedef deque<int> int_dq;

edge_v r[N + 1], tmp[N + 1];
int_dq cycle;
int idx[N + 1];
long long cycle_dist[N + 1];
int n, n_cycle;

long long depth[N + 1], diam[N + 1];
long long dist[N + 1], dist2[N + 1];

long long pref_diam[N + 2], suff_diam[N + 2];
long long pref_far[N + 2], suff_far[N + 2];

bool find_cycle(int, int=-1);
void calc_diam(int);

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        r[u].emplace_back(v, w);
        r[v].emplace_back(u, w);
    }

    for (int start_v = 1; start_v <= n; ++start_v)
    {
        if (find_cycle(start_v)) break;
    }

    int cnt = 0;
    while (!cycle.empty())
    {
        ++n_cycle;
        int u = cycle.front();
        cycle.pop_front();
        idx[u] = ++cnt;
    }
    for (int u = 1; u <= n; ++u)
    {
        if (!idx[u])
        {
            idx[u] = ++cnt;
        }
    }

    for (int u = 1; u <= n; ++u)
    {
        for (auto& e : r[u])
        {
            int v = e.v;
            long long w = e.w;
            int _u = idx[u], _v = idx[v];
            tmp[_u].emplace_back(_v, w);

            if (_u <= n_cycle && _v == _u % n_cycle + 1)
            {
                cycle_dist[_u] = w;
            }
        }
    }
    for (int u = 1; u <= n; ++u)
    {
        r[u].clear();
        r[u].assign(tmp[u].begin(), tmp[u].end());
    }

    fill(dist + 1, dist + n + 1, -1);
    fill(dist2 + 1, dist2 + n + 1, -1);
    for (int u = 1; u <= n_cycle; ++u)
    {
        calc_diam(u);
    }

    pref_diam[1] = diam[1];
    pref_far[1] = depth[1];
    long long max_dist = depth[1];
    long long from_1 = 0LL;
    for (int u = 2; u <= n_cycle; ++u)
    {
        max_dist += cycle_dist[u - 1];
        from_1 += cycle_dist[u - 1];

        pref_diam[u] = max({pref_diam[u - 1], max_dist + depth[u], diam[u]});
        pref_far[u] = max(pref_far[u - 1], from_1 + depth[u]);
        max_dist = max(max_dist, depth[u]);
    }
    max_dist = depth[1];
    from_1 = 0LL;
    for (int u = n_cycle; u >= 2; --u)
    {
        max_dist += cycle_dist[u];
        from_1 += cycle_dist[u];

        suff_diam[u] = max({suff_diam[u + 1], max_dist + depth[u], diam[u]});
        suff_far[u] = max(suff_far[u + 1], from_1 + depth[u]);
        max_dist = max(max_dist, depth[u]);
    }
    suff_diam[n_cycle + 1] = suff_far[n_cycle + 1] = INF;

    long long answer = INF;
    for (int u = 1; u <= n_cycle; ++u)
    {
        answer = min(answer, max({pref_diam[u], suff_diam[u % n_cycle + 1], pref_far[u] + suff_far[u % n_cycle + 1]}));
    }

    printf("%lld\n", answer);
    
    exit(EXIT_SUCCESS);
}

bool visited[N + 1];
bool find_cycle(int u, int src)
{
    cycle.push_back(u);
    visited[u] = true;
    for (auto& e : r[u])
    {
        int v = e.v;
        if (v == src) continue;
        if (visited[v])
        {
            while (cycle.front() != v)
            {
                cycle.pop_front();
            }
            return true;
        }
        if (find_cycle(v, u))
        {
            return true;
        }
    }
    cycle.pop_back();
    return false;
}

void calc_dist(int, int, long long[N + 1]);
int max_v;
void calc_diam(int start_v)
{
    dist[start_v] = 0;
    max_v = start_v;
    calc_dist(start_v, start_v, dist);
    int far_v = max_v;
    depth[start_v] = dist[far_v];

    dist2[far_v] = 0;
    max_v = far_v;
    calc_dist(far_v, start_v, dist2);
    diam[start_v] = dist2[max_v];
}

void calc_dist(int u, int root, long long dist[N + 1])
{
    if (dist[max_v] < dist[u])
    {
        max_v = u;
    }
    
    for (auto& e : r[u])
    {
        int v = e.v;
        long long w = e.w;
        if ((v <= n_cycle && v != root) || dist[v] >= 0) continue;
        dist[v] = dist[u] + w;
        calc_dist(v, root, dist);
    }
}
