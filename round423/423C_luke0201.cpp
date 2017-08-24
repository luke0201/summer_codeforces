#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100000;
const int L = 2000000;

struct part_t
{
    int idx;

    part_t() = default;
    part_t(int idx)
    {
    }

    int get_l();
};

string piece[N + 1];
char s[L + 1];

part_t parts[L + 1];

int main()
{
    int max_l = 0;

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%s", s);
        piece[i] = s;
        int l = piece[i].size();
        
        int m;
        scanf("%d", &m);
        while (m--)
        {
            int x;
            scanf("%d", &x);
            if (parts[x].get_l() < l)
            {
                parts[x].idx = i;
                max_l = max(max_l, x + l - 1);
            }
        }
    }

    fill(s + 1, s + max_l + 1, '\0');
    for (int i = 1; i <= max_l; ++i)
    {
        if (!parts[i].get_l()) continue;

        for (int j = 0; j < parts[i].get_l(); ++j)
        {
            if (i + parts[i].get_l() < i + j + parts[i + j].get_l())
            {
                i += j - 1;
                break;
            }
            s[i + j] = piece[parts[i].idx][j];
        }
    }

    for (int i = 1; i <= max_l; ++i)
    {
        printf("%c", s[i] ? s[i] : 'a');
    }
    printf("\n");

    exit(EXIT_SUCCESS);
}

int part_t::get_l()
{
    return piece[idx].size();
}