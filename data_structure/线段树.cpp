#include <bits/stdc++.h>
using namespace std;
// 给n个数a1,a2,a3,…,an
// 支持q个操作：
// 1 x d，修改ax=d
// 2 l r，查询min(ai)(i=l到r)
// 并且求出最小值出现了多少次。
#define int long long
const int N = 2e5 + 10;
int n, q;
int a[N];
struct info
{
    int minv, mincnt;
};
info operator+(const info &l, const info &r)
{
    info a;
    a.minv = min(l.minv, r.minv);
    if (l.minv == r.minv)
    {
        a.mincnt = l.mincnt + r.mincnt;
    }
    else if (l.minv < r.minv)
    {
        a.mincnt = l.mincnt;
    }
    else
    {
        a.mincnt = r.mincnt;
    }
    return a;
}
struct node
{
    info val;
} seg[N * 4];
void update(int id)
{
    seg[id].val = seg[id * 2].val + seg[id * 2 + 1].val;
}
void build(int id, int l, int r)
{
    if (l == r)
    {
        seg[id].val = {a[l], 1};
    }
    else
    {
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        update(id);
    }
}
// 节点为id,对应区间为[l,r],修改a[pos]->val
void change(int id, int l, int r, int pos, int val)
{
    if (l == r) // 到叶子节点了
    {
        seg[id].val = {val, 1};
        // a[pos]=val;//看原数组还是否使用
    }
    else
    {
        int mid = (l + r) / 2;
        if (pos <= mid)
        {
            change(id * 2, l, mid, pos, val);
        }
        else
        {
            change(id * 2 + 1, mid + 1, r, pos, val);
        }
        // important!!
        update(id);
    }
}
// 查询区间为[ql,qr]
// O(log(n))
info query(int id, int l, int r, int ql, int qr)
{
    if (l == ql && r == qr)
    {
        return seg[id].val;
    }
    int mid = (l + r) / 2;
    //[l,mid],[mid+1,r]
    if (qr <= mid)
    {
        return query(id * 2, l, mid, ql, qr);
    }
    else if (ql > mid)
    {
        return query(id * 2 + 1, mid + 1, r, ql, qr);
    }
    else
    {
        // qr>mid,ql<=mid
        //[qr,mid],[mid+1,qr]
        return query(id * 2, l, mid, ql, mid) + query(id * 2 + 1, mid + 1, r, mid + 1, qr);
    }
}
signed main()
{
    scanf("%lld%lld", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    build(1, 1, n);
    for (int i = 1; i <= q; i++)
    {
        int type;
        scanf("%lld", &type);
        if (type == 1)
        {
            int x, d;
            scanf("%lld%lld", &x, &d);
            change(1, 1, n, x, d);
        }
        else
        {
            int l, r;
            scanf("%lld%lld", &l, &r);
            auto ans = query(1, 1, n, l, r);
            printf("%lld %lld\n", ans.minv, ans.mincnt);
        }
    }
    return 0;
}