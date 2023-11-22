/*判断两张简单图是否同构*/
#include <bits/stdc++.h>
using namespace std;
int n, m, ans = 0, a[9][9], b[9][9], c[9];
bool r[9];
inline void dfs(int x)
{
    if (x == n + 1)
    {
        bool ok = true;
        for (int i = 1; i <= n && ok; i++)
        {
            for (int j = i + 1; j <= n && ok; j++)
            {
                if (a[i][j] != b[c[i]][c[j]])
                {
                    ok = false;
                }
            }
        }
        if (ok == true)
        {
            ans++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!r[i])
        {
            c[x] = i;
            r[i] = true;
            dfs(x + 1);
            r[i] = false;
        }
    }
}
int main()
{
    // 输入点和边
    scanf("%d%d", &n, &m);
    // 输入第一张图
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x][y] = a[y][x] = 1;
    }
    // 第二张
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        b[x][y] = b[y][x] = 1;
    }
    dfs(1);
    if (ans >= 1)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}