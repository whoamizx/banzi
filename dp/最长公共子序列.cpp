// O(nm)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int x[N];
int y[N];
int dp[N][N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &y[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i] == y[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    printf("%d\n", dp[n][n]);
    return 0;
}