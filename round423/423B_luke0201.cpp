#include <cstdio>
#include <cstdlib>
#include <set>
#include <algorithm>

using namespace std;

const int SIZE = 100;

typedef set<int> int_set;

char arr[SIZE + 2][SIZE + 2];

int white[SIZE + 2][SIZE + 2];

int main()
{
    int_set ys, xs;

    int size_y, size_x;
    scanf("%d%d", &size_y, &size_x);
    for (int y = 1; y <= size_y; y++)
    {
        scanf("%s", arr[y] + 1);
        
        for (int x = 1; x <= size_x; x++)
        {
            if (arr[y][x] == 'B')
            {
                ys.insert(y);
                xs.insert(x);
            }
            white[y][x] = white[y - 1][x] + white[y][x - 1] - white[y - 1][x - 1] + (arr[y][x] == 'W');
        }
    }

    if (!ys.empty())
    {
        int min_y = *ys.begin(), max_y = *ys.rbegin();
        int min_x = *xs.begin(), max_x = *xs.rbegin();
        int l = max(max_y - min_y + 1, max_x - min_x + 1);

        if (l > size_y || l > size_x)
        {
            printf("-1\n");
            exit(EXIT_SUCCESS);
        }

        int min_cnt = l * l;
        for (int y = l; y <= size_y; y++)
        {
            for (int x = l; x <= size_x; x++)
            {
                min_cnt = min(min_cnt, white[y][x] - white[y - l][x] - white[y][x - l] + white[y - l][x - l]);
            }
        }
        printf("%d\n", min_cnt);
    }
    else
    {
        printf("1\n");
    }

    exit(EXIT_SUCCESS);
}