#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int f[310][310];
signed main()
{
    cin >> n >> m;
    // 初始化成无穷大
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = LLONG_MAX;
        }
    }
    // 如果f[i][i]初始化成0,就是代表i到i距离定义为0
    // 如果初始化成无穷大,最后会得到走一圈回到i的距离(无向边就是出门就回来)
    // 如果最后f[i][i]<0,则存在负环
    for (int i = 1; i <= n; i++)
    {
        f[i][i] = 0;
        // f[i][i] = LLONG_MAX;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // 重边检查,小的话就不更新
        if (f[u][v] < w)
        {
            continue;
        }
        // 无向边
        f[u][v] = w;
        f[v][u] = w;
    }
    // k是最外层循环
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                // 如果i到k和j到k都有连边//不要忘记写
                if (f[i][k] < LLONG_MAX && f[k][j] < LLONG_MAX)
                    // 滚动数组优化,只用到上一层
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%lld ", f[i][j]);
        }
        printf("\n");
    }
    return 0;
}