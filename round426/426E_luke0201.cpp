#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> int_v;

int_v a, b;
int n;

int cnt[10], tmp[10];
int ans;

int_v int_to_str(long long);
void generate_cnt(int);
bool dfs(int, bool, bool);

int main()
{
    long long _a, _b;
    scanf("%lld%lld", &_a, &_b);
    a = int_to_str(_a);
    b = int_to_str(_b);
    while (a.size() < b.size())
    {
        a.push_back(0);
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    n = cnt[0] = b.size();
    generate_cnt(1);
    
    printf("%d\n", ans);

    exit(EXIT_SUCCESS);
}

int_v int_to_str(long long x)
{
    int_v y;
    for (; x > 0; x /= 10)
    {
        y.push_back(x % 10);
    }
    return y;
}

void generate_cnt(int cur)
{
    if (cur == 10)
    {
        copy(cnt, cnt + 10, tmp);
        ans += dfs(0, true, true);
        return;
    }

    for (cnt[cur] = 0; cnt[cur] <= cnt[0]; ++cnt[cur])
    {
        cnt[0] -= cnt[cur];
        generate_cnt(cur + 1);
        cnt[0] += cnt[cur];
    }
}

bool dfs(int cur, bool leftflag, bool rightflag)
{
    if (cur == n)
    {
        return true;
    }
    
    bool ret = false;
    int l = a[cur], r = b[cur];
    if (leftflag && rightflag)
    {
        if (l == r)
        {
            if (tmp[l] > 0)
            {
                --tmp[l];
                ret = dfs(cur + 1, true, true);
                ++tmp[l];
            }
        }
        else
        {
            for (int i = l + 1; i <= r - 1; ++i)
            {
                if (tmp[i] > 0)
                {
                    return true;
                }
            }
            bool ret = false;
            if (tmp[l] > 0)
            {
                --tmp[l];
                ret |= dfs(cur + 1, true, false);
                ++tmp[l];
            }
            if (tmp[r] > 0)
            {
                --tmp[r];
                ret |= dfs(cur + 1, false, true);
                ++tmp[r];
            }
            return ret;
        }
    }
    if (leftflag && !rightflag)
    {
        for (int i = l + 1; i <= 9; ++i)
        {
            if (tmp[i] > 0)
            {
                return true;
            }
        }
        if (tmp[l] > 0)
        {
            --tmp[l];
            ret = dfs(cur + 1, true, false);
            ++tmp[l];
        }
    }
    if (!leftflag && rightflag)
    {
        for (int i = 0; i <= r - 1; ++i)
        {
            if (tmp[i] > 0)
            {
                return true;
            }
        }
        if (tmp[r] > 0)
        {
            --tmp[r];
            ret = dfs(cur + 1, false, true);
            ++tmp[r];
        }
    }
    return ret;
}
