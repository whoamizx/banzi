#include <bits/stdc++.h>
using namespace std;
#define int long long
// 一个区间内相同的放进set不重复
int k;
struct cmp
{
    bool operator()(const int &u, const int &v) const
    {
        if (abs(u - v) <= k)
        {
            return false;
        }
        return u < v;
    }
};

set<int, cmp> se;
signed main()
{
    int m;
    cin >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        string op;
        cin >> op;
        int x;
        scanf("%lld", &x);

        if (op == "add")
        {
            se.insert(x);
        }
        else if (op == "del")
        {
            se.erase(x);
        }
        else
        {
            if (se.count(x)) // if (se.find(x)!=se.end())
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }
    return 0;
}