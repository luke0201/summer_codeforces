#include <cstdio>
#include <cstdlib>

using namespace std;

const int N = 1000000;
const long long MOD = 1000000007LL;

int cnt[N + 1];

long long pow2[N + 1];
long long dp[N + 1];

int main()
{
    pow2[0] = 1LL;
    for (int i = 1; i <= N; ++i)
    {
        pow2[i] = (pow2[i - 1] << 1LL) % MOD;
    }

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        ++cnt[x];
    }

    for (int i = N; i >= 2; --i)
    {
        int ngroup = 0;
        long long duplicate = 0LL;
        for (int j = i; j <= N; j += i)
        {
            ngroup += cnt[j];
            duplicate = (duplicate + dp[j]) % MOD;
        }
        if (!ngroup) continue;
        dp[i] = (pow2[ngroup - 1] * ngroup + MOD - duplicate) % MOD;
    }

    long long total_cnt = 0LL;
    for (int i = 2; i <= N; ++i)
    {
        total_cnt = (total_cnt + dp[i] * i) % MOD;
    }
    printf("%lld\n", total_cnt);

    exit(EXIT_SUCCESS);
}
