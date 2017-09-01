#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 65536;
const int K = 50;

class Max_Segment_Tree
{
    int diff[4 * N];
    int max_arr[4 * N];

public:
    void add_interval(int, int, int, int=1, int=0, int=N - 1);
    int get_max(int, int, int=1, int=0, int=N - 1);

    void clear();
};

void Max_Segment_Tree::add_interval(int left, int right, int value, int p, int l, int r)
{
    if (l >= left && r <= right)
    {
        diff[p] += value;
        for (int i = p; i >= 1; i /= 2)
        {
            max_arr[i] = max(max_arr[i * 2], max_arr[i * 2 + 1]) + diff[i];
        }
        return;
    }

    int m = (l + r) / 2;
    if (m >= left)
    {
        add_interval(left, right, value, p * 2, l, m);
    }
    if (m + 1 <= right)
    {
        add_interval(left, right, value, p * 2 + 1, m + 1, r);
    }
}

int Max_Segment_Tree::get_max(int left, int right, int p, int l, int r)
{
    if (l >= left && r <= right)
    {
        return max_arr[p];
    }

    int max_value = 0;
    int m = (l + r) / 2;
    if (m >= left)
    {
        max_value = max(max_value, get_max(left, right, p * 2, l, m));
    }
    if (m + 1 <= right)
    {
        max_value = max(max_value, get_max(left, right, p * 2 + 1, m + 1, r));
    }
    
    return max_value;
}

void Max_Segment_Tree::clear()
{
    fill(diff, diff + 2 * N, 0);
    fill(max_arr, max_arr + 2 * N, 0);
}

int arr[N + 1];
int occur[N + 1], tmp[N + 1];

int dp[K + 1][N + 1];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i <= n; ++i)
    {
        occur[i] = tmp[arr[i]];
        tmp[arr[i]] = i;
    }

    Max_Segment_Tree segtree;
    for (int i = 1; i <= k; ++i)
    {
        segtree.clear();

        segtree.add_interval(i - 1, i - 1, i);
        dp[i][i] = i;
        for (int j = i + 1; j <= n; ++j)
        {
            segtree.add_interval(max(occur[j], i - 1), j - 1, 1);
            segtree.add_interval(j - 1, j - 1, dp[i - 1][j - 1]);
            dp[i][j] = segtree.get_max(i - 1, j - 1);
        }
    }

    printf("%d\n", dp[k][n]);

    exit(EXIT_SUCCESS);
}
