#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[310][310];
int main()
{
    cin >> n >> m;
    memset(f, 127, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        f[i][i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        f[u][v] = w;
        f[v][u] = w;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (f[i][k] < 1 << 30 && f[k][j] < 1 << 30)
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", f[i][j]);
        }
        printf("\n");
    }
    return 0;
}