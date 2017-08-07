#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>

using namespace std;

const int AB = 26;
const int L = 1000;

char key1[AB + 1], key2[AB + 1];
char s[L + 1];

int main()
{
    scanf("%s%s%s", key1, key2, s);

    for (int i = 0; s[i]; ++i)
    {
        if (isalpha(s[i]))
        {
            bool upper = isupper(s[i]);
            char conv = key2[find(key1, key1 + AB, tolower(s[i])) - key1];
            printf("%c", !upper ? conv : toupper(conv));
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");

    exit(EXIT_SUCCESS);
}
