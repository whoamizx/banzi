#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

int main()
{

    int t;
    cin >> t;
    auto start = system_clock::now();
    while (t--)
    {
        int a[110];
        bool vis[110] = {0};
        vector<int> b;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + 1 + n);
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            long long dp[25010] = {0};
            b.clear();
            for (int j = i - 1; j >= 1; j--)
            {
                if (!vis[j])
                    b.push_back(a[j]);
            }
            for (int x = 0; x < b.size(); x++)
            {
                for (int y = b[x]; y <= a[i]; y++)
                {
                    dp[y] = max(dp[y - b[x]] + b[x], dp[y]);
                }
            }
            if (dp[a[i]] == a[i])
            {
                cnt++;
                vis[i] = 1;
            }
        }
        printf("%d\n", n - cnt);
    }
    auto end = system_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << (double)(duration.count()) * microseconds::period::num / microseconds::period::den << endl;
    return 0;
}
