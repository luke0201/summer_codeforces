#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

const int N = 5000000;
const int MOD = 1000000007;

typedef vector<int> int_v;

int min_div[N + 1];
long long f[N + 1];

int main()
{
    int_v primes;
    for (int i = 2; i <= N / 2; i++)
    {
        bool is_prime = true;
        for (auto& j : primes)
        {
            if (j * j > i) break;
            if (i % j == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
        {
            primes.push_back(i);
        }
    }

    for (auto& p : primes)
    {
        for (int i = p; i <= N / p; i++)
        {
            if (!min_div[p * i])
            {
                min_div[p * i] = p;
            }
        }
    }
    for (int i = 2; i <= N; i++)
    {
        if (!min_div[i])
        {
            f[i] = 1LL * i * (i - 1) / 2;
        }
        else
        {
            int x = min_div[i], y = i / min_div[i];
            f[i] = min(x * f[y] + f[x], y * f[x] + f[y]);
        }
    }

    long long t;
    int l, r;
    scanf("%lld%d%d", &t, &l, &r);

    long long sum = 0LL;
    for (int i = r; i >= l; i--)
    {
        sum = ((t * sum) % MOD + f[i]) % MOD;
    }

    printf("%lld\n", sum);

    exit(EXIT_SUCCESS);
}
