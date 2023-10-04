#include <bits/stdc++.h>
using namespace std;
int a[110][110], b[110][110], c[110][110];
int main()
{
    int n, m, u;
    cin >> m >> n >> u;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= u; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int k = 1; k <= n; k++)
        {
            if (a[i][k])
                for (int j = 1; j <= u; j++)
                {
                    if (b[k][j])
                        c[i][j] += a[i][k] * b[k][j];
                }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= u; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}