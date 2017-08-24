#include <cstdio>
#include <cstdlib>

using namespace std;

const int N = 100;
const int AB = 26;

char s[N + 1];

int cnt[AB];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", s);

    for (int i = 0; i < n; ++i)
    {
        ++cnt[s[i] - 'a'];
    }

    for (int i = 0; i < AB; ++i)
    {
        if (cnt[i] > k)
        {
            printf("NO\n");
            exit(EXIT_SUCCESS);
        }
    }
    printf("YES\n");

    exit(EXIT_SUCCESS);
}
