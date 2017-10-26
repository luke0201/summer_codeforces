#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

struct edge_t
{
    int v, w;

    edge_t() = default;
    edge_t(int v, int w) : v(v), w(w)
    {
    }
};

class Graph
{
    vector<vector<edge_t>> r;

    int n;

public:
    Graph(int n) : n(n)
    {
        r.resize(n + 1);
    }

    int size() const;
    void add_edge(int, int, int);
    vector<edge_t> get_edges(int) const;
};

int Graph::size() const
{
    return n;
}

void Graph::add_edge(int u, int v, int w)
{
    r[u].emplace_back(v, w);
};

vector<edge_t> Graph::get_edges(int u) const
{
    return r[u];
}

const int N = 300000;
const int M = 300000;

typedef vector<int> int_v;

int d[N + 1];

int lv[N + 1];
bool visited[N + 1], used[M + 1];
int_v ans;

void construct_spanning_tree(int, const Graph&);
void dfs(int, const Graph&);

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int_v negs;
    bool mod = false;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &d[i]);
        if (d[i] == -1)
        {
            negs.push_back(i);
        }
        mod ^= (d[i] == 1);
    }
    if (negs.empty() && mod)
    {
        printf("-1\n");
    }
    else
    {
        for (int i : negs)
        {
            d[i] = mod;
            mod = false;
        }

        Graph graph(n);
        for (int i = 1; i <= m; ++i)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            graph.add_edge(u, v, i);
            graph.add_edge(v, u, i);
        }

        lv[1] = 1;
        construct_spanning_tree(1, graph);
        
        dfs(1, graph);

        printf("%d\n", (int)ans.size());
        for (int i : ans)
        {
            printf("%d\n", i);
        }
    }

    exit(EXIT_SUCCESS);
}

void construct_spanning_tree(int u, const Graph& graph)
{
    for (auto e : graph.get_edges(u))
    {
        int v = e.v;
        if (!lv[v])
        {
            lv[v] = lv[u] + 1;
            used[e.w] = true;
            construct_spanning_tree(v, graph);
        }
    }
}

void dfs(int u, const Graph& graph)
{
    int root = 1, idx = 0;
    for (auto e : graph.get_edges(u))
    {
        if (!used[e.w]) continue;
        int v = e.v;
        if (lv[v] < lv[u])
        {
            root = v;
            idx = e.w;
        }
        else
        {
            dfs(v, graph);
        }
    }
    if (d[u])
    {
        ans.push_back(idx);
        d[root] ^= 1;
    }
}
