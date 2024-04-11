// 找图上最长的链
// https://codeforces.com/contest/1950/problem/G
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20;
string a[N];
string b[N];
vector<int> edges[N];
bool dp[1 << 16][N];
int n;
void dfs(int state, int now)
{
    dp[state][now] = true;
    for (auto y : edges[now])
    {
        // 下一个位置未在路线中,且没被访问过
        if (((state >> y) & 1) == 0 && dp[state + (1 << y)][y] == 0)
        {
            dfs(state + (1 << y), y);
        }
    }
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        scanf("%lld", &n);
        // 初始化
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            cin >> b[i];

            edges[i - 1].clear();
        }
        for (int i = 0; i < (1 << n); i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = false;
            }
        }
        // 建图
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (a[i] == a[j] || b[i] == b[j])
                {
                    edges[i - 1].push_back(j - 1);
                    edges[j - 1].push_back(i - 1);
                }
            }
        }
        // 正向dp
        for (int i = 0; i < n; i++)
        {
            dp[1 << i][i] = true;
            dfs(1 << i, i);
        }
        // 统计答案
        int ans = 0;
        for (int i = 0; i < (1 << n); i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i][j])
                {
                    ans = max(ans, __builtin_popcount(i) * 1LL);
                }
            }
        }
        printf("%lld\n", n - ans);
    }
    return 0;
}
