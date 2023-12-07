#include <bits/stdc++.h>
using namespace std;
// 此为权值线段树
// 1e7最大,再大就要离散化
#define int long long
const int M = 1e6 + 5;
struct node
{
    int sum = 0;
    int l = 0, r = 0;
} tr[M * 30];
#define ls(x) (tr[x].l)
#define rs(x) (tr[x].r)
#define sum(x) tr[x].sum
int tot = 1;
void pushup(int x)
{
    sum(x) = sum(ls(x)) + sum(rs(x));
}
void pushdown(int x)
{
    if (!ls(x))
        ls(x) = ++tot;
    if (!rs(x))
        rs(x) = ++tot;
}
// 单点修改 修改权值对应位置pos位置加k
void upd(int x, int l, int r, int pos, int k)
{
    if (l == r)
    {
        sum(x) += k;
        return;
    }
    int mid = (l + r - 1) / 2;
    pushdown(x);
    if (pos <= mid)
        upd(ls(x), l, mid, pos, k);
    else
        upd(rs(x), mid + 1, r, pos, k);
    pushup(x);
}
// 查l到r有几个数
int que(int x, int l, int r, int L, int R)
{
    if (L <= l && r <= R)
        return sum(x);
    if (l > R || r < L)
        return 0;
    pushdown(x);
    int mid = (l + r - 1) / 2;
    return que(ls(x), l, mid, L, R) +
           que(rs(x), mid + 1, r, L, R);
}
void add(int pos, int k)
{
    upd(1, -10000005, 10000005, pos, k);
}
int que(int L, int R)
{
    return que(1, -10000005, 10000005, L, R);
}
// 1.插入数x
void insert(int x) { add(x, 1); }
// 2.删除数x(有相同的话只删一个)
void del(int x) { add(x, -1); }
// 3.查询数的排名(排名定义为比当前数小的数的个数＋1)
int rnk(int x) { return que(-10000005, x - 1) + 1; }
// 4.查询排名为x的数
int kth(int x, int l, int r, int k)
{
    if (l == r)
        return l;
    int mid = (l + r - 1) / 2;
    if (k <= sum(ls(x)))
        return kth(ls(x), l, mid, k);
    else
        return kth(rs(x), mid + 1, r, k - sum(ls(x)));
}
int kth(int k) { return kth(1, -10000005, 10000005, k); }
// 5.求x的前驱(前驱定义为小于x，且最大的数)
int pre(int k)
{
    return kth(rnk(k) - 1);
}
// 6.求x的后继(后继定义为大于x，且最小的数)
int nxt(int k)
{
    return kth(rnk(k + 1));
}
void slove()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%lld", &x);
        insert(x);
    }
    for (int i = 1; i <= q; i++)
    {
        int op, x;
        cin >> op;
        if (op == 1)
        {
            scanf("%lld", &x);
            insert(x);
        }
        else if (op == 2)
        {
            scanf("%lld", &x);
            del(x);
        }
        else if (op == 3)
        {
            scanf("%lld", &x);
            cout << rnk(x) << endl;
        }
        else if (op == 4)
        {
            scanf("%lld", &x);
            cout << kth(x) << endl;
        }
        else if (op == 5)
        {
            scanf("%lld", &x);
            cout << pre(x) << endl;
        }
        else if (op == 6)
        {
            scanf("%lld", &x);
            cout << nxt(x) << endl;
        }
        else if (op == 7)
        {

            int l, r;
            scanf("%lld%lld", &l, &r);
            printf("%lld\n", que(l, r));
        }
    }
}
signed main()
{
    slove();
    return 0;
}