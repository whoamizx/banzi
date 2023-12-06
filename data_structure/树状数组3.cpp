// 查询第k大 //对权值开数组
// 每个位置值为1 看这个数前面有几个1,就是第几大
// 比如2 5 8 10
// 就是第2 5 8 10的数组位置为1
#include <bits/stdc++.h>
using namespace std;
// 给n个数a1,a2,a3,…,an
// 支持q个操作：
// 1 x d，修改ax=d
// 2 s，查询最大的T(0≤T≤n)
// 满足∑ai(i=1到T)≤s
#define int long long
const int N = 2e5 + 10;
int a[N], c[N];
int n, q;
int query(int s)
{
    int t = 0;
    int pos = 0;
    for (int j = 18; j >= 0; j--)
    {
        if (pos + (1 << j) <= n && t + c[pos + (1 << j)] <= s)
        {
            pos += (1 << j);
            t += c[pos];
        }
    }
    return pos;
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
