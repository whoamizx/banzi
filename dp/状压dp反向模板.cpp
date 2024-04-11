// 特定方式建好图后,找汉密尔顿回路
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 30;
int n = 21;
vector<int> edges[N];
int dp[1 << 21][21];

int dfs(int state, int now)
{
    // 该状态已经访问过,直接返回之前记录的答案
    if (dp[state][now] != -1)
    {
        return dp[state][now];
    }
    // 该状态的路线数目等于(所有可以转移到他的)状态的路线数目之和
    int ans = 0;
    // 从这个状态的终点开始,找所有与他联通的,且在路线中的点
    // 删去终点,然后把终点改成之前终点联通的点,继续dfs
    for (auto y : edges[now])
    {
        if ((state >> y) & 1 && y != 0)
        {
            dp[state - (1 << now)][y] = dfs(state - (1 << now), y);
            ans += dp[state - (1 << now)][y];
        }
    }
    return dp[state][now] = ans;
}
signed main()
{
    // 建图
    for (int i = 1; i <= 21; i++)
    {
        for (int j = i + 1; j <= 21; j++)
        {
            if (__gcd(i, j) == 1)
            {
                edges[i - 1].push_back(j - 1);
                edges[j - 1].push_back(i - 1);
                g[i - 1][j - 1] = 1;
                g[j - 1][i - 1] = 1;
            }
        }
    }
    // 初始化
    memset(dp, -1, sizeof(dp));
    // 手动确定这些状态的路线数目
    for (int i = 1; i < n; i++)
    {
        dp[(1 << i) + 1][i] = 1;
    }
    int ans = 0;
    // 每一个最终状态开始反向状压
    for (int i = 1; i < n; i++)
    {
        dp[(1 << n) - 1][i] = dfs((1 << n) - 1, i);
        ans += dp[(1 << n) - 1][i];
    }
    printf("%lld\n", ans);
    return 0;
}
