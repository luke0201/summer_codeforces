#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 1000;
const int M = 5;

struct coord_t
{
    int coord[M];

    coord_t() = default;

    coord_t operator -(const coord_t& that) const
    {
        coord_t ret;
        for (int k = 0; k < M; ++k)
        {
            ret.coord[k] = this->coord[k] - that.coord[k];
        }
        return ret;
    }

    int& operator [](const int& idx)
    {
        return coord[idx];
    }
    int operator [](const int& idx) const
    {
        return coord[idx];
    }

    int get_sqnorm()
    {
        int sum = 0;
        for (int k = 0; k < M; ++k)
        {
            sum += coord[k] * coord[k];
        }
        return sum;
    }
};

coord_t coords[N];

int dot_product(const coord_t&, const coord_t&);

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        for (int k = 0; k < M; ++k)
        {
            scanf("%d", &coords[i][k]);
        }
    }
    if (n <= 2)
    {
        printf("%d\n", n);
        for (int i = 1; i <= n; ++i)
        {
            printf("%d\n", i);
        }
        exit(EXIT_SUCCESS);
    }

    int min_sqdist = (coords[0] - coords[1]).get_sqnorm(), u = 0, v = 1;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int sqdist = (coords[i] - coords[j]).get_sqnorm();
            if (min_sqdist > sqdist)
            {
                min_sqdist = sqdist;
                u = i;
                v = j;
            }
        }
    }

    bool uflag = true, vflag = true;
    coord_t a = coords[u], b = coords[v];
    for (int t = 0; t < n; ++t)
    {
        if (t == u || t == v) continue;
        coord_t c = coords[t];

        uflag &= (dot_product(b - a, c - a) <= 0);
        vflag &= (dot_product(a - b, c - b) <= 0);
        printf("%d: %d\n", t + 1, dot_product(b - a, c - a));
    }

    if (uflag || vflag)
    {
        printf("1\n%d\n", uflag ? (u + 1) : (v + 1));
    }
    else
    {
        printf("0\n");
    }

    exit(EXIT_SUCCESS);
}

int dot_product(const coord_t& a, const coord_t& b)
{
    int sum = 0;
    for (int k = 0; k < M; ++k)
    {
        sum += a[k] * b[k];
    }
    return sum;
}
