#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100;

typedef vector<int> int_v;

int arr[N];
int_v seq;

int ceil_div(int, int);
void remove_dup(int_v&);

int main()
{
    int n;
    long long k;
    scanf("%d%lld", &n, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
        k += arr[i];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j * j <= arr[i]; ++j)
        {
            seq.push_back(j);
            seq.push_back(ceil_div(arr[i], j));
        }
    }
    remove_dup(seq);

    long long max_seq = 0;
    for (auto& l : seq)
    {
        long long sum = 0LL;
        for (int i = 0; i < n; ++i)
        {
            sum += ceil_div(arr[i], l);
        }
        long long d = k / sum;
        if (d >= l)
        {
            max_seq = max(max_seq, d);
        }
    }

    printf("%lld\n", max_seq);

    exit(EXIT_SUCCESS);
}

int ceil_div(int n, int r)
{
    return (n + r - 1) / r;
}

void remove_dup(int_v& arr)
{
    sort(arr.begin(), arr.end());
    unique(arr.begin(), arr.end());
    int_v:: iterator p;
    for (p = arr.begin(); next(p) != arr.end(); ++p)
    {
        int u = *p, v = *next(p);
        if (u > v) break;
    }
    arr.erase(next(p), arr.end());
}
