// 二维前缀和
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N][N];
long long sum[N][N] = {0};
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
            printf("%lld ", sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}
