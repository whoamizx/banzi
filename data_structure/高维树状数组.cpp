#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 510;
int a[N][N], c[N][N];
int n, m, q;
int query(int x, int y)
{
    int s = 0;
    for (int p = x; p; p -= p & (-p))
    {
        for (int q = y; q; q -= q & (-q))
            s += c[p][q];
    }
    return s;
}
void modify(int x, int y, int s)
{
    for (int p = x; p <= n; p += p & (-p))
    {
        for (int q = y; q <= m; q += q & (-q))
        {
            c[p][q] += s;
        }
    }
}
signed main()
{
    scanf("%lld%lld%lld", &n, &m, &q);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%lld", &a[i][j]);
            modify(i, j, a[i][j]);
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int type;
        scanf("%lld", &type);
        if (type == 1)
        {
            int x, y, d;
            scanf("%lld%lld%lld", &x, &y, &d);
            modify(x, y, d - a[x][y]);
            a[x][y] = d;
        }
        else
        {
            int x, y;
            scanf("%lld%lld", &x, &y);
            printf("%lld\n", query(x, y));
        }
    }
    return 0;
}
