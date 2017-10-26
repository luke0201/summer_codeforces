#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 262144;

typedef vector<int> int_v;

int_v r[N + 1];
int idx[N + 1], subsize[N + 1];

void dfs(int);

class Lazy_Segment_Tree
{
    int sum[2 * N];
    bool chk[2 * N];

public:
    template <typename InputIterator>
    Lazy_Segment_Tree(InputIterator first, InputIterator last)
    {
        fill(chk + 1, chk + 2 * N, false);
        fill(sum + 1, sum + 2 * N, 0);
        copy(first, last, sum + N);
        copy(first, last, chk + N);
        for (int i = N - 1; i >= 1; --i)
        {
            sum[i] = sum[i * 2] + sum[i * 2 + 1];
        }
    }

    void change(int, int, int=1, int=1, int=N);
    int get_sum(int, int, bool=false, int=1, int=1, int=N);
};

int arr[N + 1];

int main()
{
    int n;
    scanf("%d", &n);
    for (int v = 2; v <= n; ++v)
    {
        int u;
        scanf("%d", &u);
        r[u].push_back(v);
    }

    dfs(1);

    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &arr[idx[i]]);
    }
    Lazy_Segment_Tree segtree(arr + 1, arr + n + 1);

    int m;
    scanf("%d", &m);
    while (m--)
    {
        char oper[5];
        int u;
        scanf("%s%d", oper, &u);
        if (!strcmp(oper, "pow"))
        {
            segtree.change(idx[u], idx[u] + subsize[idx[u]] - 1);
        }
        if (!strcmp(oper, "get"))
        {
            printf("%d\n", segtree.get_sum(idx[u], idx[u] + subsize[idx[u]] - 1));
        }
    }

    exit(EXIT_SUCCESS);
}

void dfs(int u)
{
    static int cur = 1;

    idx[u] = cur++;
    subsize[idx[u]] = 1;
    for (int v : r[u])
    {
        dfs(v);
        subsize[idx[u]] += subsize[idx[v]];
    }
}

void Lazy_Segment_Tree::change(int left, int right, int p, int l, int r)
{
    if (l >= left && r <= right)
    {
        int n = r - l + 1;
        chk[p] ^= true;
        sum[p] = n - sum[p];
        for (int i = p / 2; i >= 1; i /= 2)
        {
            n *= 2;
            sum[i] = sum[i * 2] + sum[i * 2 + 1];
            if (chk[i])
            {
                sum[i] = n - sum[i];
            }
        }
        return;
    }

    int m = (l + r) / 2;
    if (m >= left)
    {
        change(left, right, p * 2, l, m);
    }
    if (m + 1 <= right)
    {
        change(left, right, p * 2 + 1, m + 1, r);
    }
}

int Lazy_Segment_Tree::get_sum(int left, int right, bool flag, int p, int l, int r)
{
    if (l >= left && r <= right)
    {
        int n = r - l + 1;
        return !flag ? sum[p] : (n - sum[p]);
    }

    int ret = 0;
    int m = (l + r) / 2;
    if (m >= left)
    {
        ret += get_sum(left, right, flag ^ chk[p], p * 2, l, m);
    }
    if (m + 1 <= right)
    {
        ret += get_sum(left, right, flag ^ chk[p], p * 2 + 1, m + 1, r);
    }
    return ret;
}
