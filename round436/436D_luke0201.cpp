#include <cstdio>
#include <cstdlib>

using namespace std;

const int N = 200000;

int arr[N + 1];
int cnts[N + 1];

bool flag[N + 1];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &arr[i]);
        ++cnts[arr[i]];
    }

    int cur = 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (cnts[arr[i]] > 1)
        {
            for (; cnts[cur] > 0; ++cur);

            if (arr[i] < cur && !flag[arr[i]])
            {
                flag[arr[i]] = true;
            }
            else
            {
                --cnts[arr[i]];
                ++cnts[cur];
                arr[i] = cur;
                ++ans;
            }
        }
    }

    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    exit(EXIT_SUCCESS);
}
