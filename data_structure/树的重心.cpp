// 到每个点距离之和最小
// 一个节点底下每个子树的大小最大值最小的点是重心
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, pre[N], dist[N], s[N];
vector<int> edges[N];
inline void dfs(int x) // 求距离
{
    for (auto y : edges[x])
    {
        if (y != pre[x])
        {
            pre[y] = x;
            dist[y] = dist[x] + 1;
            dfs(y);
        }
    }
}
inline void solve(int x) // 求子树大小
{
    s[x] = 1;
    for (auto y : edges[x])
    {
        if (y != pre[x])
        {
            pre[y] = x;
            solve(y);
            s[x] += s[y];
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    memset(pre, 0, sizeof(pre));
    pre[1] = -1;
    solve(1);
    int idx = 0, v = 1 << 30;
    for (int i = 1; i <= n; i++)
    {
        int f = 0;
        for (auto y : edges[i])
        {
            if (y != pre[i])
            {
                f = max(f, s[y]);
            }
            else
            {
                f = max(f, n - s[i]);
            }
        }
        if (f < v)
        {
            v = f;
            idx = i;
        }
    }
    memset(pre, 0, sizeof(pre));
    memset(dist, 0, sizeof(dist));
    pre[idx] = -1;
    dfs(idx);
    long long ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans += dist[i];
    }
    printf("%lld\n", ans);
    return 0;
}