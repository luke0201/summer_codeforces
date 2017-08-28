#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 20;

int r[2 * N][2 * N];
int r1[N], r2[N], rb[N];

int dp[1 << N];

int count_bits(int);
int get_conn(int*, const int);

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int u = 0; u < n; ++u)
    {
        for (int v = 0; v < n; ++v)
        {
            scanf("%d", &r[u][v]);
        }
        r[u][u] = 1;
    }
    int n1 = n / 2;
    for (int u = 0; u < n1; ++u)
    {
        for (int v = 0; v < n1; ++v)
        {
            r1[u] |= r[u][v] << v;
        }
    }
    int n2 = n - n1;
    for (int u = n1; u < n; ++u)
    {
        for (int v = n1; v < n; ++v)
        {
            r2[u - n1] |= r[u][v] << (v - n1);
        }
    }
    for (int u = 0; u < n1; ++u)
    {
        for (int v = n1; v < n; ++v)
        {
            rb[u] |= r[u][v] << (v - n1);
        }
    }
    
    int max_clique = 1;
    for (int b = 1; b < (1 << n2); ++b)
    {
        if ((get_conn(r2, b) & b) == b)
        {
            dp[b] = count_bits(b);
            max_clique = max(max_clique, dp[b]);
        }
        else
        {
            for (int u = 0; u < n2; ++u)
            {
                if (b & (1 << u))
                {
                    dp[b] = max(dp[b], dp[b ^ (1 << u)]);
                }
            }
        }
    }

    for (int b = 1; b < (1 << n1); ++b)
    {
        if ((get_conn(r1, b) & b) == b)
        {
            int adj_r2 = get_conn(rb, b);
            max_clique = max(max_clique, count_bits(b) + dp[adj_r2]);
        }
    }

    printf("%.9lf\n", 0.5 * k * k * (max_clique - 1) / max_clique);

    exit(EXIT_SUCCESS);
}

int count_bits(int x)
{
    x = x - ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    return (((x + (x >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int get_conn(int* r, const int b)
{
    int conn = 0x7fffffff;;
    for (int i = 0; (1 << i) <= b; ++i)
    {
        if (b & (1 << i))
        {
            conn &= r[i];
        }
    }
    return conn;
}
