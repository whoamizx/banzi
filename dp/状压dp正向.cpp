#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20;
double x[N];
double y[N];
double dist[N][N];
double dp[1 << 16][N];
signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf", &x[i]);
        scanf("%lf", &y[i]);
    }
    // 预处理距离
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dist[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
        }
    }
    // 初始化,把从0开始的初始化好,后面j直接从1开始遍历
    // 如果不初始化,让j从0开始,0可能不是起点
    for (int i = 0; i < (1 << (n + 1)); i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = LLONG_MAX;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[(1 << i) + 1][i] = dist[0][i];
    }
    // 遍历状态
    for (int i = 0; i < (1 << (n + 1)); i++)
    {
        // 遍历点,找到在路线上的点
        for (int j = 1; j <= n; j++)
        {
            if (((i >> j) & 1))
            {
                // 在路线上的点进行延申,扩展到一个不在路线的点
                for (int k = 1; k <= n; k++)
                {
                    if (((i >> k) & 1) == 0)
                    {
                        // 扩展后用之前在的点更新距离
                        dp[i + (1 << k)][k] = min(dp[i + (1 << k)][k], dp[i][j] + dist[j][k]);
                    }
                }
            }
        }
    }
    double ans = 1e9 + 10;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, dp[(1 << (n + 1)) - 1][i]);
    }
    printf("%.2lf\n", ans);
    return 0;
}
