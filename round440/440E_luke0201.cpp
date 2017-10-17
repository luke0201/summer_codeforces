#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> int_v;

class Reduced_Indexs
{
    int_v idxs;
    int n;

public:
    Reduced_Indexs() = default;
    template <typename InputIterator>
    Reduced_Indexs(InputIterator first, InputIterator last)
    {
        idxs = int_v(first, last);

        sort(idxs.begin(), idxs.end());
        n = unique(idxs.begin(), idxs.end()) - idxs.begin();
        idxs.resize(n);
    }

    int size();
    int get_idx(int);
    int get_value(int);
};

int Reduced_Indexs::size()
{
    return n;
}

int Reduced_Indexs::get_idx(int x)
{
    auto p = lower_bound(idxs.begin(), idxs.end(), x);
    return (p != idxs.end() && *p == x) ? (p - idxs.begin()) : -1;
}

int Reduced_Indexs::get_value(int i)
{
    return idxs[i];
}

#include <cstdio>
#include <cstdlib>
#include <set>

const int N = 100000;
const long long MOD = 1000000007LL;

typedef set<int> int_set;

long long pow2[N + 2];

int xs[N], ys[N];
Reduced_Indexs xidxs, yidxs;
int_v xeq[N], yeq[N];

bool checked[N];
int_set xused, yused;
int cnt;

void check(int);

int main()
{
    pow2[0] = 1LL;
    for (int i = 1; i <= N + 1; ++i)
    {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }
    
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &xs[i], &ys[i]);
    }

    xidxs = Reduced_Indexs(xs, xs + n);
    yidxs = Reduced_Indexs(ys, ys + n);
    for (int i = 0; i < n; ++i)
    {
        xeq[xidxs.get_idx(xs[i])].push_back(i);
        yeq[yidxs.get_idx(ys[i])].push_back(i);
    }

    long long ans = 1LL;
    for (int i = 0; i < n; ++i)
    {
        xused.clear();
        yused.clear();
        cnt = 0;
        check(i);

        int total = xused.size() + yused.size();
        ans = (ans * (pow2[total] - (cnt < total))) % MOD;
    }

    printf("%lld\n", ans);

    exit(EXIT_SUCCESS);
}

void check(int u)
{
    if (checked[u])
    {
        return;
    }
    checked[u] = true;
    ++cnt;

    int x = xs[u], y = ys[u];
    if (!xused.count(x))
    {
        xused.insert(x);
        for (int v : xeq[xidxs.get_idx(x)])
        {
            check(v);
        }
    }
    if (!yused.count(y))
    {
        yused.insert(y);
        for (int v : yeq[yidxs.get_idx(y)])
        {
            check(v);
        }
    }
}
