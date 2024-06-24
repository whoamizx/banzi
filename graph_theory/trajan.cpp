#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
// 初始-桥两边连通块的大小,最小是多少
// trajan找桥
// https://codeforces.com/contest/1986/problem/F
vector<int> edge[N];
int tin[N];
int low[N];
bool vis[N];
int siz[N];
int timer = 1;
int ans;
int n;
void dfs(int now, int fa)
{
    siz[now] = 1;
    vis[now] = 1;
    low[now] = timer;
    tin[now] = timer;
    timer++;
    for (auto y : edge[now])
    {
        if (y == fa)
        {
            continue;
        }
        if (vis[y] == 0)
        {
            dfs(y, now);
            siz[now] += siz[y];
            low[now] = min(low[now], low[y]);
            if (low[y] > tin[now])
            {
                ans = max(ans, siz[y] * (n - siz[y]));
            }
        }
        else
        {
            low[now] = min(low[now], low[y]);
        }
    }
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            edge[i].clear();
            tin[i] = 0;
            low[i] = 0;
            vis[i] = 0;
            siz[i] = 0;
        }
        int sum = (n - 1) * n / 2;
        ans = 0;
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            scanf("%lld%lld", &u, &v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        dfs(1, 0);
        printf("%lld\n", sum - ans);
    }
    return 0;
}
