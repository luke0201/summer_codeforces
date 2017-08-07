#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N1 = 1000;
const int N2 = 2000;
const long long INF = 1000000000LL * N2;

int arr1[N1], arr2[N2];
int n1, n2, end_v;

long long dp[N1][N2];

long long get_dist(int, int);

int main()
{
    for (int i = 0; i < N1; ++i)
    {
        for (int j = 0; j < N2; ++j)
        {
            dp[i][j] = INF;
        }
    }

    scanf("%d%d%d", &n1, &n2, &end_v);
    for (int i = 0; i < n1; ++i)
    {
        scanf("%d", &arr1[i]);
    }
    sort(arr1, arr1 + n1);
    for (int i = 0; i < n2; ++i)
    {
        scanf("%d", &arr2[i]);
    }
    sort(arr2, arr2 + n2);

    dp[0][0] = get_dist(0, 0);
    for (int j = 1; j < n2; ++j)
    {
        dp[0][j] = min(dp[0][j - 1], get_dist(0, j));
    }
    for (int i = 1; i < n1; ++i)
    {
        for (int j = i; j < n2; ++j)
        {
            dp[i][j] = min(dp[i][j], min(dp[i][j - 1], max(dp[i - 1][j - 1], get_dist(i, j))));
        }
    }

    printf("%lld\n", dp[n1 - 1][n2 - 1]);

    exit(EXIT_SUCCESS);
}

long long get_dist(int u, int v)
{
    return abs(arr2[v] - arr1[u]) + abs(end_v - arr2[v]);
}
