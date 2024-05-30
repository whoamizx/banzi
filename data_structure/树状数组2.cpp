#include <bits/stdc++.h>
using namespace std;
// 有n个数a1,a2,a3,…,an ，一开始都是0
// 支持q个操作：
// 1 l r d，令所有的ai(l≤i≤r)加上d
// 2 x，查询(∑ai)(i=1到x)mod264
#define int long long
const int N = 2e5 + 10;
int n, q;
template <class T>
struct BIT
{
    T c[N];
    int size;
    void resize(int s)
    {
        size = s;
    }
    T query(int x)
    {
        assert(x <= size);
        T s = 0;
        for (; x; x -= x & (-x))
        {
            s += c[x];
        }
        return s;
    }
    void modify(int x, T s)
    {
        // x!=0
        assert(x != 0);
        for (; x <= size; x += x & (-x)) // 一定注意size
        {
            c[x] += s;
        }
    }
};
BIT<int> c1, c2;
signed main()
{
    scanf("%lld%lld", &n, &q);
    c1.resize(n);
    c2.resize(n);
    for (int i = 1; i <= q; i++)
    {
        int type;
        scanf("%lld", &type);
        if (type == 1)
        {
            int l, r, d;
            scanf("%lld%lld%lld", &l, &r, &d);
            c1.modify(l, d);
            c1.modify(r + 1, -d);
            c2.modify(l, l * d);
            c2.modify(r + 1, (r + 1) * (-d));
        }
        else
        {
            int x;
            scanf("%lld", &x);
            unsigned long long ans = (x + 1) * c1.query(x) - c2.query(x);
            printf("%llu\n", ans); // 取模对2^64
        }
    }
    return 0;
}
