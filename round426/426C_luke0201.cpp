#include <cstdio>
#include <cstdlib>

using namespace std;

const long long INF = 1000000;

long long tripow(long long);

int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        long long a, b;
        scanf("%lld%lld", &a, &b);

        long long left, right, mid;
        for (left = 1LL, right = INF; left <= right; )
        {
            mid = (left + right) / 2LL;
            if (tripow(mid) > a * b)
            {
                right = mid - 1;
            }
            else if (tripow(mid) < a * b)
            {
                left = mid + 1;
            }
            else break;
        }

        printf("%s\n", (tripow(mid) == a * b && a % mid == 0 && b % mid == 0) ? "Yes" : "No");
    }

    exit(0);
}

long long tripow(long long x)
{
    return x * x * x;
}