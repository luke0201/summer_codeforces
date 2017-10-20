#include <cstdio>
#include <cstdlib>
#include <string>
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

const int M = 100000;
const int N = 100000;
const int L = 100000;

typedef vector<int> int_v;

int_v arr[M];

bool changed[N + 1], checked[N + 1];

void capitalize(int, const Graph&);
void fix_word(int_v&);

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i)
    {
        int ni;
        scanf("%d", &ni);
        while (ni--)
        {
            int x;
            scanf("%d", &x);
            arr[i].push_back(x);
        }
    }

    Graph graph(n);
    for (int i = 1; i < m; ++i)
    {
        for (int j = 0; j < arr[i - 1].size(); ++j)
        {
            if (j >= arr[i].size())
            {
                printf("No\n");
                exit(EXIT_SUCCESS);
            }

            if (arr[i - 1][j] > arr[i][j])
            {
                changed[arr[i - 1][j]] = true;
                break;
            }
            if (arr[i - 1][j] < arr[i][j])
            {
                graph.add_edge(arr[i][j], arr[i - 1][j], 1);
                break;
            }
        }
    }

    for (int u = 1; u <= n; ++u)
    {
        if (changed[u])
        {
            capitalize(u, graph);
        }
    }

    fix_word(arr[0]);
    for (int i = 1; i < m; ++i)
    {
        fix_word(arr[i]);

        for (int j = 0; j < arr[i - 1].size(); ++j)
        {
            if (arr[i - 1][j] > arr[i][j])
            {
                printf("No\n");
                exit(EXIT_SUCCESS);
            }
            if (arr[i - 1][j] < arr[i][j]) break;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        cnt += checked[i];
    }

    printf("Yes\n%d\n", cnt);
    if (cnt > 0)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (checked[i])
            {
                printf("%d ", i);
            }
        }
        printf("\n");
    }

    exit(EXIT_SUCCESS);
}

void capitalize(int u, const Graph& graph)
{
    if (checked[u])
    {
        return;
    }
    checked[u] = true;

    for (auto e : graph.get_edges(u))
    {
        int v = e.v;
        if (!changed[v])
        {
            changed[v] = true;
            capitalize(v, graph);
        }
    }
}

void fix_word(int_v& word)
{
    for (int& x : word)
    {
        x -= (!changed[x] ? 0 : N);
    }
}
