#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 200000;
const int M = 200000;

struct query_t
{
    int idx;
    int x, y1, y2;
    
    query_t() = default;
    query_t(int idx, int x, int y1, int y2) : idx(idx), x(x), y1(y1), y2(y2)
    {
    }

    bool operator <(const query_t& that) const
    {
        return x < that.x;
    }
};

class Fenwick_Tree
{
    int _arr[N + 1];

public:
    Fenwick_Tree()
    {
        clear();
    }

    void add(int, int);
    int get_sum(int);
    int get_sum(int, int);

    void clear()
    {
        fill(_arr + 1, _arr + N + 1, 0);
    }
};

void Fenwick_Tree::add(int i, int value)
{
    for (; i <= N; i += (i & -i))
    {
        _arr[i] += value;
    }
}

int Fenwick_Tree::get_sum(int i)
{
    int sum = 0;
    for (; i > 0; i -= (i & -i))
    {
        sum += _arr[i];
    }
    return sum;
}

int Fenwick_Tree::get_sum(int u, int v)
{
    return get_sum(v) - get_sum(u - 1);
}

typedef vector<query_t> query_v;

int f[N + 2];
long long query[M + 1];

query_v leftq, rightq;

long long sq(long long);

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int x = 1; x <= n; ++x)
    {
        scanf("%d", &f[x]);
    }

    for (int i = 1; i <= m; ++i)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (x1 > x2)
        {
            swap(x1, x2);
        }
        if (y1 > y2)
        {
            swap(y1, y2);
        }

        query[i] = sq(x1 - 1) + sq(n - x2) + sq(y1 - 1) + sq(n - y2);
        if (x1 > 1)
        {
            leftq.emplace_back(i, x1 - 1, y1, y2);
        }
        if (x2 < n)
        {
            rightq.emplace_back(i, x2 + 1, y1, y2);
        }
    }
    sort(leftq.begin(), leftq.end());
    sort(rightq.begin(), rightq.end());
    reverse(rightq.begin(), rightq.end());

    Fenwick_Tree bitree;
    auto p = leftq.begin();
    for (int x = 1; x <= n - 1; ++x)
    {
        bitree.add(f[x], 1);
        for (; p != leftq.end(); ++p)
        {
            if (p->x > x) break;
            query[p->idx] -= sq(bitree.get_sum(1, p->y1 - 1)) + sq(bitree.get_sum(p->y2 + 1, n));
        }
    }

    bitree.clear();
    p = rightq.begin();
    for (int x = n; x >= 2; --x)
    {
        bitree.add(f[x], 1);
        for (; p != rightq.end(); ++p)
        {
            if (p->x < x) break;
            query[p->idx] -= sq(bitree.get_sum(1, p->y1 - 1)) + sq(bitree.get_sum(p->y2 + 1, n));
        }
    }

    for (int i = 1; i <= m; ++i)
    {
        printf("%lld\n", sq(n) - query[i]);
    }

    exit(EXIT_SUCCESS);
}

long long sq(long long x)
{
    return x * (x - 1LL) / 2LL;
}
