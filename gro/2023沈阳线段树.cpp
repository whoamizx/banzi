#include <iostream>
#include <vector>
#include <functional>

using namespace std;

struct TNode
{
    long long int sum = 0; // 和
    int cnt = 0;           // 节点个数
    int l = 0;             // 左节点(0 表示不存在)
    int r = 0;             // 右节点(0 表示不存在)
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<TNode> tree(n << 6);
    int tot = 1;
    const int INF = 1 << 30;
    function<void(int)> Pull = [&](int p) -> void
    {
        int l = tree[p].l;
        int r = tree[p].r;
        tree[p].sum = tree[l].sum + tree[r].sum;
        tree[p].cnt = tree[l].cnt + tree[r].cnt;
    };
    function<void(int, int, int, int, int)> Add = [&](int p, int l, int r, int x, int k) -> void
    {
        // 插入 x 这个数字 k 个(实际上 k = 1, 插入 一个 x, k = -1, 删除 一个 x)
        if (l >= r)
        {
            tree[p].sum += k * x;
            tree[p].cnt += k;
            return;
        }
        int mid = (l + r) / 2;
        if (x <= mid)
        {
            // 左边的
            if (tree[p].l == 0)
            {
                tree[p].l = ++tot;
            }
            Add(tree[p].l, l, mid, x, k);
        }
        else
        {
            // 右边的
            if (tree[p].r == 0)
            {
                tree[p].r = ++tot;
            }
            Add(tree[p].r, mid + 1, r, x, k);
        }
        Pull(p);
    };
    // 查询 [ql, qr] 里面的元素之和 sum 和元素个数 cnt
    function<pair<long long int, int>(int, int, int, int, int)> Query = [&](int p, int l, int r, int ql, int qr) -> pair<long long int, int>
    {
        if (ql <= l && r <= qr)
        {
            return make_pair(tree[p].sum, tree[p].cnt);
        }
        int mid = (l + r) / 2;
        if (qr <= mid)
        {
            if (tree[p].l == 0)
            {
                tree[p].l = ++tot;
            }
            return Query(tree[p].l, l, mid, ql, mid);
        }
        else if (ql > mid)
        {
            if (tree[p].r == 0)
            {
                tree[p].r = ++tot;
            }
            return Query(tree[p].r, mid + 1, r, mid + 1, qr);
        }
        else
        {
            if (tree[p].l == 0)
            {
                tree[p].l = ++tot;
            }
            if (tree[p].r == 0)
            {
                tree[p].r = ++tot;
            }
            auto ans_l = Query(tree[p].l, l, mid, ql, mid);
            auto ans_r = Query(tree[p].r, mid + 1, r, mid + 1, qr);
            return make_pair(ans_l.first + ans_r.first, ans_l.second + ans_r.second);
        }
    };
    // 查询 [ql, qr] 第一个前缀和 > x 的, 如果没有则返回 0
    function<long long int(int, int, int, int, int, long long int)> FirstGT = [&](int p, int l, int r, int ql, int qr, long long int x) -> long long int
    {
        if (tree[p].sum <= x)
        {
            return 0;
        }
        if (l >= r)
        {
            // 找到了
            // 需要找到最小的 k, k * l > x
            if (1ll * tree[p].cnt * l <= x)
            {
                return 0;
            }
            else
            {
                return x / l + 1;
            }
        }
        // 一整段的
        int mid = (l + r) / 2;
        if (ql <= l && r <= qr)
        {
            if (tree[p].l == 0)
            {
                tree[p].l = ++tot;
            }
            if (tree[tree[p].l].sum > x)
            {
                return FirstGT(tree[p].l, l, mid, ql, mid, x);
            }
            else
            {
                if (tree[p].r == 0)
                {
                    tree[p].r = ++tot;
                }
                return FirstGT(tree[p].r, mid + 1, r, mid + 1, qr, x - tree[tree[p].l].sum) + tree[tree[p].l].cnt;
            }
        }
        // 分散的
        if (qr <= mid)
        {
            if (tree[p].l == 0)
            {
                tree[p].l = ++tot;
            }
            return FirstGT(tree[p].l, l, mid, ql, qr, x);
        }
        else if (ql > mid)
        {
            if (tree[p].r == 0)
            {
                tree[p].r = ++tot;
            }
            return FirstGT(tree[p].r, mid + 1, r, ql, qr, x);
        }
        else
        {
            if (tree[p].l == 0)
            {
                tree[p].l = ++tot;
            }
            long long int ans_l = FirstGT(tree[p].l, l, mid, ql, mid, x);
            if (ans_l != 0)
            {
                return ans_l;
            }
            else
            {
                if (tree[p].r == 0)
                {
                    tree[p].r = ++tot;
                }
                auto info_l = Query(tree[p].l, l, mid, ql, mid);
                return FirstGT(tree[p].r, mid + 1, r, mid + 1, qr, x - info_l.first) + info_l.second;
            }
        }
    };
    vector<int> a(n + 1);
    int cnt1 = 0;           // 正数的个数
    int cnt2 = 0;           // 负数的个数
    long long int sum2 = 0; // 负数的和
    int cnt3 = 0;           // 0 的个数
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (a[i] > 0)
        {
            Add(1, 1, INF, a[i], 1);
            ++cnt1;
        }
        else if (a[i] < 0)
        {
            ++cnt2;
            sum2 += a[i];
        }
        else
        {
            ++cnt3;
        }
    }
    for (int i = 1; i <= q; ++i)
    {
        int p, x;
        cin >> p >> x;
        if (a[p] > 0)
        {
            Add(1, 1, INF, a[p], -1);
            --cnt1;
        }
        else if (a[p] < 0)
        {
            --cnt2;
            sum2 -= a[p];
        }
        else
        {
            --cnt3;
        }
        a[p] = x;
        if (x > 0)
        {
            Add(1, 1, INF, x, 1);
            ++cnt1;
        }
        else if (x < 0)
        {
            ++cnt2;
            sum2 += x;
        }
        else
        {
            ++cnt3;
        }
        // 开始查询啦
        if (cnt1 == 0)
        {
            cout << "1\n";
        }
        else
        {
            // 正数的第 k 个, 第一次 > -sum2
            long long int k = FirstGT(1, 1, INF, 1, INF, -sum2);
            if (k == 0)
            {
                // 全部 <= sum2, 说明可以增长 0 次
                cout << cnt1 + 1 << "\n";
            }
            else
            {
                // 最小, 第 k 个数字开始到第 cnt1 个数字都是增长的, 最少增长 cnt1 - k + 1 次
                // 最大, cnt1 次增长
                // 一共有 k 种可能性
                cout << k << "\n";
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}