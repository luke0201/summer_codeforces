#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

const int L = 1000;

typedef vector<int> int_v;

char s1[L + 1], s2[L + 1];

int main()
{
    int l1, l2;
    scanf("%d%d%s%s", &l1, &l2, s1, s2);

    int_v min_diff;
    for (int i = 1; i <= l1; i++)
    {
        min_diff.push_back(i);
    }
    for (int i = 0; i < l2 - l1 + 1; i++)
    {
        int_v diff;
        for (int j = 0; j < l1; j++)
        {
            if (s1[j] != s2[i + j])
            {
                diff.push_back(j + 1);
            }
        }
        if (diff.size() < min_diff.size())
        {
            min_diff = diff;
        }
    }

    printf("%lu\n", min_diff.size());
    for (auto& idx : min_diff)
    {
        printf("%d ", idx);
    }
    printf("\n");

    exit(EXIT_SUCCESS);
}
