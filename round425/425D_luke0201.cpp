#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 131072;
const int NN = 2 * N;
const int INF = N;

typedef vector<int> int_v;

int_v r[N + 1];
int idx[N + 1];

class Segment_Tree
{
    int _arr[2 * NN];

public:
    Segment_Tree() = default;
    Segment_Tree(const int_v& arr)
    {
        copy(arr.begin(), arr.end(), _arr + NN);
        fill(_arr + NN + arr.size(), _arr + 2 * NN, INF);

        for (int i = NN - 1; i >= 1; --i)
        {
            _arr[i] = min(_arr[i * 2], _arr[i * 2 + 1]);
        }
    }

    int get_min(int, int, int=1, int=0, int=NN - 1);
};

class LCA
{
    Segment_Tree segtree;
    int_v trav;
    int occur[N + 1];

public:
    LCA()
    {
        fill(occur + 1, occur + N + 1, -1);
        _init(1);

        segtree = Segment_Tree(trav);
    }

    void _init(int);
    int get_lca(int, int);
    int get_is(int, int, int, int);
};

int dist[N + 1];

void dfs(int);

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int v = 2; v <= n; ++v)
    {
        int u;
        scanf("%d", &u);
        r[u].push_back(v);
    }

    idx[1] = 1;
    dfs(1);
    LCA lca;

    while (m--)
    {
        int vs[3];
        for (int i = 0; i < 3; ++i)
        {
            scanf("%d", &vs[i]);
            vs[i] = idx[vs[i]];
        }
        
        int ans = 1;
        for (int i = 0; i < 3; ++i)
        {
            int u = vs[i == 0], v = vs[2 - (i == 2)], w = vs[i];
            int pu = lca.get_lca(u, w), pv = lca.get_lca(v, w);
            ans = max(ans, lca.get_is(pu, u, pv, v) + lca.get_is(pu, u, pv, w) + lca.get_is(pu, w, pv, v) + lca.get_is(pu, w, pv, w) + 1);
        }

        printf("%d\n", ans);
    }

    exit(EXIT_SUCCESS);
}

int Segment_Tree::get_min(int left, int right, int p, int l, int r)
{
    if (l >= left && r <= right)
    {
        return _arr[p];
    }

    int mid = (l + r) / 2;
    int min_value = INF;
    if (mid >= left)
    {
        min_value = min(min_value, get_min(left, right, p * 2, l, mid));
    }
    if (mid + 1 <= right)
    {
        min_value = min(min_value, get_min(left, right, p * 2 + 1, mid + 1, r));
    }

    return min_value;
}

void LCA::_init(int u)
{
    occur[idx[u]] = trav.size();
    trav.push_back(idx[u]);
    
    for (int v : r[u])
    {
        _init(v);
        trav.push_back(idx[u]);
    }
}

int LCA::get_lca(int u, int v)
{
    if (occur[u] > occur[v])
    {
        swap(u, v);
    }
    return segtree.get_min(occur[u], occur[v]);
}

int LCA::get_is(int u1, int u2, int v1, int v2)
{
    return max(dist[get_lca(u2, v2)] - max(dist[u1], dist[v1]), 0);
}

void dfs(int u)
{
    static int cnt = 1;
    
    for (int v : r[u])
    {
        idx[v] = ++cnt;
        dist[idx[v]] = dist[idx[u]] + 1;
        dfs(v);
    }
}
