#include <bits/stdc++.h>
using namespace std;
// 给n个数a1,a2,a3,…,an
// 支持q个操作：
// 1 l r d，令所有的ai(l≤i≤r)加上d
// 2 l r，查询max(ai)(i=l到r)
#define int long long
const int N = 2e5 + 10;
int n, q;
int a[N];
struct node
{
    int t, val;
} seg[N * 4];
void update(int id)
{
    seg[id].val = max(seg[id * 2].val, seg[id * 2 + 1].val);
}
void settag(int id, int t)
{
    seg[id].val = seg[id].val + t;
    seg[id].t = seg[id].t + t;
}
void pushdown(int id)
{
    if (seg[id].t != 0) // tag不是0
    {
        settag(id * 2, seg[id].t);
        settag(id * 2 + 1, seg[id].t);
        seg[id].t = 0;
    }
}
void build(int id, int l, int r)
{
    if (l == r)
    {
        seg[id].val = {a[l]};
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
void modify(int id, int l, int r, int ql, int qr, int t)
{
    if (l == ql && r == qr)
    {
        settag(id, t);
        return;
    }
    int mid = (l + r) / 2;
    //!!
    pushdown(id);
    if (qr <= mid)
    {
        modify(id * 2, l, mid, ql, qr, t);
    }
    else if (ql > mid)
    {
        modify(id * 2 + 1, mid + 1, r, ql, qr, t);
    }
    else
    {
        modify(id * 2, l, mid, ql, mid, t);
        modify(id * 2 + 1, mid + 1, r, mid + 1, qr, t);
    }
    // important!!
    update(id);
}
// 查询区间为[ql,qr]
// O(log(n))
int query(int id, int l, int r, int ql, int qr)
{
    if (l == ql && r == qr)
    {
        return seg[id].val;
    }
    int mid = (l + r) / 2;
    //!!
    pushdown(id);
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
        return max(query(id * 2, l, mid, ql, mid), query(id * 2 + 1, mid + 1, r, mid + 1, qr));
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
            int l, r, d;
            scanf("%lld%lld%lld", &l, &r, &d);
            modify(1, 1, n, l, r, d);
        }
        else
        {
            int l, r;
            scanf("%lld%lld", &l, &r);
            auto ans = query(1, 1, n, l, r);
            printf("%lld\n", ans);
        }
    }
    return 0;
}