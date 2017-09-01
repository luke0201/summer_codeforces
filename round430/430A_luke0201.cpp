#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    long long a1, a2, b1, b2, k;
    scanf("%lld%lld%lld%lld%lld", &a1, &a2, &b1, &b2, &k);
    
    for (long long b = b1; b <= b2; ++b)
    {
        if (k * b >= a1 && k * b <= a2)
        {
            printf("YES\n");
            exit(EXIT_SUCCESS);
        }
    }
    printf("NO\n");

    exit(EXIT_SUCCESS);
}
