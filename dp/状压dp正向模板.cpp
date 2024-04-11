// 特定方式建好图后,找汉密尔顿回路
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 30;
int n = 21;
vector<int> edges[N];
// 第一维,走过哪些点,第二维,最后一个走到的是谁
int dp[1 << 21][N];
template class vector<int>;
signed main()
{
    // 建图
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (__gcd(i, j) == 1)
            {
                edges[i - 1].push_back(j - 1);
                edges[j - 1].push_back(i - 1);
            }
        }
    }
    // 初始化
    dp[1][0] = 1;
    // 二进制遍历
    for (int i = 0; i < (1 << n); i++)
    {
        // 遍历每一位,找为1的点(即已经在路线中的点)
        for (int j = 0; j < n; j++)
        {
            if (((i >> j) & 1) == 1)
            {
                // 从找到的这个点开始,找所有与他联通的,并且不在路线中的点
                // 他的下一个状态的路线数目就可以加上他现在状态的路线数目
                for (auto y : edges[j])
                {
                    if (((i >> y) & 1) == 0)
                    {
                        dp[i + (1 << y)][y] += dp[i][j];
                    }
                }
            }
        }
    }
    // 统计答案
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans += dp[(1 << n) - 1][i];
    }
    printf("%lld\n", ans);
    return 0;
}
