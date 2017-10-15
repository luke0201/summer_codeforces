#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 5000;

int ret[N], ret2[N];
int ps[N], bs[N], ans[N];

int ask(int, int);

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        ret[i] = ask(0, i);
    }
    int y = find(ret, ret + n, 0) - ret;

    for (int i = 1; i < n; ++i)
    {
        ret2[i] = ask(i, y);
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            ps[j] = ret2[j] ^ i;
            bs[j] = ret[j] ^ i;
        }

        bool invalid = false;
        for (int j = 0; j < n; ++j)
        {
            if (ps[j] >= n || bs[j] >= n)
            {
                invalid = true;
                break;
            }
        }
        if (invalid) continue;

        bool consistent = true;
        for (int j = 0; j < n; ++j)
        {
            if (bs[ps[j]] != j)
            {
                consistent = false;
                break;
            }
        }
        if (consistent)
        {
            ++cnt;
            copy(ps, ps + n, ans);
        }
    }

    printf("!\n%d\n", cnt);
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");

    exit(EXIT_SUCCESS);
}

int ask(int a, int b)
{
    printf("? %d %d\n", a, b);
    fflush(stdout);
    
    int x;
    scanf("%d", &x);
    return x;
}
