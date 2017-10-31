#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <initializer_list>
#include <algorithm>

using namespace std;

const int N = 300;
const long long INF = 1000000000LL;
const long long MOD = 1000000007LL;

typedef initializer_list<long long> ll_init;

int arr[N + 1];

long long binom[N + 1][N + 1];
long long facto[N + 1];

int cnt[N + 1];
long long dp[N], tmp[N];

long long modadd(long long, long long);
long long modmul(long long, long long);
long long modmul(ll_init);

bool is_perfect(long long);

int main()
{
    binom[0][0] = facto[0] = 1LL;
    for (int i = 1; i <= N; ++i)
    {
        binom[i][0] = binom[i][i] = 1LL;
        for (int j = 1; j <= N - 1; ++j)
        {
            binom[i][j] = modadd(binom[i - 1][j - 1], binom[i - 1][j]);
        }
        facto[i] = modmul(facto[i - 1], i);
    }

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i <= n; ++i)
    {
        int j;
        for (j = 1; j <= i && !is_perfect(1LL * arr[i] * arr[j]); ++j);
        ++cnt[j];
    }

    dp[cnt[1] - 1] = facto[cnt[1]];
    int holes = cnt[1] + 1;
    for (int i = 2; i <= n; ++i)
    {
        if (!cnt[i]) continue;

        for (int j = 0; j <= holes - 2; ++j)
        {
            if (!dp[j]) continue;

            for (int k = 1; k <= min(cnt[i], holes); ++k)
            {
                for (int l = k - min(holes - j, k); l <= min(j, k); ++l)
                {
                    int nextj = j - l + (cnt[i] - k);
                    tmp[nextj] = modadd(tmp[nextj], modmul({dp[j], facto[cnt[i]], binom[cnt[i] - 1][cnt[i] - k], binom[j][l], binom[holes - j][k - l]}));
                }
            }
        }
        
        holes += cnt[i];
        copy(tmp, tmp + n, dp);
        fill(tmp, tmp + n, 0);
    }
    
    printf("%lld\n", dp[0]);

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

long long modmul(ll_init arr)
{
    long long ret = 1LL;
    for (auto x : arr)
    {
        ret = modmul(ret, x);
    }
    return ret;
}

bool is_perfect(long long x)
{
    long long left, right;
    for (left = 1LL, right = min(x, INF); left < right; )
    {
        long long mid = (left + right + 1LL) / 2LL;
        if (mid * mid > x)
        {
            right = mid - 1;
        }
        else
        {
            left = mid;
        }
    }

    return left * left == x;
}
