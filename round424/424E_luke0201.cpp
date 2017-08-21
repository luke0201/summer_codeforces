#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100000;

class Fenwick_Tree
{
    int arr[N + 1];

public:
    void add(int, int);
    int get_sum(int);

    int get_sum(int, int);
};

void Fenwick_Tree::add(int i, int value)
{
    for (; i <= N; i += (i & -i))
    {
        arr[i] += value;
    }
}

int Fenwick_Tree::get_sum(int i)
{
    int sum = 0;
    for (; i > 0; i -= (i & -i))
    {
        sum += arr[i];
    }
    return sum;
}

int Fenwick_Tree::get_sum(int a, int b)
{
    return get_sum(b) - get_sum(a - 1);
}

typedef vector<int> int_v;

int arr[N + 1];

int_v idxs[N + 1];
Fenwick_Tree cnts;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &arr[i]);
        idxs[arr[i]].push_back(i);
    }

    for (int i = 1; i <= N; ++i)
    {
        sort(idxs[i].begin(), idxs[i].end());
    }
    for (int i = 1; i <= n; ++i)
    {
        cnts.add(i, 1);
    }

    int pos = 1;
    long long total_cnt = 0LL;
    for (int v = 1; v <= N; ++v)
    {
        if (idxs[v].size() == 1)
        {
            int npos = *idxs[v].begin();
            total_cnt += (pos <= npos) ? cnts.get_sum(pos, npos) : (cnts.get_sum(pos, n) + cnts.get_sum(1, npos));
            cnts.add(npos, -1);
            pos = npos;
        }
        else if (idxs[v].size() > 1)
        {
            auto p = lower_bound(idxs[v].begin(), idxs[v].end(), pos);
            if (p == idxs[v].end())
            {
                total_cnt += cnts.get_sum(pos, n) + cnts.get_sum(1, *idxs[v].begin());
                cnts.add(*idxs[v].begin(), -1);
                for (auto q = next(idxs[v].begin()); q != idxs[v].end(); ++q)
                {
                    total_cnt += cnts.get_sum(*prev(q), *q);
                    cnts.add(*q, -1);
                }
                pos = *prev(p);
            }
            else
            {
                total_cnt += cnts.get_sum(pos, *p);
                cnts.add(*p, -1);
                for (auto q = next(p); q != idxs[v].end(); ++q)
                {
                    total_cnt += cnts.get_sum(*prev(q), *q);
                    cnts.add(*q, -1);
                }

                if (p != idxs[v].begin())
                {
                    total_cnt += cnts.get_sum(*idxs[v].rbegin(), n) + cnts.get_sum(1, *idxs[v].begin());
                    cnts.add(*idxs[v].begin(), -1);
                    for (auto q = next(idxs[v].begin()); q != p; ++q)
                    {
                        total_cnt += cnts.get_sum(*prev(q), *q);
                        cnts.add(*q, -1);
                    }
                    pos = *prev(p);
                }
                else
                {
                    pos = *idxs[v].rbegin();
                }
            }
        }
    }

    printf("%lld\n", total_cnt);

    exit(0);
}
