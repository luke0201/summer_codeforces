#include <cstdio>
#include <cstdlib>

using namespace std;

const int N = 300000;

class Fenwick_Tree
{
    int _arr[N + 1];

public:
    void add(int, int);
    int get_sum(int);
};

void Fenwick_Tree::add(int i, int value)
{
    for (; i <= N; i += (i & -i))
    {
        _arr[i] += value;
    }
}

int Fenwick_Tree::get_sum(int i)
{
    int sum = 0;
    for (; i > 0; i -= (i & -i))
    {
        sum += _arr[i];
    }
    return sum;
}

Fenwick_Tree bitree;
bool checked[N + 1];

int main()
{
    int n;
    scanf("%d", &n);
    
    int right = n;
    printf("1");
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        checked[x] = true;
        bitree.add(x, 1);
        
        for (; checked[right]; --right);
        printf(" %d", bitree.get_sum(right) + 1);
    }
    printf("\n");

    exit(EXIT_SUCCESS);
}
