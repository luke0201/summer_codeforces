#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> int_v;

int n;

int used[10], cnt[10];
int_v ans;

void proc(int, int);

int main()
{
    scanf("%d", &n);

    proc(0, 9);

    printf("%d\n", (int)ans.size());
    if (!ans.empty())
    {
        sort(ans.begin(), ans.end());
        for (int x : ans)
        {
            printf("%d ", x);
        }
        printf("\n");
    }

    exit(EXIT_SUCCESS);
}

void proc(int bound, int d)
{
    fill(cnt, cnt + 10, 0);
    for (int tmp = n; tmp > 0; tmp /= 10)
    {
        ++cnt[tmp % 10];
    }

    if (equal(cnt, cnt + 10, used))
    {
        ans.push_back(n);
    }

    if (bound < n)
    {
        for (int i = d; i >= (bound == 0); --i)
        {
            ++used[i];
            n -= i;
            proc(bound * 10 + 9, i);
            --used[i];
            n += i;
        }
    }
}
