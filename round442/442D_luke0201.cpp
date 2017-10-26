#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

const int SIZE = 1000;
const int INF = SIZE * SIZE;

struct coord_t
{
    int y, x;

    coord_t() = default;
    coord_t(int y, int x) : y(y), x(x)
    {
    }
};

typedef queue<coord_t> coord_q;

char table[SIZE + 2][SIZE + 2];

int d[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
int dist[SIZE + 2][SIZE + 2];

int main()
{
    for (int y = 1; y <= SIZE; ++y)
    {
        for (int x = 1; x <= SIZE; ++x)
        {
            dist[y][x] = INF;
        }
    }

    int size_y, size_x, jump;
    scanf("%d%d%d", &size_y, &size_x, &jump);
    for (int y = 1; y <= size_y; ++y)
    {
        scanf("%s", table[y] + 1);
    }
    int start_y, start_x, end_y, end_x;
    scanf("%d%d%d%d", &start_y, &start_x, &end_y, &end_x);

    dist[start_y][start_x] = 0;
    coord_q que;
    que.emplace(start_y, start_x);
    while (!que.empty())
    {
        int y = que.front().y, x = que.front().x;
        que.pop();

        for (int k = 0; k < 4; ++k)
        {
            int next_y = y, next_x = x;
            for (int i = 1; i <= jump; ++i)
            {
                next_y += d[k][0];
                next_x += d[k][1];
                if (table[next_y][next_x] != '.') break;
                if (dist[next_y][next_x] > dist[y][x] + 1)
                {
                    dist[next_y][next_x] = dist[y][x] + 1;
                    que.emplace(next_y, next_x);
                }
                if (dist[next_y][next_x] < dist[y][x] + 1) break;
            }
        }
    }

    printf("%d\n", (dist[end_y][end_x] < INF) ? dist[end_y][end_x] : -1);

    exit(EXIT_SUCCESS);
}
