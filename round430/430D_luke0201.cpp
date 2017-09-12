#include <cstdio>
#include <cstdlib>

using namespace std;

const int N_BITS = 19;

class Trie
{
    struct node
    {
        node* left;
        node* right;
        bool is_complete;

        node(const bool is_complete=false) : is_complete(is_complete), left(nullptr), right(nullptr)
        {
        }

        void calc_completeness()
        {
            if (is_complete)
            {
                return;
            }
            is_complete = true;
            
            if (left)
            {
                left->calc_completeness();
                is_complete &= left->is_complete;
            }
            else
            {
                is_complete = false;
            }
            if (right)
            {
                right->calc_completeness();
                is_complete &= right->is_complete;
            }
            else
            {
                is_complete = false;
            }
        }
    };
    node* root;

public:
    Trie() : root(new node())
    {
    }

    void insert(const int);
    void calc_completeness();

    int get_min_uncontained(const int);
};

void Trie::insert(const int x)
{
    auto p = root;
    for (int i = 1 << N_BITS; i > 0; i >>= 1)
    {
        if ((x & i) == 0)
        {
            if (!p->left)
            {
                p->left = new node(i == 1);
            }
            p = p->left;
        }
        else
        {
            if (!p->right)
            {
                p->right = new node(i == 1);
            }
            p = p->right;
        }
    }
}

void Trie::calc_completeness()
{
    root->calc_completeness();
}

int Trie::get_min_uncontained(const int x)
{
    int y = 0;
    auto p = root;
    for (int i = 1 << N_BITS; i > 0; i >>= 1)
    {
        if ((x & i) == 0)
        {
            if (!p->left || !p->left->is_complete)
            {
                p = p->left;
            }
            else
            {
                y ^= i;
                p = p->right;
            }
        }
        else
        {
            if (!p->right || !p->right->is_complete)
            {
                y ^= i;
                p = p->right;
            }
            else
            {
                p = p->left;
            }
        }

        if (!p)
        {
            y ^= x & (i - 1);
            break;
        }
    }
    return y;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    Trie trie;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        trie.insert(x);
    }
    trie.calc_completeness();

    int x = 0;
    while (m--)
    {
        int _x;
        scanf("%d", &_x);
        x ^= _x;

        printf("%d\n", trie.get_min_uncontained(x) ^ x);
    }
    
    exit(EXIT_SUCCESS);
}
