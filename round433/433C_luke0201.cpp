#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

const int N = 300000;

struct flight_t
{
    int i, cost;
    
    flight_t() = default;
    flight_t(const int& i, const int& cost) : i(i), cost(cost)
    {
    }

    bool operator <(const flight_t& that) const
    {
        return cost < that.cost;
    }
};

typedef priority_queue<flight_t> flight_min_pq;

int arr[N + 1];

int depart[N + 1];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    flight_min_pq min_heap;
    for (int i = 1; i <= k; ++i)
    {
        min_heap.emplace(i, arr[i]);
    }
    long long total_cost = 0LL;
    for (int j = k + 1; j <= n + k; ++j)
    {
        if (j <= n)
        {
            min_heap.emplace(j, arr[j]);
        }

        int i = min_heap.top().i, cost = min_heap.top().cost;
        min_heap.pop();
        total_cost += 1LL * (j - i) * cost;
        depart[i] = j;
    }

    printf("%lld\n", total_cost);
    for (int i = 1; i <= n; ++i)
    {
        printf("%d ", depart[i]);
    }
    printf("\n");

    exit(EXIT_SUCCESS);
}
