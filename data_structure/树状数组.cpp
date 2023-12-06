#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int a[N], c[N];
int n, q;
int query(int x)
{
    int s = 0;
    for (; x; x -= x & (-x))
    {
        s += c[x];
    }
    return s;
}
void modify(int x, int s)
{
    for (; x <= n; x += x & (-x))
    {
        c[x] += s;
    }
}
signed main()
{
    scanf("%lld%lld", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        modify(i, a[i]);
    }
    for (int i = 1; i <= q; i++)
    {
        int type;
        scanf("%lld", &type);
        if (type == 1)
        {
            int x, d;
            scanf("%lld%lld", &x, &d);
            modify(x, d - a[x]);
            a[x] = d;
        }
        else
        {
            int x;
            scanf("%lld", &x);
            printf("%lld\n", query(x));
        }
    }
    return 0;
}
