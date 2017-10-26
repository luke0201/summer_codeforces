#include <cstdio>
#include <cstdlib>
#include <set>

using namespace std;

const int N = 2000;

typedef set<int> int_set;

int arr1[N], arr2[N];
int_set arrs;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr1[i]);
        arrs.insert(arr1[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr2[i]);
        arrs.insert(arr2[i]);
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cnt += arrs.count(arr1[i] ^ arr2[j]);
        }
    }

    printf("%s\n", (cnt % 2 == 0) ? "Karen" : "Koyomi");

    exit(EXIT_SUCCESS);
}
