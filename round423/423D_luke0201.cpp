#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    int height = ((n - k - 1) + (k - 1)) / k + 1;
    printf("%d\n", 2 * height - ((n - k - 1) % k == 1));
    for (int u = 2; u <= k + 1; u++)
    {
        printf("%d %d\n", 1, u);
    }
    for (int u = k + 2; u <= n; u++)
    {
        printf("%d %d\n", u - k, u);
    }

    exit(EXIT_SUCCESS);
}