#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int L = 5000;

char s[L + 2];

int dp[L + 1][L + 1];
int cnt[L + 1];

int main()
{
    scanf("%s", s + 1);
    int l = strlen(s + 1);

    for (int i = 1; i <= l; ++i)
    {
        dp[i][i] = 1;
        dp[i - 1][i] = 2 * (s[i - 1] == s[i]);
    }
    for (int d = 2; d < l; ++d)
    {
        for (int i = 1; i <= l - d; ++i)
        {
            int j = i + d;
            dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]) ? (dp[i][(i + j - 1) / 2] + 1) : 0;
        }
    }

    for (int i = 1; i <= l; ++i)
    {
        for (int j = i; j <= l; ++j)
        {
            ++cnt[dp[i][j]];
        }
    }
    for (int i = l - 1; i >= 1; --i)
    {
        cnt[i] += cnt[i + 1];
    }

    for (int i = 1; i <= l; ++i)
    {
        printf("%d ", cnt[i]);
    }
    printf("\n");

    exit(EXIT_SUCCESS);
}
