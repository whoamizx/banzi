#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
// 区间修改+区间和查询
int a[N];
int tree[N * 4];
int tag[N * 4];

int ls(int p)
{
    return p * 2;
}
int rs(int p)
{
    return p * 2 + 1;
}

void push_up(int p)
{
    tree[p] = tree[ls(p)] + tree[rs(p)];
}
void build(int p, int pl, int pr)
{
    // 懒标记初始化为0
    tag[p] = 0;

    if (pl == pr)
    {
        // 或者tree[p]=a[pr]也行
        tree[p] = a[pl];
        return;
    }

    int mid = (pl + pr) / 2;
    build(ls(p), pl, mid);
    build(rs(p), mid + 1, pr);

    // 儿子更新过了,用儿子更新自己,向上传递
    push_up(p);
}

void addtag(int p, int pl, int pr, int d)
{
    tag[p] += d;
    tree[p] += d * (pr - pl + 1);
}
void push_down(int p, int pl, int pr)
{
    if (tag[p])
    {
        int mid = (pl + pr) / 2;
        addtag(ls(p), pl, mid, tag[p]);
        addtag(rs(p), mid + 1, pr, tag[p]);
        tag[p] = 0;
    }
}
void update(int L, int R, int p, int pl, int pr, int d)
{
    // 完全覆盖则更新懒标签
    if (L <= pl && pr <= R)
    {
        addtag(p, pl, pr, d);
        return;
    }

    // 不能覆盖就要把tag传给子树
    push_down(p, pl, pr);

    int mid = (pl + pr) / 2;
    if (L <= mid)
    {
        update(L, R, ls(p), pl, mid, d);
    }
    if (R > mid)
    {
        update(L, R, rs(p), mid + 1, pr, d);
    }

    // 儿子更新过了,传递上来
    push_up(p);
}
int query(int L, int R, int p, int pl, int pr)
{
    if (L <= pl && pr <= R)
    {
        return tree[p];
    }
    // 不能完全覆盖,要去子树,则先把懒标记传下去
    push_down(p, pl, pr);
    int res = 0;
    int mid = (pl + pr) / 2;
    if (L <= mid)
    {
        res += query(L, R, ls(p), pl, mid);
    }
    if (R > mid)
    {
        res += query(L, R, rs(p), mid + 1, pr);
    }
    return res;
}

signed main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    build(1, 1, n);
    while (m--)
    {
        int q, L, R, d;
        scanf("%lld", &q);
        if (q == 1)
        {
            scanf("%lld%lld%lld", &L, &R, &d);
            update(L, R, 1, 1, n, d);
        }
        else
        {
            scanf("%lld%lld", &L, &R);
            printf("%lld\n", query(L, R, 1, 1, n));
        }
    }
    return 0;
}