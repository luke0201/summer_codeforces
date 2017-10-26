#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int L = 5000;

char s[L + 2];

int acnt[L + 1];

int main()
{
    scanf("%s", s + 1);
    int l = strlen(s + 1);

    for (int i = 1; i <= l; ++i)
    {
        acnt[i] = acnt[i - 1] + (s[i] == 'a');
    }

    int ans = 0;
    for (int i = 0; i <= l; ++i)
    {
        for (int j = i; j <= l; ++j)
        {
            int keep1 = acnt[i];
            int keep2 = (j - i) - (acnt[j] - acnt[i]);
            int keep3 = acnt[l] - acnt[j];
            ans = max(ans, keep1 + keep2 + keep3);
        }
    }

    printf("%d\n", ans);

    exit(EXIT_SUCCESS);
}
