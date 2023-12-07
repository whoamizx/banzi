#include <bits/stdc++.h>
using namespace std;
// 平面上有n个点(xi,yi)
// 回答q个询问，每个询问给定一个矩形[X1,X2]×[Y1,Y2]
// 询问矩形里面有多少个点。
#define int long long
const int N = 2e5 + 10;
vector<int> vx;
vector<array<int, 4>> event;
int ans[N];
int n, q, m;
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
        for (; x <= n; x += x & (-x))
        {
            c[x] += s;
        }
    }
};
BIT<int> c1;
signed main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%lld%lld", &x, &y);
        vx.push_back(x);
        event.push_back({y, 0, x});
    }
    for (int i = 1; i <= q; i++)
    {
        int x1, y1, x2, y2;
        scanf("%lld%lld%lld%lld", &x1, &x2, &y1, &y2);
        event.push_back({y1 - 1, 2, x1 - 1, i});
        event.push_back({y2, 2, x2, i});
        event.push_back({y2, 1, x1 - 1, i});
        event.push_back({y1 - 1, 1, x2, i});
    }
    sort(event.begin(), event.end());
    // 离散化
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    int m = event.size() + 10;
    c1.resize(m);
    for (auto eva : event)
    {
        // 容斥
        if (eva[1] == 0)
        {
            int temp = lower_bound(vx.begin(), vx.end(), eva[2]) - vx.begin() + 1;
            c1.modify(temp, 1);
        }
        else if (eva[1] == 2)
        {
            // 找到第一个大于的点的前一个
            // 200 300
            // 输入200 201都应该找到200
            // 因为是要小于等于的点
            int temp = upper_bound(vx.begin(), vx.end(), eva[2]) - vx.begin() + 1 - 1;
            ans[eva[3]] += c1.query(temp);
        }
        else
        {
            int temp = upper_bound(vx.begin(), vx.end(), eva[2]) - vx.begin() + 1 - 1;
            ans[eva[3]] -= c1.query(temp);
        }
    }
    // 离线
    for (int i = 1; i <= q; i++)
    {
        printf("%lld\n", ans[i]);
    }
    return 0;
}