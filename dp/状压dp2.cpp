#include <bits/stdc++.h>
using namespace std;
#define int long long
// 找图上最长的链
string a[20];
string b[20];
vector<int> edges[20];
bool dp[1 << 20][20];

void dfs(int state, int now)
{
    dp[state][now] = true;
    for (auto y : edges[now])
    {
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

        for (int i = 0; i < (1 << n); i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = false;
            }
        }
        for (int i = 0; i < n; i++)
        {
            edges[i].clear();
        }

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
        for (int i = 0; i < n; i++)
        {
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
                    ans = max(ans, __builtin_popcount(i) * 1LL);
                }
            }
        }
        printf("%lld\n", n - ans);
    }
    return 0;
}
