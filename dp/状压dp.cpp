#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20;
// 房间里放着 n 块奶酪。
// 一只小老鼠要把它们都吃掉，问至少要跑多少距离？
// 老鼠一开始在(0,0) 点处。
double a[N];
double b[N];
double dist[N][N];
double dp[1 << N][N];

signed main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf%lf", &a[i], &b[i]);
    }

    a[0] = 0;
    b[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            double temp = sqrt((a[i] - a[j]) * (a[i] - a[j]) + (b[i] - b[j]) * (b[i] - b[j]));
            dist[i][j] = temp;
            dist[j][i] = temp;
        }
    }
    for (int i = 0; i < (1 << n + 1); i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = 1e9 + 10;
        }
    }

    dp[1][0] = 0;
    for (int S = 1; S < (1 << (n + 1)); S++)
    {
        for (int j = 0; j <= n; j++)
        {
            if ((S >> j) & 1)
            {
                for (int k = 0; k <= n; k++)
                {
                    if (S ^ (1 << j) >> k & 1)
                    {
                        dp[S][j] = min(dp[S][j], dp[S ^ (1 << j)][k] + dist[k][j]);
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
    printf("%.2lf", ans);
    return 0;
}
