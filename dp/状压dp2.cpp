#include <bits/stdc++.h>
using namespace std;
#define int long long
// 找图上最长的链
// https://codeforces.com/contest/1950/problem/G
string a[20];
string b[20];
vector<int> edges[20];
// 第一维是包含的点,第二维是最后加入的点
bool dp[1 << 20][20];

void dfs(int state, int now)
{
    dp[state][now] = true;
    for (auto y : edges[now])
    {
        // y已经包含在之前的里面了,不能再加入,并且这个状态之前没有出现过
        if (state & (1 << y) || dp[state | (1 << y)][y])
        {
            continue;
        }
        else
        {
            dfs(state | (1 << y), y);
        }
    }
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        scanf("%lld", &n);
        // dp数组初始化
        for (int i = 0; i < (1 << n); i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = false;
            }
        }
        // 初始化
        for (int i = 0; i < n; i++)
        {
            edges[i].clear();
        }

        /// 建图
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            cin >> b[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] == a[j] || b[i] == b[j])
                {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        // 遍历顺序,从每个点开始找最长链
        for (int i = 0; i < n; i++)
        {
            // 当前状态,只包含第一个点,并且最后的点就是这个点
            dp[1 << i][i] = true;
            dfs(1 << i, i);
        }

        int ans = 0;
        for (int i = 0; i < (1 << n); i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i][j])
                {
                    // 最长链就是1最多并且dp是true(合法)的
                    ans = max(ans, __builtin_popcount(i) * 1LL);
                }
            }
        }

        printf("%lld\n", n - ans);
    }
    return 0;
}
