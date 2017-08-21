#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 1000;

int arr[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    int p = max_element(arr, arr + n) - arr, i;
    for (i = p - 1; i >= 0 && arr[i] == arr[i + 1]; --i);
    for (; i >= 0; --i)
    {
        if (arr[i] >= arr[i + 1])
        {
            printf("NO\n");
            exit(0);
        }
    }

    for (i = p + 1; i <= n && arr[i] == arr[i - 1]; ++i);
    for (; i <= n; ++i)
    {
        if (arr[i] >= arr[i - 1])
        {
            printf("NO\n");
            exit(0);
        }
    }

    printf("YES\n");

    exit(EXIT_SUCCESS);
}
