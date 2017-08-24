#include <cstdio>
#include <cstdlib>
#include <set>

using namespace std;

const int N = 1000000;
const int AB = 26;

class Fenwick_Tree
{
    int arr[N + 2];

public:
    void add(int, int);
    int get_sum(int);
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

typedef set<int> int_set;

char s[N + 1];

int_set occur[AB];
Fenwick_Tree opened;

int main()
{
    int n, k;
    scanf("%d%d%s", &n, &k, s + 1);

    for (int i = 1; s[i]; ++i)
    {
        occur[s[i] - 'A'].insert(i);
    }
    for (int i = 0; i < AB; ++i)
    {
        if (occur[i].empty()) continue;
        opened.add(*occur[i].begin(), 1);
        opened.add(*occur[i].rbegin() + 1, -1);
    }

    for (int i = 1; s[i]; ++i)
    {
        if (opened.get_sum(i) > k)
        {
            printf("YES\n");
            exit(0);
        }
    }
    printf("NO\n");

    exit(0);
}