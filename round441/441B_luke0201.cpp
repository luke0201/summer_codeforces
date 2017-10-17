#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

typedef vector<int> int_v;

const int N = 100000;

int_v mods[N];

int main()
{
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        mods[x % m].push_back(x);
    }

    int p = -1;
    for (int i = 0; i < m; ++i)
    {
        if (mods[i].size() >= k)
        {
            p = i;
            break;
        }
    }
    
    if (p >= 0)
    {
        printf("Yes\n");
        for (int i = 0; i < k; ++i)
        {
            printf("%d ", mods[p][i]);
        }
        printf("\n");
    }
    else
    {
        printf("No\n");
    }

    exit(EXIT_SUCCESS);
}
