#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 30;
const int L = 100000;

const long long EXP = 29LL;
const long long MOD1 = 402653189LL;
const long long MOD2 = 805306457LL;

typedef pair<long long, long long> iip;

char s1[L + 2], s2[L + 2];
int l1, l2;

long long exps1[L + 1], exps2[L + 1];
iip suf1[L + 2], suf2[L + 2];
int dp[N + 1][L + 1];

void calc_suf(iip*, char*, int);
iip get_hash(iip*, int, int);
long long pow_mod(long long, long long, long long);

int main()
{
    exps1[0] = exps2[0] = 1LL;
    for (int i = 1; i <= L; i++)
    {
        exps1[i] = (exps1[i - 1] * EXP) % MOD1;
        exps2[i] = (exps2[i - 1] * EXP) % MOD2;
    }

    int n;
    scanf("%d%s%d%s%d", &l1, s1 + 1, &l2, s2 + 1, &n);

    calc_suf(suf1, s1, l1);
    calc_suf(suf2, s2, l2);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < l1; j++)
        {
            dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);

            int left, right;
            for (left = 0, right = min(l1 - j, l2 - dp[i][j]); left < right; )
            {
                int mid = (left + right + 1) / 2;

                if (get_hash(suf1, j + 1, j + mid) != get_hash(suf2, dp[i][j] + 1, dp[i][j] + mid))
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid;
                }
            }
            int lcp = left;
            dp[i + 1][j + lcp] = max(dp[i + 1][j + lcp], dp[i][j] + lcp);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dp[i][l1] == l2)
        {
            printf("YES\n");
            exit(EXIT_SUCCESS);
        }
    }
    for (int j = l2; j <= l1; j++)
    {
        if (dp[n][j] == l2)
        {
            printf("YES\n");
            exit(EXIT_SUCCESS);
        }
    }
    printf("NO\n");

    exit(EXIT_SUCCESS);
}

void calc_suf(iip* hash, char* s, int l)
{
    hash[l] = make_pair(s[l] - 'a', s[l] - 'a');
    for (int i = l - 1; i >= 1; i--)
    {
        hash[i].first = (hash[i + 1].first * EXP + s[i] - 'a') % MOD1;
        hash[i].second = (hash[i + 1].second * EXP + s[i] - 'a') % MOD2;
    }
}

iip get_hash(iip* hash, int l, int r)
{
    return make_pair(
            (hash[l].first + MOD1 - (hash[r + 1].first * exps1[r - l + 1]) % MOD1) % MOD1,
            (hash[l].second + MOD2 - (hash[r + 1].second * exps2[r - l + 1]) % MOD2) % MOD2
            );
}
