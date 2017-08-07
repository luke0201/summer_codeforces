#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

const int L = 200000;
const long long INF = 2000000001LL;

struct voucher_t
{
    int u, v;
    int w;

    voucher_t() = default;
    voucher_t(int u, int v, int w) : u(u), v(v), w(w)
    {
    }

    bool operator <(const voucher_t& that) const
    {
        return u < that.u;
    }
};

struct query_t
{
    int u, v;
    int w;

    query_t() = default;
    query_t(int u, int v, int w) : u(u), v(v), w(w)
    {
    }

    bool operator <(const query_t& that) const
    {
        return v > that.v;
    }
};

typedef vector<voucher_t> voucher_v;
typedef priority_queue<query_t> min_pq;

long long cost[L + 1];

int main()
{
    fill(cost + 1, cost + L + 1, INF);
    voucher_v arr;

    int n, l;
    scanf("%d%d", &n, &l);
    for (int i = 1; i <= n; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        if (v - u + 1 >= l) continue;
        arr.emplace_back(u, v, w);
    }
    sort(arr.begin(), arr.end());

    long long min_cost = INF;
    min_pq min_heap;
    for (auto& e : arr)
    {
        while (!min_heap.empty())
        {
            int u = min_heap.top().u, v = min_heap.top().v, w = min_heap.top().w;
            if (v >= e.u) break;
            min_heap.pop();

            cost[v - u + 1] = min(cost[v - u + 1], 0LL + w);
        }

        min_cost = min(min_cost, cost[l - (e.v - e.u + 1)] + e.w);
        min_heap.emplace(e.u, e.v, e.w);
    }

    printf("%lld\n", (min_cost < INF) ? min_cost : -1);

    exit(EXIT_SUCCESS);
}
