#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

const int L = 100000;
const int LE = 10;

class Fenwick_Tree
{
    int arr[L + 1];

public:
    void add(int, int);
    int get_sum(int);
    int get_sum(int, int);
};

class DNA_Occurence
{
    Fenwick_Tree cnts[4][LE + 1][LE];
    string s;

    int get_idx(char);

public:
    DNA_Occurence() = default;

    void update(int, char);
    int get_cnt(int, int, const string&);
};

char s[L + 1];

DNA_Occurence dnncnt;

int main()
{
    scanf("%s", s);
    for (int i = 0; s[i]; ++i)
    {
        dnncnt.update(i + 1, s[i]);
    }

    int m;
    scanf("%d", &m);
    while (m--)
    {
        int oper;
        scanf("%d", &oper);
        if (oper == 1)
        {
            int a;
            scanf("%d%s", &a, s);
            
            dnncnt.update(a, s[0]);
        }
        if (oper == 2)
        {
            int a, b;
            scanf("%d%d %s", &a, &b, s);

            printf("%d\n", dnncnt.get_cnt(a, b, s));
        }
    }

    exit(EXIT_SUCCESS);
}

void Fenwick_Tree::add(int i, int value)
{
    for (; i <= L + 1; i += (i & -i))
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
int Fenwick_Tree::get_sum(int left, int right)
{
    return get_sum(right) - get_sum(left - 1);
}

void DNA_Occurence::update(int pos, char c)
{
    if (s.size() >= pos)
    {
        for (int i = 1; i <= LE; ++i)
        {
            cnts[get_idx(s[pos - 1])][i][pos % i].add(pos, -1);
        }

        s[pos - 1] = c;
    }
    else
    {
        s.push_back(c);
    }

    for (int i = 1; i <= LE; ++i)
    {
        cnts[get_idx(c)][i][pos % i].add(pos, 1);
    }
}

int DNA_Occurence::get_cnt(int left, int right, const string& q)
{
    int l = q.size();

    int sum = 0;
    for (int i = 0; i < min(l, right - left + 1); ++i)
    {
        sum += cnts[get_idx(q[i])][l][(left + i) % l].get_sum(left, right);
    }

    return sum;
}

int DNA_Occurence::get_idx(char c)
{
    if (c == 'A')
    {
        return 0;
    }
    if (c == 'T')
    {
        return 1;
    }
    if (c == 'G')
    {
        return 2;
    }
    if (c == 'C')
    {
        return 3;
    }

    return -1;
}