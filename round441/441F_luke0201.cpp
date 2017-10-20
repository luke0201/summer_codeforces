#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

#define ROUND_POW2(n) ((__builtin_popcount(n) > 1) ? (1 << (32 - __builtin_clz(n))) : n)

using namespace std;

template <typename T>
class Max_Segment_Tree
{
    vector<T> _arr;
    int n;
    T inf;

public:
    template <typename InputIterator>
    Max_Segment_Tree(InputIterator first, InputIterator last, T inf) : inf(inf)
    {
        n = ROUND_POW2(last - first);
        _arr.resize(2 * n);

        copy(first, last, _arr.begin() + n);

        for (int i = n - 1; i >= 1; --i)
        {
            _arr[i] = max(_arr[i * 2], _arr[i * 2 + 1]);
        }
    }

    T get_max(int, int, int=1, int=0, int=-1) const;
    void change(int, T);
};

template <typename T>
T Max_Segment_Tree<T>::get_max(int left, int right, int p, int l, int r) const
{
    if (r == -1)
    {
        r = n - 1;
    }

    if (l >= left && r <= right)
    {
        return _arr[p];
    }

    int m = (l + r) / 2;
    T ret = inf;
    if (m >= left)
    {
        ret = max(ret, get_max(left, right, p * 2, l, m));
    }
    if (m + 1 <= right)
    {
        ret = max(ret, get_max(left, right, p * 2 + 1, m + 1, r));
    }
    return ret;
}

template <typename T>
void Max_Segment_Tree<T>::change(int p, T value)
{
    int i = n + p;
    _arr[i] = value;
    for (i /= 2; i >= 1; i /= 2)
    {
        _arr[i] = max(_arr[i * 2], _arr[i * 2 + 1]);
    }
}

const int N = 200000;
const int INF = 1000000000;
const int BITS = 30;

typedef pair<int, int> iip;

iip arr[N + 1];
int n;

int lcover[N + 2][BITS], rcover[N + 2][BITS];
int lnear[N + 2], rnear[N + 2];

long long ans;

void proc(int, int, const Max_Segment_Tree<iip>&);

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        arr[i] = make_pair(x, i);
    }

    fill(lcover[0], lcover[0] + BITS, 0);
    fill(rcover[n + 1], rcover[n + 1] + BITS, n + 1);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < BITS; ++j)
        {
            lcover[i][j] = ((arr[i].first & (1 << j)) ? i : lcover[i - 1][j]);
        }
    }
    for (int i = n; i >= 1; --i)
    {
        for (int j = 0; j < BITS; ++j)
        {
            rcover[i][j] = ((arr[i].first & (1 << j)) ? i : rcover[i + 1][j]);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        lnear[i] = 0;
        rnear[i] = n + 1;
        for (int j = 0; j < BITS; ++j)
        {
            if (lcover[i][j] < i)
            {
                lnear[i] = max(lnear[i], lcover[i][j]);
            }
            if (rcover[i][j] > i)
            {
                rnear[i] = min(rnear[i], rcover[i][j]);
            }
        }
    }

    Max_Segment_Tree<iip> segtree(arr + 1, arr + n + 1, make_pair(0, 0));

    proc(1, n, segtree);

    printf("%lld\n", ans);

    exit(EXIT_SUCCESS);
}

void proc(int left, int right, const Max_Segment_Tree<iip>& segtree)
{
    int mid = segtree.get_max(left - 1, right - 1).second;

    long long sum = 0LL;
    if (lnear[mid] >= left)
    {
        sum += (lnear[mid] - left + 1LL) * (right - mid + 1);
    }
    if (rnear[mid] <= right)
    {
        sum += (mid - left + 1LL) * (right - rnear[mid] + 1);
    }
    if (lnear[mid] >= left && rnear[mid] <= right)
    {
        sum -= (lnear[mid] - left + 1LL) * (right - rnear[mid] + 1LL);
    }
    ans += sum;

    if (mid > left)
    {
        proc(left, mid - 1, segtree);
    }
    if (mid < right)
    {
        proc(mid + 1, right, segtree);
    }
}
