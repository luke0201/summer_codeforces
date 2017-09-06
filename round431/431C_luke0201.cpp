#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

const int M = 500;
const int N = 100000;
const int INF = 27;

typedef vector<int> int_v;

int dp[N + 1];

void top_down(int, int=0);

int main()
{
    fill(dp + 1, dp + N + 1, INF);

    int n;
    scanf("%d", &n);

    if (n == 0)
    {
        printf("a\n");
    }
    else
    {
        top_down(n);
    }

    exit(EXIT_SUCCESS);
}

void top_down(int n, int cnt)
{
    static int_v cnts;
    
    if (n == 0)
    {
        for (int i = 0; i < cnts.size(); ++i)
        {
            for (int j = 1; j <= cnts[i]; ++j)
            {
                printf("%c", 'a' + i);
            }
        }
        printf("\n");

        exit(EXIT_SUCCESS);
    }
    if (cnt == 26 || dp[n] < cnt)
    {
        return;
    }
    dp[n] = cnt;

    for (int i = 0; i * (i - 1) / 2 <= n; ++i)
    {
        cnts.push_back(i);
        top_down(n - i * (i - 1) / 2, cnt + 1);
        cnts.pop_back();
    }
}
