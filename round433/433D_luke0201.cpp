#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

const int N = 100000;
const int M = 1000000;
const int INF = 1000001;

struct flight_t
{
    int date, idx, cost;
    
    flight_t() = default;
    flight_t(const int& date, const int& idx, const int& cost) : date(date), idx(idx), cost(cost)
    {
    }

    bool operator <(const flight_t& that) const
    {
        return date < that.date;
    }
    bool operator >(const flight_t& that) const
    {
        return date > that.date;
    }
};

typedef priority_queue<flight_t> flight_max_pq;
typedef priority_queue<flight_t, vector<flight_t>, greater<flight_t>> flight_min_pq;

flight_min_pq inflight;
flight_max_pq outflight;

int in_per[N + 1], out_per[N + 1];
long long min_in[M + 1], min_out[M + 1];

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    while (m--)
    {
        int date, u, v, cost;
        scanf("%d%d%d%d", &date, &u, &v, &cost);
        if (v == 0)
        {
            inflight.emplace(date, u, cost);
        }
        if (u == 0)
        {
            outflight.emplace(date, v, cost);
        }
    }

    fill(in_per + 1, in_per + N + 1, 0);
    fill(min_in + 1, min_in + M + 1, 1LL * N * INF);
    int cnt = 0;
    long long total_cost = 0LL;
    for (int i = 1; i <= M - k - 1; ++i)
    {
        while (!inflight.empty())
        {
            int date = inflight.top().date, u = inflight.top().idx, cost = inflight.top().cost;
            if (date > i) break;
            inflight.pop();

            if (!in_per[u])
            {
                ++cnt;
                total_cost += cost;
                in_per[u] = cost;
            }
            else if (in_per[u] > cost)
            {
                total_cost -= in_per[u] - cost;
                in_per[u] = cost;
            }
        }

        if (cnt == n)
        {
            min_in[i] = min(min_in[i], total_cost);
        }
    }

    fill(out_per + 1, out_per + N + 1, 0);
    fill(min_out + 1, min_out + M + 1, 1LL * N * INF);
    cnt = 0;
    total_cost = 0LL;
    for (int i = M; i >= k + 2; --i)
    {
        while (!outflight.empty())
        {
            int date = outflight.top().date, v = outflight.top().idx, cost = outflight.top().cost;
            if (date < i) break;
            outflight.pop();

            if (!out_per[v])
            {
                ++cnt;
                total_cost += cost;
                out_per[v] = cost;
            }
            else if (out_per[v] > cost)
            {
                total_cost -= out_per[v] - cost;
                out_per[v] = cost;
            }
        }

        if (cnt == n)
        {
            min_out[i] = min(min_out[i], total_cost);
        }
    }
    
    long long total_min = 2LL * N * INF;
    for (int i = 1; i <= M - k - 1; ++i)
    {
        if (min_in[i] == 1LL * N * INF || min_out[i + k + 1] == 1LL * N * INF) continue;
        total_min = min(total_min, min_in[i] + min_out[i + k + 1]);
    }

    printf("%lld\n", (total_min < 2LL * N * INF) ? total_min : -1);

    exit(EXIT_SUCCESS);
}
