#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

const int N = 100000;

typedef vector<int> int_v;

int_v r[N + 1];

double prob[N + 1];
int dist[N + 1];

void calc_prob(int);

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

    prob[1] = 1.0;
    calc_prob(1);

    double sum = 0.0;
    for (int u = 2; u <= n; ++u)
    {
        if (r[u].size() == 1)
        {
            sum += prob[u] * dist[u];
        }
    }
    
    printf("%.8lf\n", sum);

    exit(EXIT_SUCCESS);
}

void calc_prob(int u)
{
    for (auto& v : r[u])
    {
        if (v == 1 || dist[v]) continue;
        dist[v] = dist[u] + 1;
        prob[v] = prob[u] / (r[u].size() - (u != 1));
        calc_prob(v);
    }
}