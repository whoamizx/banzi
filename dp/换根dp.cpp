// 给定一个
// n 个点的树，请求出一个结点，使得以这个结点为根时，所有结点的深度之和最大。
// 一个结点的深度之定义为该节点到根的简单路径上边的数量。
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
vector<int> edge[N];
int siz[N];
int dep[N];
int f[N];
int n;
// 预处理
void dfs1(int now, int fa)
{
    siz[now] = 1;
    dep[now] = dep[fa] + 1;
    for (auto y : edge[now])
    {
        if (y == fa)
        {
            continue;
        }
        dfs1(y, now);
        siz[now] += siz[y];
    }
}
// 换根
void dfs2(int now, int fa)
{
    for (auto y : edge[now])
    {
        if (y == fa)
        {
            continue;
        }
        f[y] = f[now] + n - 2 * siz[y];
        dfs2(y, now);
    }
}
signed main()
{
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        scanf("%lld%lld", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs1(1, 0);
    for (int i = 1; i <= n; i++)
    {
        f[1] += dep[i];
    }
    dfs2(1, 0);
    int ans = 0;
    int id;
    for (int i = 1; i <= n; i++)
    {
        if (f[i] > ans)
        {
            ans = f[i];
            id = i;
        }
    }
    printf("%lld\n", id);
    return 0;
}