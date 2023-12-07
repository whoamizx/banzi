#include <bits/stdc++.h>
using namespace std;
// 给n个数a1,a2,a3,…,an
// 支持q个操作：
// 1 x d，修改ax=d
// 2 l r d， 查询al,al+1,al+2,…,ar中大于等于d的第一个数的下标，如果不存在，输出−1
// 也就是说，求最小的i(l≤i≤r)满足ai≥d
#define int long long
const int N = 2e5 + 10;
int n, q;
int a[N];
struct node
{
    int val;
} seg[N * 4];
void update(int id)
{
    seg[id].val = max(seg[id * 2].val, seg[id * 2 + 1].val);
}
void build(int id, int l, int r)
{
    if (l == r)
    {
        seg[id].val = a[l];
    }
    else
    {
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        update(id);
    }
}
// 节点为i,修改a[pos]->val
void change(int id, int l, int r, int pos, int val)
{
    if (l == r) // 到叶子节点了
    {
        seg[id].val = val;
    }
    else
    {
        int mid = (l + r) / 2;
        //!!
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
int search(int id, int l, int r, int ql, int qr, int d)
{
    if (l == ql && r == qr)
    {
        if (seg[id].val < d)
        {
            return -1;
        }
        else
        {
            if (l == r)
            {
                return l;
            }
            int mid = (l + r) / 2;
            if (seg[id * 2].val >= d)
            {
                return search(id * 2, l, mid, ql, mid, d);
            }
            else
            {
                return search(id * 2 + 1, mid + 1, r, mid + 1, qr, d);
            }
        }
    }
    int mid = (l + r) / 2;
    //[l,mid],[mid+1,r]
    if (qr <= mid)
    {
        return search(id * 2, l, mid, ql, qr, d);
    }
    else if (ql > mid)
    {
        return search(id * 2 + 1, mid + 1, r, ql, qr, d);
    }
    else
    {
        // qr>mid,ql<=mid
        //[qr,mid],[mid+1,qr]
        int pos = search(id * 2, l, mid, ql, mid, d);
        if (pos == -1)
        {
            return search(id * 2 + 1, mid + 1, r, mid + 1, qr, d);
        }
        else
        {
            return pos;
        }
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
            int l, r, d;
            scanf("%lld%lld%lld", &l, &r, &d);
            auto ans = search(1, 1, n, l, r, d);
            printf("%lld\n", ans);
        }
    }
    return 0;
}