#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

const int N = 1000;

typedef vector<int> int_v;

int f[N];

bool same_roc(int, int, int, int);

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &f[i]);
    }

    for (int x0 = 0; x0 < 2; ++x0)
    {
        for (int x1 = x0 + 1; x1 < n; ++x1)
        {
            int_v not_same;
            for (int x = 0; x < n; ++x)
            {
                if (!same_roc(x0, x1, x0, x))
                {
                    not_same.push_back(x);
                }
            }
            if (not_same.empty()) continue;
            int x2 = *not_same.rbegin();

            bool all_second = true;
            not_same.pop_back();
            for (auto& x3 : not_same)
            {
                if (!same_roc(x0, x1, x2, x3))
                {
                    all_second = false;
                    break;
                }
            }
            if (not_same.empty() || all_second)
            {
                printf("Yes\n");
                exit(EXIT_SUCCESS);
            }
        }
    }
    printf("No\n");

    exit(EXIT_SUCCESS);
}

bool same_roc(int x00, int x01, int x10, int x11)
{
    return 1LL * (f[x01] - f[x00]) * (x11 - x10) == 1LL * (f[x11] - f[x10]) * (x01 - x00);
}
