#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 5000;
const long long MOD = 998244353LL;

int binom[N + 1][N + 1];
int facto[N + 1];

long long modadd(long long, long long);
long long modmul(long long, long long);

int main()
{
    binom[0][0] = facto[0] = 1;
    for (int i = 1; i <= N; ++i)
    {
        binom[i][0] = binom[i][i] = 1;
        for (int j = 1; j <= i - 1; ++j)
        {
            binom[i][j] = modadd(binom[i - 1][j - 1], binom[i - 1][j]);
        }
        facto[i] = modmul(facto[i - 1], i);
    }

    int arr[3];
    for (int i = 0; i < 3; ++i)
    {
        scanf("%d", &arr[i]);
    }

    long long ans = 1LL;
    for (int i = 0; i < 3; ++i)
    {
        int a = arr[i], b = arr[(i + 1) % 3];

        long long total = 0LL;
        for (int j = 0; j <= min(a, b); ++j)
        {
            total = modadd(total, modmul(modmul(binom[a][j], binom[b][j]), facto[j]));
        }

        ans = modmul(ans, total);
    }

    printf("%lld\n", ans);

    exit(EXIT_SUCCESS);
}

long long modadd(long long a, long long b)
{
    return (a + b) % MOD;
}

long long modmul(long long a, long long b)
{
    return (a * b) % MOD;
}
