#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int L = 9;
const int N = 70000;

typedef pair<string, int> sip;
typedef vector<sip> sip_v;
typedef set<int> int_set;
typedef vector<string> string_v;

char s[L + 1];

sip_v substrs;
string_v ans[N + 1];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", s);
        for (int j = 0; j < L; ++j)
        {
            string substr;
            for (int k = j; k < L; ++k)
            {
                substr.push_back(s[k]);
                substrs.emplace_back(substr, i);
            }
        }
    }
    sort(substrs.begin(), substrs.end());
    substrs.emplace_back("", 0);

    int_set idxs({substrs.begin()->second});
    for (auto p = next(substrs.begin()); p != substrs.end(); ++p)
    {
        if (p->first != prev(p)->first)
        {
            if (idxs.size() == 1)
            {
                ans[*idxs.begin()].push_back(prev(p)->first);
            }

            idxs.clear();
        }
        idxs.insert(p->second);
    }

    for (int i = 0; i < n; ++i)
    {
        printf("%s\n", min_element(ans[i].begin(), ans[i].end(), [&](const string& a, const string& b) -> bool { return a.size() < b.size();  })->c_str());
    }

    exit(EXIT_SUCCESS);
}
