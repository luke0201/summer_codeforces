#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 1048576;

class Segment_Tree
{
    long long _arr[2 * N];

public:
    void add(int, int, long long, int=1, int=0, int=N - 1);
    int get_single_sum(int);
};

void Segment_Tree::add(int left, int right, long long value, int p, int l, int r)
{
    if (l >= left && r <= right)
    {
        _arr[p] += value;
        return;
    }

    int m = (l + r) / 2;
    if (m >= left)
    {
        add(left, right, value, p * 2, l, m);
    }
    if (m + 1 <= right)
    {
        add(left, right, value, p * 2 + 1, m + 1, r);
    }
}

int Segment_Tree::get_single_sum(int idx)
{
    int sum = 0;
    for (int i = N + idx; i >= 1; i >>= 1)
    {
        sum += _arr[i];
    }
    return sum;
}

Segment_Tree diffs;

int main()
{
    int n;
    scanf("%d", &n);
    long long offset = 0LL;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        offset += abs(x - i);
        if (i <= x)
        {
            if (i < x)
            {
                diffs.add(1, x - i, -1);
            }
            if (x < n)
            {
                diffs.add(x - i + 1, n - i, 1);
            }
            if (i > 1)
            {
                diffs.add(n - i + 1, n - i + 1, (x - 1) - (n - x));
                if (i > 2)
                {
                    diffs.add(n - i + 2, n - 1, -1);
                }
            }
        }
        else
        {
            if (i < n)
            {
                diffs.add(1, n - i, 1);
            }
            diffs.add(n - i + 1, n - i + 1, (x - 1) - (n - x));
            if (x > 1)
            {
                diffs.add(n - i + 2, n - i + x, -1);
            }
            if (x < i - 1)
            {
                diffs.add(n - i + x + 1, n - 1, 1);
            }
        }
    }

    long long min_dev = offset;
    int min_idx = 0;
    long long dev = offset;
    for (int i = 1; i <= n - 1; ++i)
    {
        dev += diffs.get_single_sum(i);
        if (min_dev > dev)
        {
            min_dev = dev;
            min_idx = i;
        }
    }

    printf("%lld %d\n", min_dev, min_idx);

    exit(EXIT_SUCCESS);
}
