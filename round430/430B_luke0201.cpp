#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    int r, d;
    scanf("%d%d", &r, &d);

    int n;
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        int x, y, ri;
        scanf("%d%d%d", &x, &y, &ri);

        bool out_of_main = (x * x + y * y >= (r - d + ri) * (r - d + ri));
        bool in_pizza = (x * x + y * y <= (r - ri) * (r - ri));
        cnt += (out_of_main && in_pizza);
    }

    printf("%d\n", cnt);

    exit(EXIT_SUCCESS);
}
