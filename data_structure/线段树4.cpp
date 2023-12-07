#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
#define int long long

struct node
{
    int l, r;
    int add, sum;
} tr[N << 1];

int n, m, idx, root;

void pushup(int p)
{
    tr[p].sum = tr[tr[p].l].sum + tr[tr[p].r].sum;
}

void pushdown(int p, int l, int r)
{
    if (tr[p].add)
    {
        int mid = l + r >> 1;
        tr[tr[p].l].sum += (mid - l + 1) * tr[p].add, tr[tr[p].l].add += tr[p].add;
        tr[tr[p].r].sum += (r - mid) * tr[p].add, tr[tr[p].r].add += tr[p].add;
        tr[p].add = 0;
    }
}
// 区间修改
void modify(int &p, int l, int r, int ql, int qr, int k)
{
    if (!p)
        p = ++idx;
    if (l >= ql && r <= qr)
    {
        tr[p].sum += (r - l + 1) * k;
        tr[p].add += k;
        return;
    }
    pushdown(p, l, r);
    int mid = l + r >> 1;
    if (ql <= mid)
        modify(tr[p].l, l, mid, ql, qr, k);
    if (qr > mid)
        modify(tr[p].r, mid + 1, r, ql, qr, k);
    pushup(p);
}
// 区间和
int query(int p, int l, int r, int ql, int qr)
{
    if (l >= ql && r <= qr)
    {
        return tr[p].sum;
    }
    int mid = l + r >> 1;
    pushdown(p, l, r);
    int v = 0;
    if (ql <= mid)
        v = query(tr[p].l, l, mid, ql, qr);
    if (qr > mid)
        v += query(tr[p].r, mid + 1, r, ql, qr);
    return v;
}

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        modify(root, 1, n, i, i, x);
    }

    int op, x, y, k;
    while (m--)
    {
        cin >> op >> x >> y;
        if (op == 1)
        {
            cin >> k;
            modify(root, 1, n, x, y, k);
        }
        else
        {
            cout << query(root, 1, n, x, y) << endl;
        }
    }
    return 0;
}
