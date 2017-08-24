#include <cstdio>
#include <cstdlib>

using namespace std;

const int SIZE = 100;
const int BRIGHT = 10;

int stars[SIZE + 2][SIZE + 2][BRIGHT + 1];

int main()
{
    int n, m, max_bright;
    scanf("%d%d%d", &n, &m, &max_bright);
    for (int i = 0; i < n; ++i)
    {
        int x, y, init_bright;
        scanf("%d%d%d", &x, &y, &init_bright);
        ++stars[x][y][init_bright];
    }

    for (int x = 1; x <= SIZE; ++x)
    {
        for (int y = 1; y <= SIZE; ++y)
        {
            for (int i = 0; i <= max_bright; ++i)
            {
                stars[x][y][i] += stars[x - 1][y][i] + stars[x][y - 1][i] - stars[x - 1][y - 1][i];
            }
        }
    }

    while (m--)
    {
        int t, x1, y1, x2, y2;
        scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);

        int sum = 0;
        for (int i = 0; i <= max_bright; ++i)
        {
            int bright = (i + t) % (max_bright + 1);
            sum += bright * (stars[x2][y2][i] - stars[x1 - 1][y2][i] - stars[x2][y1 - 1][i] + stars[x1 - 1][y1 - 1][i]);
        }
        
        printf("%d\n", sum);
    }

    exit(EXIT_SUCCESS);
}