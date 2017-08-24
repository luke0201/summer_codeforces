#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    int cnt = 0;

    int n, a, b, c = 0;
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);

        switch (x)
        {
        case 1:
            if (a > 0)
            {
                --a;
            }
            else if (b > 0)
            {
                --b;
                ++c;
            }
            else if (c > 0)
            {
                --c;
            }
            else
            {
                ++cnt;
            }
            break;

        case 2:
            if (b > 0)
            {
                --b;
            }
            else
            {
                cnt += 2;
            }
            break;
        }
    }

    printf("%d\n", cnt);

    exit(EXIT_SUCCESS);
}